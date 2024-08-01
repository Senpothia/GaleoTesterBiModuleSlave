
#include <xc.h>
#include "I2C-tester.h"

char getSlaveStatus(char code) {

    char slaveResponse;

    SSPCON2bits.SEN = 1; // Génération START
    while (SSPCON2bits.SEN); // Attente fin de START
    SSPBUF = SLAVE_ADD; // Adresse du périphérique en mode écriture 
    while (SSPSTATbits.BF); // Attente fin de transmission
    while (SSPSTATbits.R_nW); // Attente ACK
    SSPBUF = code; // Adresse du périphérique en mode écriture 
    while (SSPSTATbits.BF); // Attente fin de transmission
    while (SSPSTATbits.R_nW); // Attente ACK
    SSPCON2bits.RSEN = 1; // Génération RESTART
    while (SSPCON2bits.RSEN); // Attente fin de RESTART
    SSPBUF = SLAVE_ADD + 1; // Adresse du périphérique en mode lecture
    while (SSPSTATbits.BF); // Attente fin de transmission
    while (SSPSTATbits.R_nW); // Attente ACK
    SSPCON2bits.RCEN = 1; // Maitre en mode de réception
    while (!SSPSTATbits.BF); // Attente fin de réception
    slaveResponse = SSPBUF; // sauvegarde réception
    SSPCON2bits.ACKDT = 1; // Configuration génération NACK
    SSPCON2bits.ACKEN = 1; // Génération NACK
    while (SSPCON2bits.ACKEN); // Attente fin génération NACK
    SSPCON2bits.PEN = 1; //Génération STOP
    while (SSPCON2bits.PEN); //Attente fin de STOP

    return slaveResponse;

}

void writeSlave(char code) {

    SSPCON2bits.SEN = 1; // Génération START
    while (SSPCON2bits.SEN); // Attente fin de START
    SSPBUF = SLAVE_ADD; // Adresse du périphérique en mode écriture 
    while (SSPSTATbits.BF); // Attente fin de transmission
    while (SSPSTATbits.R_nW); // Attente ACK
    SSPBUF = code;
    while (SSPSTATbits.BF); // Attente fin de transmission
    while (SSPSTATbits.R_nW); // Attente ACK
    SSPCON2bits.PEN = 1; //Génération STOP
    while (SSPCON2bits.PEN); //Attente fin de STOP

}
