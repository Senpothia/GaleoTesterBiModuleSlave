/*
 * File:   tester.c
 * Author: Michel
 *
 * Created on 31 août 2023, 15:28
 */


#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "I2C_LCD.h"
#include "tester.h"
#include "display.h"
#include <stdio.h>
#include <string.h>

void alimenter(bool active) {

    if (active) {

        REL1_SetHigh();
    } else {
        REL1_SetLow();
    }
}

void pressBP1(bool active) {

    if (active) {

        REL2_SetHigh();
    } else {
        REL2_SetLow();
    }
}

void pressBP2(bool active) {

    if (active) {

        REL3_SetHigh();
    } else {
        REL3_SetLow();
    }
}

void setHorloge(bool active) {

    if (active) {

        REL4_SetHigh();
    } else {
        REL4_SetLow();
    }

}

bool testR1(bool active) {

    bool result = false;
    if (active) {

        if (IN1_GetValue() == 1 && IN2_GetValue() == 0) {

            result = true;
        }
    }

    if (!active) {

        if (IN1_GetValue() == 0 && IN2_GetValue() == 1) {


            result = true;
        }
    }

    return result;
}

bool testR2(bool active) {

    bool result = false;
    if (active) {

        if (IN4_GetValue() == 1 && IN5_GetValue() == 0) {

            result = true;
        }
    }

    if (!active) {

        if (IN4_GetValue() == 0 && IN5_GetValue() == 1) {

            result = true;
        }
    }

    return result;
}

bool testR3(bool active) {


    bool result = false;
    if (active) {

        if (IN6_GetValue() == 1 && IN7_GetValue() == 0) {

            result = true;
        }
    }

    if (!active) {

        if (IN6_GetValue() == 0 && IN7_GetValue() == 1) {

            result = true;
        }
    }

    return result;
}

bool testOK(bool active) {

    bool result = false;
    if (active) {

        if (IN3_GetValue() == 0) {

            result = true;
        }
    }

    if (!active) {

        if (IN3_GetValue() == 1) {

            result = true;
        }
    }

    return result;

}

bool testNOK(bool active) {

    bool result = false;
    if (active) {

        if (IN8_GetValue() == 0) {

            result = true;
        }
    }

    if (!active) {

        if (IN8_GetValue() == 1) {

            result = true;
        }
    }

    return result;
}

bool controlVisuel() {

    bool result = false;


    if (IN3_GetValue() == 0) {

        result = true;
    }

    if (IN3_GetValue() == 1) {

        result = false;

    }

}

void ledNonConforme(bool active) {

    if (active) {

        C3_SetHigh();
    } else {
        C3_SetLow();
    }
}

void ledConforme(bool active) {

    if (active) {

        C4_SetHigh();
    } else {
        C4_SetLow();
    }
}

void ledProgession(bool active) {

    if (active) {

        C2_SetHigh();

    } else {

        C2_SetLow();
    }
}


void alerteDefaut(char etape[], bool *testAct, bool *testVoy) {

    char error[20] = "-> ERREUR: ";
    char eol[10] = "\r\n";
    ledNonConforme(true);
    ledProgession(true);
    ledConforme(false);
    alimenter(false);
    displayManager(etape, NON_CONFORME, ACQ, LIGNE_VIDE);
    printf(strcat(strcat(error, etape), eol));
    errorAlert();

    while (IN3_GetValue() == 0) {
        ;
    }

    // ledNonConforme(false);
    *testAct = false;
    *testVoy = false;

}

bool reponseOperateur(bool automatique) {

    bool reponse = false;
    bool repOperateur = false;
    unsigned char reception;

    if (automatique) {

        while (!repOperateur) {

            if (0) {



                switch (reception) // check command  
                {


                    case '0':
                    {
                        RESET();

                    }

                    case '2':
                    {

                        __delay_ms(50);
                        reponse = true;
                        repOperateur = true;
                        break;
                    }

                    case '3':
                    {

                        __delay_ms(50);
                        reponse = false;
                        repOperateur = true;
                        break;
                    }

                       
                    case '9': // fin de programmation
                    {

                        __delay_ms(50);
                        reponse = true;
                        repOperateur = true;
                        REL8_SetLow();
                        break;
                    }
                }

            }

        }

    }

    if (!automatique) {

        while (!repOperateur) {

            if (testNOK(true)) {
                reponse = false;
                repOperateur = true;
            }
            if (testOK(true)) {
                reponse = true;
                repOperateur = true;
            }
        }

    }

    return reponse;

}

void setP1(bool active) {

    if (active) {

        REL5_SetHigh();
    } else {
        REL5_SetLow();
    }

}

void setP2(bool active) {

    if (active) {

        REL6_SetHigh();
    } else {
        REL6_SetLow();
    }

}

void initialConditions(bool *testAct, bool *testVoy, bool *autom, bool *prog) {

   
    *testAct = false;
    *testVoy = false;
    *autom = false;
    *prog = true;
    ledConforme(false);
    ledNonConforme(false);
    ledProgession(false);
    alimenter(false);
    pressBP1(false);
    pressBP2(false);
    setP1(false);
    setP2(false);
    REL8_SetLow();

}

void activerBuzzer() {


    for (int i = 0; i < 50; i++) {

        BUZ_SetHigh();
        // __delay_ms(1);
        __delay_us(1000);

        BUZ_SetLow();
        // __delay_ms(1);
        __delay_us(1000);

    }

}

void activerTouche(void) {

    REL7_SetHigh();
    __delay_ms(250);
    REL7_SetLow();
    __delay_ms(250);

}

void startAlert(void) {

    for (int i = 0; i < 2; i++) {

        activerBuzzer();
        __delay_ms(80);

    }

}

void errorAlert(void) {

    for (int j = 0; j < 4; j++) {

        for (int i = 0; i < 4; i++) {

            activerBuzzer();
            __delay_ms(1000);

        }
        __delay_ms(500);
    }


}

void okAlert(void) {

    for (int i = 0; i < 2; i++) {

        startAlert();

    }


}



void attenteDemarrageSlave(bool *autom, bool *testAct, bool *prog, char *order) {

   
    bool repOperateur = false;

    while (!repOperateur) {


        if (IN3_GetValue() == 0) {

            // if(master){printf("-> TEST MANUEL EN COURS\r\n");}
            repOperateur = true;
            *autom = false;
            *prog = false;
            *testAct = true;
        }

        if (*order == 'a') {

            repOperateur = true;
            *autom = true;
            *prog = false;
            *testAct = true;

        }


    }

}

void attenteAquittement(bool *autom, bool *testAct) {

    unsigned char reception;
    bool repOperateur = false;

    while (!repOperateur) {


        if (IN3_GetValue() == 0) {

            repOperateur = true;
            *autom = false;
            *testAct = false;
        }

        if (0) {



            switch (reception) // check command  
            {

                case '0':
                {
                    RESET();

                }

                case '4':
                {
                   
                    *autom = false;
                    *testAct = false;
                    __delay_ms(50);
                    repOperateur = true;
                    break;
                }
            }
        }
    }

}

void sortieErreur(bool *autom, bool *testAct, bool *testVoy, bool *prog) {

    attenteAquittement(*autom, *testAct);
    initialConditions(*testAct, *testVoy, *autom, *prog);
    __delay_ms(2000);

}

void alerteDefautEtape16(char etape[], bool *testAct, bool *testVoy, bool *autom, bool *prog) {

    char error[20] = "-> ERREUR: ";
    char eol[10] = "\r\n";
    ledNonConforme(true);
    ledProgession(true);
    ledConforme(false);
    //alimenter(false);
    displayManager(etape, NON_CONFORME, "VERIFIER P1 ET P2", "PRESSER OK OU ERREUR");
    printf(strcat(strcat(error, etape), eol));
    errorAlert();

    bool reponse = reponseOperateur(*autom);
    __delay_ms(500);
    if (reponse) {

        // ledNonConforme(false);
        *testAct = false;
        *testVoy = false;
        //alerteDefaut("ETAPE 16 CONFIRMEE", &testAct, &testVoy);
        displayManager("ETAPE 16", "NON CONFORME", "RESULTAT CONFIRME", ACQ);
        sortieErreur(&autom, &testAct, &testVoy, &prog);

    } else {

        displayManager("ETAPE 16", "TEST P1", LIGNE_VIDE, LIGNE_VIDE);
        ledNonConforme(false);
        ledProgession(true);
        ledConforme(false);
        setP1(true);
        __delay_ms(1200);
        setP1(false);
        __delay_ms(1000);
        if (testR1(true) && testR2(true) && testR3(true)) {

            displayManager("ETAPE 16", "TEST P1", "ERREUR VALIDEE", "TEST OK");

        } else {

            *testAct = false;
            alerteDefaut("ETAPE 16", &testAct, &testVoy);
            sortieErreur(&autom, &testAct, &testVoy, &prog);
        }

    }


}

void marchePAP() {

    bool repOperateur = false;
   
    while (!repOperateur) {


        if (IN3_GetValue() == 0) {

            repOperateur = true;
        }
    }
}


