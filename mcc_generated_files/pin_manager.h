/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF1939
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set REL1 aliases
#define REL1_TRIS                 TRISAbits.TRISA0
#define REL1_LAT                  LATAbits.LATA0
#define REL1_PORT                 PORTAbits.RA0
#define REL1_ANS                  ANSELAbits.ANSA0
#define REL1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define REL1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define REL1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define REL1_GetValue()           PORTAbits.RA0
#define REL1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define REL1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define REL1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define REL1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set REL2 aliases
#define REL2_TRIS                 TRISAbits.TRISA1
#define REL2_LAT                  LATAbits.LATA1
#define REL2_PORT                 PORTAbits.RA1
#define REL2_ANS                  ANSELAbits.ANSA1
#define REL2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define REL2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define REL2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define REL2_GetValue()           PORTAbits.RA1
#define REL2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define REL2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define REL2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define REL2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set REL3 aliases
#define REL3_TRIS                 TRISAbits.TRISA2
#define REL3_LAT                  LATAbits.LATA2
#define REL3_PORT                 PORTAbits.RA2
#define REL3_ANS                  ANSELAbits.ANSA2
#define REL3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define REL3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define REL3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define REL3_GetValue()           PORTAbits.RA2
#define REL3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define REL3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define REL3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define REL3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set REL4 aliases
#define REL4_TRIS                 TRISAbits.TRISA3
#define REL4_LAT                  LATAbits.LATA3
#define REL4_PORT                 PORTAbits.RA3
#define REL4_ANS                  ANSELAbits.ANSA3
#define REL4_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define REL4_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define REL4_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define REL4_GetValue()           PORTAbits.RA3
#define REL4_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define REL4_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define REL4_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define REL4_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set REL5 aliases
#define REL5_TRIS                 TRISAbits.TRISA4
#define REL5_LAT                  LATAbits.LATA4
#define REL5_PORT                 PORTAbits.RA4
#define REL5_ANS                  ANSELAbits.ANSA4
#define REL5_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define REL5_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define REL5_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define REL5_GetValue()           PORTAbits.RA4
#define REL5_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define REL5_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define REL5_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define REL5_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set REL6 aliases
#define REL6_TRIS                 TRISAbits.TRISA5
#define REL6_LAT                  LATAbits.LATA5
#define REL6_PORT                 PORTAbits.RA5
#define REL6_ANS                  ANSELAbits.ANSA5
#define REL6_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define REL6_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define REL6_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define REL6_GetValue()           PORTAbits.RA5
#define REL6_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define REL6_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define REL6_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define REL6_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set REL7 aliases
#define REL7_TRIS                 TRISAbits.TRISA6
#define REL7_LAT                  LATAbits.LATA6
#define REL7_PORT                 PORTAbits.RA6
#define REL7_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define REL7_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define REL7_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define REL7_GetValue()           PORTAbits.RA6
#define REL7_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define REL7_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set REL8 aliases
#define REL8_TRIS                 TRISAbits.TRISA7
#define REL8_LAT                  LATAbits.LATA7
#define REL8_PORT                 PORTAbits.RA7
#define REL8_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define REL8_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define REL8_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define REL8_GetValue()           PORTAbits.RA7
#define REL8_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define REL8_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set VIN1 aliases
#define VIN1_TRIS                 TRISBbits.TRISB0
#define VIN1_LAT                  LATBbits.LATB0
#define VIN1_PORT                 PORTBbits.RB0
#define VIN1_WPU                  WPUBbits.WPUB0
#define VIN1_ANS                  ANSELBbits.ANSB0
#define VIN1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define VIN1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define VIN1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define VIN1_GetValue()           PORTBbits.RB0
#define VIN1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define VIN1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define VIN1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define VIN1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define VIN1_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define VIN1_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set AN2 aliases
#define AN2_TRIS                 TRISBbits.TRISB1
#define AN2_LAT                  LATBbits.LATB1
#define AN2_PORT                 PORTBbits.RB1
#define AN2_WPU                  WPUBbits.WPUB1
#define AN2_ANS                  ANSELBbits.ANSB1
#define AN2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define AN2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define AN2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define AN2_GetValue()           PORTBbits.RB1
#define AN2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define AN2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define AN2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define AN2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define AN2_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define AN2_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set AN3 aliases
#define AN3_TRIS                 TRISBbits.TRISB2
#define AN3_LAT                  LATBbits.LATB2
#define AN3_PORT                 PORTBbits.RB2
#define AN3_WPU                  WPUBbits.WPUB2
#define AN3_ANS                  ANSELBbits.ANSB2
#define AN3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define AN3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define AN3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define AN3_GetValue()           PORTBbits.RB2
#define AN3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define AN3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define AN3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define AN3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define AN3_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define AN3_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set AN4 aliases
#define AN4_TRIS                 TRISBbits.TRISB3
#define AN4_LAT                  LATBbits.LATB3
#define AN4_PORT                 PORTBbits.RB3
#define AN4_WPU                  WPUBbits.WPUB3
#define AN4_ANS                  ANSELBbits.ANSB3
#define AN4_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define AN4_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define AN4_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define AN4_GetValue()           PORTBbits.RB3
#define AN4_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define AN4_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define AN4_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define AN4_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define AN4_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define AN4_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set BUZ aliases
#define BUZ_TRIS                 TRISBbits.TRISB4
#define BUZ_LAT                  LATBbits.LATB4
#define BUZ_PORT                 PORTBbits.RB4
#define BUZ_WPU                  WPUBbits.WPUB4
#define BUZ_ANS                  ANSELBbits.ANSB4
#define BUZ_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define BUZ_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define BUZ_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define BUZ_GetValue()           PORTBbits.RB4
#define BUZ_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define BUZ_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define BUZ_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define BUZ_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define BUZ_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define BUZ_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set C1 aliases
#define C1_TRIS                 TRISBbits.TRISB5
#define C1_LAT                  LATBbits.LATB5
#define C1_PORT                 PORTBbits.RB5
#define C1_WPU                  WPUBbits.WPUB5
#define C1_ANS                  ANSELBbits.ANSB5
#define C1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define C1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define C1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define C1_GetValue()           PORTBbits.RB5
#define C1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define C1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define C1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define C1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define C1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define C1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set GPIO1 aliases
#define GPIO1_TRIS                 TRISCbits.TRISC0
#define GPIO1_LAT                  LATCbits.LATC0
#define GPIO1_PORT                 PORTCbits.RC0
#define GPIO1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define GPIO1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define GPIO1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define GPIO1_GetValue()           PORTCbits.RC0
#define GPIO1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define GPIO1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set GPIO2 aliases
#define GPIO2_TRIS                 TRISCbits.TRISC1
#define GPIO2_LAT                  LATCbits.LATC1
#define GPIO2_PORT                 PORTCbits.RC1
#define GPIO2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define GPIO2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define GPIO2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define GPIO2_GetValue()           PORTCbits.RC1
#define GPIO2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define GPIO2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set GPIO3 aliases
#define GPIO3_TRIS                 TRISCbits.TRISC2
#define GPIO3_LAT                  LATCbits.LATC2
#define GPIO3_PORT                 PORTCbits.RC2
#define GPIO3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define GPIO3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define GPIO3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define GPIO3_GetValue()           PORTCbits.RC2
#define GPIO3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define GPIO3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set GPIO4 aliases
#define GPIO4_TRIS                 TRISCbits.TRISC5
#define GPIO4_LAT                  LATCbits.LATC5
#define GPIO4_PORT                 PORTCbits.RC5
#define GPIO4_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define GPIO4_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define GPIO4_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define GPIO4_GetValue()           PORTCbits.RC5
#define GPIO4_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define GPIO4_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set IN1 aliases
#define IN1_TRIS                 TRISDbits.TRISD0
#define IN1_LAT                  LATDbits.LATD0
#define IN1_PORT                 PORTDbits.RD0
#define IN1_ANS                  ANSELDbits.ANSD0
#define IN1_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IN1_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IN1_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IN1_GetValue()           PORTDbits.RD0
#define IN1_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IN1_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IN1_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define IN1_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set IN2 aliases
#define IN2_TRIS                 TRISDbits.TRISD1
#define IN2_LAT                  LATDbits.LATD1
#define IN2_PORT                 PORTDbits.RD1
#define IN2_ANS                  ANSELDbits.ANSD1
#define IN2_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IN2_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IN2_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IN2_GetValue()           PORTDbits.RD1
#define IN2_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IN2_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IN2_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define IN2_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set IN3 aliases
#define IN3_TRIS                 TRISDbits.TRISD2
#define IN3_LAT                  LATDbits.LATD2
#define IN3_PORT                 PORTDbits.RD2
#define IN3_ANS                  ANSELDbits.ANSD2
#define IN3_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IN3_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IN3_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IN3_GetValue()           PORTDbits.RD2
#define IN3_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IN3_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IN3_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define IN3_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set IN4 aliases
#define IN4_TRIS                 TRISDbits.TRISD3
#define IN4_LAT                  LATDbits.LATD3
#define IN4_PORT                 PORTDbits.RD3
#define IN4_ANS                  ANSELDbits.ANSD3
#define IN4_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IN4_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IN4_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IN4_GetValue()           PORTDbits.RD3
#define IN4_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IN4_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IN4_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define IN4_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set IN5 aliases
#define IN5_TRIS                 TRISDbits.TRISD4
#define IN5_LAT                  LATDbits.LATD4
#define IN5_PORT                 PORTDbits.RD4
#define IN5_ANS                  ANSELDbits.ANSD4
#define IN5_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IN5_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IN5_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IN5_GetValue()           PORTDbits.RD4
#define IN5_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IN5_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IN5_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define IN5_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set IN6 aliases
#define IN6_TRIS                 TRISDbits.TRISD5
#define IN6_LAT                  LATDbits.LATD5
#define IN6_PORT                 PORTDbits.RD5
#define IN6_ANS                  ANSELDbits.ANSD5
#define IN6_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IN6_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IN6_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IN6_GetValue()           PORTDbits.RD5
#define IN6_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IN6_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IN6_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define IN6_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set IN7 aliases
#define IN7_TRIS                 TRISDbits.TRISD6
#define IN7_LAT                  LATDbits.LATD6
#define IN7_PORT                 PORTDbits.RD6
#define IN7_ANS                  ANSELDbits.ANSD6
#define IN7_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IN7_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IN7_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IN7_GetValue()           PORTDbits.RD6
#define IN7_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IN7_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IN7_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define IN7_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set IN8 aliases
#define IN8_TRIS                 TRISDbits.TRISD7
#define IN8_LAT                  LATDbits.LATD7
#define IN8_PORT                 PORTDbits.RD7
#define IN8_ANS                  ANSELDbits.ANSD7
#define IN8_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IN8_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IN8_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IN8_GetValue()           PORTDbits.RD7
#define IN8_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IN8_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IN8_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define IN8_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set C4 aliases
#define C4_TRIS                 TRISEbits.TRISE0
#define C4_LAT                  LATEbits.LATE0
#define C4_PORT                 PORTEbits.RE0
#define C4_ANS                  ANSELEbits.ANSE0
#define C4_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define C4_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define C4_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define C4_GetValue()           PORTEbits.RE0
#define C4_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define C4_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define C4_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define C4_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set C3 aliases
#define C3_TRIS                 TRISEbits.TRISE1
#define C3_LAT                  LATEbits.LATE1
#define C3_PORT                 PORTEbits.RE1
#define C3_ANS                  ANSELEbits.ANSE1
#define C3_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define C3_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define C3_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define C3_GetValue()           PORTEbits.RE1
#define C3_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define C3_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define C3_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define C3_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set C2 aliases
#define C2_TRIS                 TRISEbits.TRISE2
#define C2_LAT                  LATEbits.LATE2
#define C2_PORT                 PORTEbits.RE2
#define C2_ANS                  ANSELEbits.ANSE2
#define C2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define C2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define C2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define C2_GetValue()           PORTEbits.RE2
#define C2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define C2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define C2_SetAnalogMode()      do { ANSELEbits.ANSE2 = 1; } while(0)
#define C2_SetDigitalMode()     do { ANSELEbits.ANSE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/