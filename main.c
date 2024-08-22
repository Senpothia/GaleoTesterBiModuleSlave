/**
 TEST CARTE D925ED4 - BOX GALEO BLTH
 * 
 * Septembre 2023
 * 
 * Michel LOPEZ
 * 
 */

/*
 Equipement: automate v1.0
 * PIC16LF1939
 * 
 * Relais:
 * 
 * R1: alimentation
 * R2: BP1
 * R3: BP2
 * R4: Horloge
 * R5: Cavalier P1
 * R6: Cavalier P2
 * R7: Touche clavier - "Doigt"
 * R8: Commutation alimentation programmateur STM32
 * 
 * Entrées:
 * 
 * J13/(IN1 dans le code): NC1
 * J15/IN2: NO1
 * J16/IN4: NC2
 * J17/IN5: NO2
 * J19/IN6: NC3
 * J18/IN7: NO30
 * J14/IN3: Bouton de validation OK 
 * J20/IN8: Bouton de confirmation NOK
 * J21/AN1: test éclairage clavier par mesure analogique
 * 
 * J26(serigraphie OV)/GPIO1: inhibition test des leds - starp au OV = tests des leds inhibé
 * J26(serigraphie OV)/GPIO4: sélection maître/esclave - starp au OV = esclave
 * 
 * Sorties:
 * J25.1/C2: led rouge (indication non conforme)
 * J25.2/C4: led verte (indication conforme)
 * J25.3/C2: led jaune (indication test en cours)
 
 * 
 * Mode d'emploi:
 * 
 * Pour configuration en mode maitre/esclave
 * affecter les bonnes adresses i2c des afficheurs et recompiler si besoin.
 * 
 * 1- Sélectionner mode de test des leds (strap = inhibition)
 * 2- Appuyer sur OK, pour lancer la séquence
 * 3- Appuyer sur OK pour valider / sur NOK pour invalider
 * 4- En fin de séquence le résultat est donné par la led verte ou rouge
 * 5- Acquiter le résultat en appuyant sur OK
 * 
 * 
 */

#include "mcc_generated_files/mcc.h"
#include "I2C_LCD.h"
#include "tester.h"
#include "display.h"
#include "I2C_tester.h"
#include <stdlib.h>
#include "mcc_generated_files/i2c_master.h"
#include "I2C-tester.h"

/*
                         Main application
 */

char ordre;
char slaveSummary = 'z';

void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();


    bool testActif = false;
    bool testVoyants = false;
    int lectureAN1;
    char slectureAN1[5];
    bool testLeds = true;
    bool automatique = false;
    bool pap = false;
    bool programmation = true;
    bool master = true;
    char slaveStatus;



    // Détermination mode de fonctionnement: master/slave
    // Affichage message d'accueil

    if (GPIO4_GetValue() == 0) {

        // Entrée IO4 à 0V: mode esclave activé
        master = false;
        I2C_Slave_Init();


    } else {

        // Entrée IO4 à 5V: mode maitre activé
        I2C_Master_Init();

    }

    if (GPIO1_GetValue() == 1) {

        testLeds = true;

    } else {

        testLeds = false;

    }

    if (GPIO2_GetValue() == 0) {

        pap = true;

    } else {

        pap = false;
    }

    /*
    if (master) {
        REL8_SetLow(); // Pour test  - Coupure alimentation du programmateur STM32
    } else {
        REL8_SetHigh();
    }
     */


    __delay_ms(1000);


    while (1) {


        if (master) {

            LCD_Init(0x4E);
            displayManager(TITRE, MODE_MASTER, BOARD_REQUEST, OK_REQUEST);
            __delay_ms(100);

            LCD_Init(0x46);
            displayManager(TITRE, MODE_SLAVE, BOARD_REQUEST, OK_REQUEST);
            __delay_ms(100);

        }


        // sélection test individuel des leds
        // le test est inhibé si l'entrée GPIO1 est à zéro



        // Attente de démarrage


        while (!testActif) {

            attenteDemarrageSlave(&automatique, &testActif, &programmation, &ordre);
        }


        programmation = false;
        startAlert();
        testActif = true;
        ledConforme(false);
        ledNonConforme(false);
        ledProgession(true);


        // test I2C vers esclave

        __delay_ms(100);


        if (master) {
            displayManager("ETAPE 1", "TEST 3 RELAIS ON", LIGNE_VIDE, LIGNE_VIDE);
        } else {
            __delay_ms(100);
        }


        pressBP1(true);
        pressBP2(true);
        __delay_ms(1000);
        alimenter(true);
        __delay_ms(2000); // 2000 pour D925ED4; 10000 pour D850



        if (testR1(true) && testR2(true) && testR3(true)) {



            slaveSummary = 'A';



        } else {

            testActif = false;
            pressBP1(false);
            pressBP2(false);
            alerteDefaut("ETAPE 1", &testActif, &testVoyants);
            sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
            slaveSummary = 'a';


        }

        __delay_ms(1000);


        pressBP1(false);
        pressBP2(false);

        // ETAPE 2



        if (testActif) {

            if (master) {
                displayManager("ETAPE 2", "TEST 3 RELAIS OFF", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }

            pressBP1(false);
            pressBP2(false);
            __delay_ms(500);
            if (!testR1(true) && !testR2(true) && !testR3(true)) {



                slaveSummary = 'B';




            } else {

                testActif = false;
                alerteDefaut("ETAPE 2", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'b';


            }
        }

        // ETAPE 3



        if (testActif) {

            if (master) {
                displayManager("ETAPE 3", "TEST LED ROUGE", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }

            pressBP1(true);
            __delay_ms(250);
            pressBP1(false);
            if (testLeds) {


                printf("Attente validation led rouge\r\n");

                testVoyants = reponseOperateur2(automatique, &ordre);
                if (!testVoyants) {

                    testActif = false;
                    alerteDefaut("ETAPE 3", &testActif, &testVoyants);
                    sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                    slaveSummary = 'c';


                } else {


                    slaveSummary = 'C';

                }
            }


        }

        // ETAPE 4



        if (testActif) {

            if (master) {
                displayManager("ETAPE 4", "TEST LED BLEUE", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }

            pressBP1(true);
            __delay_ms(250);
            pressBP1(false);
            if (testLeds) {

                testVoyants = reponseOperateur2(automatique, &ordre);
                if (!testVoyants) {

                    testActif = false;
                    alerteDefaut("ETAPE 4", &testActif, &testVoyants);
                    sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                    slaveSummary = 'd';


                } else {



                    slaveSummary = 'D';


                }
            }


        }

        // ETAPE 5



        if (testActif) {

            if (master) {
                displayManager("ETAPE 5", "TEST LED VERTE", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }

            pressBP1(true);
            __delay_ms(250);
            pressBP1(false);
            if (testLeds) {

                testVoyants = reponseOperateur2(automatique, &ordre);
                if (!testVoyants) {

                    testActif = false;
                    alerteDefaut("ETAPE 5", &testActif, &testVoyants);
                    sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                    slaveSummary = 'e';


                } else {

                    slaveSummary = 'E';


                }
            }

        }



        // ETAPE 6



        if (testActif) {

            if (master) {
                displayManager("ETAPE 6", "TEST R1 ON", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            pressBP1(true);
            __delay_ms(1000);
            pressBP1(false);

            __delay_ms(1000);

            if (testR1(true)) {

                slaveSummary = 'F';


            } else {

                testActif = false;
                alerteDefaut("ETAPE 6", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'f';


            }

        }

        // ETAPE 7



        if (testActif) {

            if (master) {
                displayManager("ETAPE 7", "TEST R1 OFF - R2 ON", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            pressBP1(true);
            __delay_ms(1000);
            pressBP1(false);

            __delay_ms(1000);

            if (testR1(false) && testR2(true)) {

                slaveSummary = 'G';

            } else {

                testActif = false;
                alerteDefaut("ETAPE 7", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'g';

            }

        }

        // ETAPE 8


        if (testActif) {

            if (master) {
                displayManager("ETAPE 8", "TEST R2 OFF - R3 ON", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            pressBP1(true);
            __delay_ms(1000);
            pressBP1(false);

            __delay_ms(1000);

            if (testR2(false) && testR3(true)) {

                slaveSummary = 'I';


            } else {

                testActif = false;
                alerteDefaut("ETAPE 8", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'i';

            }

        }

        // ETAPE 9


        if (testActif) {

            if (master) {
                displayManager("ETAPE 9", "TEST LED CLAVIER", "CLAVIER ECLAIRE?", LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            pressBP1(true);
            __delay_ms(250);
            pressBP1(false);
            __delay_ms(500);
            // Lecture analogique
            // Led on: Van = 433
            // Led off: Van = 587

            lectureAN1 = ADC_GetConversion(VIN1);
            int buffer = sprintf(slectureAN1, "%d", lectureAN1);
            if (lectureAN1 < LIM_H) {

                slaveSummary = 'J';


            } else {

                alerteDefaut("ETAPE 9", &testActif, &testVoyants);
                if (master) {
                    displayManager("ETAPE 9", "TEST LED CLAVIER", slectureAN1, LIGNE_VIDE);
                } else {
                    __delay_ms(100);
                }// Ligne de test: affichage valeur de mesure analogique
                REL8_SetLow();
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'j';

            }

            __delay_ms(2000);

        }

        // ETAPE 10



        if (testActif) {

            if (master) {
                displayManager("ETAPE 10", "TEST LED CLAVIER", "CLAVIER ETEINT?", LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            pressBP1(true);
            __delay_ms(250);
            pressBP1(false);

            // Lecture analogique
            // Led on: Van = 433
            // Led off: Van = 587
            __delay_ms(500);
            lectureAN1 = ADC_GetConversion(VIN1);
            int buffer = sprintf(slectureAN1, "%d", lectureAN1);

            if (lectureAN1 < LIM_L) {

                slaveSummary = 'K';

            } else {

                alerteDefaut("ETAPE 10", &testActif, &testVoyants);
                if (master) {
                    displayManager("ETAPE 10", "TEST LED CLAVIER", slectureAN1, LIGNE_VIDE);
                } else {
                    __delay_ms(100);
                } // Ligne de test: affichage valeur de mesure analogique
                REL8_SetHigh();
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'k';

            }
            __delay_ms(2000);

        }


        // ETAPE 12



        if (testActif) {

            if (master) {
                displayManager("ETAPE 12", "TEST SFLASH", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            __delay_ms(500);
            pressBP1(true);
            __delay_ms(250);
            pressBP1(false);

            __delay_ms(3000);

            pressBP1(true);
            __delay_ms(250);
            pressBP1(false);
            __delay_ms(750);

            if (testR1(true) && testR2(true) && testR3(false)) {

                slaveSummary = 'L';

            } else {

                testActif = false;
                pressBP1(false);
                pressBP2(false);
                alerteDefaut("ETAPE 12", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'l';

            }

            __delay_ms(1000);

            pressBP1(false);
            pressBP2(false);

        }

        // ETAPE 13



        if (testActif) {

            if (master) {
                displayManager("ETAPE 13", "TEST LEDS CARTE", "LEDS ALLUMEES", "PRESSER OK / NOK");
            } else {
                __delay_ms(100);
            }
            pressBP1(true);
            __delay_ms(250);
            pressBP1(false);


            printf("ATTENTE VALIDATION LEDS\r\n");

            testVoyants = reponseOperateur2(automatique, &ordre);
            if (!testVoyants) {

                testActif = false;
                alerteDefaut("ETAPE 13", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'm';


            } else {

                slaveSummary = 'M';


            }
        }

        // ETAPE 14


        if (testActif) {

            if (master) {
                displayManager("ETAPE 14", "TEST BP2", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            pressBP2(true);
            __delay_ms(250);
            pressBP2(false);
            __delay_ms(500);

            if (testR1(true) && testR2(true) && testR3(true)) {

                slaveSummary = 'N';

            } else {

                testActif = false;
                alerteDefaut("ETAPE 14", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'n';

            }

        }

        // ETAPE 15

        if (testActif) {

            if (master) {
                displayManager("ETAPE 15", "TEST HORLOGE", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            setHorloge(true);
            __delay_ms(250);
            setHorloge(false);
            __delay_ms(500);

            if (testR1(false) && testR2(false) && testR3(false)) {

                slaveSummary = 'O';


            } else {

                testActif = false;
                alerteDefaut("ETAPE 15", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'o';

            }

        }

        // ETAPE 16


        if (testActif) {

            if (master) {
                displayManager("ETAPE 16", "TEST P1", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            setP1(true);
            __delay_ms(1200); // 1200 pour D925ED2

            setP1(false);
            __delay_ms(500);
            if (testR1(true) && testR2(true) && testR3(true)) {

                slaveSummary = 'P';

            } else {

                alerteDefautEtape16("ETAPE 16", &testActif, &testVoyants, &automatique, &programmation, &ordre);
                slaveSummary = 'p';


            }

        }

        // ETAPE 17



        if (testActif) {

            if (master) {
                displayManager("ETAPE 17", "TEST P2", LIGNE_VIDE, LIGNE_VIDE);
            } else {
                __delay_ms(100);
            }
            setP2(true);
            __delay_ms(1200);
            setP2(false);
            __delay_ms(500);

            if (testR1(false) && testR2(false) && testR3(false)) {

                slaveSummary = 'Q';


            } else {

                testActif = false;
                alerteDefaut("ETAPE 17", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'q';

            }

        }


        // ETAPE 18



        if (testActif) {

            if (master) {
                displayManager("ETAPE 18", "TEST BLUETOOTH", "VOIR APPLI", "PRESSER OK / NOK");
            } else {
                __delay_ms(100);
            }
            activerTouche();
            //printf("ATTENTE VALIDATION BLUETOOTH\r\n");
            testVoyants = reponseOperateur2(automatique, &ordre);
            if (!testVoyants) {

                testActif = false;
                alerteDefaut("ETAPE 18", &testActif, &testVoyants);
                sortieErreur(&automatique, &testActif, &testVoyants, &programmation);
                slaveSummary = 'r';

                //initialConditions(&testActif, &testVoyants, &automatique);
                __delay_ms(2000);
            } else {

                slaveSummary = 'R';


            }
        }


        // ETAPE: SORTIE

        if (testActif) {

            if (master) {
                displayManager("FIN DE TEST", "CONFORME", "RETIRER CARTE", ACQ);
            } else {
                __delay_ms(100);
            }
            ledConforme(true);
            alimenter(false);
            okAlert();
            slaveSummary = 'S';
            attenteAquittement2(&automatique, &testActif, ordre);
            initialConditions(&testActif, &testVoyants, &automatique, &programmation);
            slaveSummary = 'z';

            __delay_ms(2000);

        }

    } // fin boucle infinie



} // fin fonction main

/**
 End of File
 */


void __interrupt() I2C_Slave_Read_Write() {


    // entrée en interruption


    if (SSPIF) {

        SSPIF = 0;

        //-------------------------------------------------------------------------------
        // Gestion des collisions
        if (SSPOV || WCOL) {
            SSPOV = 0; // Clear the overflow flag
            WCOL = 0; // Clear the collision flag
            return;
        }

        //-------------------------------------------------------------------------------
        // Adresse + écriture (R/W=0)
        if (!D_nA && !R_nW) // If last byte was an address + Write
        {

            unsigned char temp = SSPBUF; // Read the buffer to clear BF
            CKP = 1; // Release the clock
            //-------------------------------------------------------------------------------


        } else if (!D_nA && R_nW) // If last byte was an address + Read
        {

            // adresse + lecture (R/W=1)
            // Gestion acquittement des ordres reçus du maitre
            // Accusés réception aux ordres du maitre
            unsigned char temp = SSPBUF; // Read the buffer to clear BF

            if (ordre == 'a') {

                SSPBUF = 'a'; // Load the buffer with the data to be sent
              
            }

            if (ordre == '?') {

                SSPBUF = slaveSummary; // Load the buffer with the data to be sent
              

            }

            if (ordre == 'u') {

                SSPBUF = 'u'; // Load the buffer with the data to be sent
               
            }


            if (ordre == 'v') {

                SSPBUF = 'v'; // Load the buffer with the data to be sent
               
            }

            if (ordre == 'w') {

                SSPBUF = 'w'; // Load the buffer with the data to be sent
                
            }

            CKP = 1; // Release the clock
           

            //-------------------------------------------------------------------------------
            // Donnée + écriture R/W=0
            // Identification des ordres en provenance du maitre

        } else if (D_nA && !R_nW) // If data byte + Write
        {

            unsigned char temp = SSPBUF; // Read the buffer to clear BF

            CKP = 1; // Release the clock


            // Réception ordre d'interrogation status

            if (temp == '?') {

                ordre = '?';

            }

            // Réception ordre de démarrage

            if (temp == 'a') {

                ordre = 'a';

            }

            // Réception ordre OK
            if (temp == 'u') {

                ordre = 'u';

            }

            // Réception ordre KO
            if (temp == 'v') {

                ordre = 'v';

            }

            // Réception ordre ACQ
            if (temp == 'w') {

                ordre = 'w';

            }

            //-------------------------------------------------------------------------------
            // Donnée + ecriture R/W=1
            // Traitement des ordres 
            // --- NON UTILISEE --------

        } else if (D_nA && R_nW) // If data byte + lecture
        {

            unsigned char temp = SSPBUF; // Read the buffer to clear BF
            //SSPBUF = 0x55; // Load the buffer with the data to be sent2222
            CKP = 1; // Release the clock
            if (temp == 88) {

                SSPBUF = 0x22; // Load the buffer with the data to be sent
                //CKP = 1; // Release the clock
            }

            if (temp == 77) {

                SSPBUF = 0x99; // Load the buffer with the data to be sent
                //CKP = 1; // Release the clock
            }

            if (temp == 25) {

                //SSPBUF = 0x55; // Load the buffer with the data to be sent
                //CKP = 1; // Release the clock
            }


        }
    }
}
