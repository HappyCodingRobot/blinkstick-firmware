/* Name: main.c
 * Project: BlinkStick
 * Author: Arvydas Juskevicius
 * Creation Date: 2013-04-02
 * Tabsize: 4
 * Copyright: (c) 2013 by Agile Innovative Ltd
 * License: GNU GPL v2 (see License.txt), GNU GPL v3 or proprietary (CommercialLicense.txt)
 */

#define LED_PORT_DDR        DDRB
#define LED_PORT_OUTPUT     PORTB
#define R_BIT            1
#define G_BIT            0
#define B_BIT            4

#define uchar unsigned char

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
//#include <avr/interrupt.h>  /* for sei() */
//#include <util/delay.h>     /* for _delay_ms() */
#include <avr/pgmspace.h>   /* required by usbdrv.h */


// serial number string in eeprom: "BS<6-digit number>-1.4"
#define SERIAL_NUMBER_LENGTH 12 // BSXXXXXX-1.0
const char serial_string[SERIAL_NUMBER_LENGTH+1] = "BS003001-1.4";



int main(void) {
    uchar serialNumber[SERIAL_NUMBER_LENGTH];
    eeprom_read_block(serialNumber, (uchar *)0 + 1, SERIAL_NUMBER_LENGTH);
    
    if (serialNumber[0]!='B' || serialNumber[1]!='S') {
        eeprom_write_block(&serial_string, (uchar *)0 + 1, SERIAL_NUMBER_LENGTH);
    }
    
    LED_PORT_DDR |= (1<<PB1);       // PB1 as LED_PORT_OUTPUT
    LED_PORT_OUTPUT |= (1<<PB1);    // set LED (digistump..)
    
    for(;;){                /* main event loop */
    }
    return 0;
}

/* ------------------------------------------------------------------------- */
