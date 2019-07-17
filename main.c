/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC12F1572
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include <xc.h>


unsigned isClosed = 1;
unsigned toClose = 1;

/*
                         Main application
 */
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

    while (1) {
        toClose = PORTAbits.RA4;
        if (toClose && isClosed) {
            PORTAbits.RA2 = 1;
            __delay_us(996ul);
            PORTAbits.RA2 = 0;
            __delay_us(18996ul);
        } else if ((!toClose) && (!isClosed)) {
            PORTAbits.RA2 = 1;
            __delay_us(2000ul);
            PORTAbits.RA2 = 0;
            __delay_us(17996ul);
        } else if (toClose && !isClosed) {
            for (int cycle = 0; cycle < 200; cycle++) {
                PORTAbits.RA2 = 1;
                for (int counter = 200 - cycle; counter > 0; counter--) {
                    _delay(4ul);
                }
                __delay_us(995ul);
                PORTAbits.RA2 = 0;
                for (int counter = cycle; counter > 0; counter--) {
                    _delay(4ul);
                }
                __delay_us(17995ul);
            }
            isClosed = 1;
        } else if (isClosed && !toClose) {
            for (int cycle = 0; cycle < 200; cycle++) {
                PORTAbits.RA2=1;
                for (int counter = cycle; counter >0; counter--) {
                    _delay(4ul);
                }
                __delay_us(995ul);
                PORTAbits.RA2=0;
                for (int counter = 200-cycle; counter >0; counter--) {
                    _delay(4ul);
                }
                __delay_us(17995ul);
            }
            isClosed = 0;
        }
    }
}
/**
 End of File
 */