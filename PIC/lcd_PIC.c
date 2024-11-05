#include <P18f4550.h>

#define LCD_EN LATAbits.LA1
#define LCD_RS LATAbits.LA0
#define LCDPORT PORTB

void lcd_delay(unsigned int timer) {
    unsigned int i, j;
    for (i = 0; i < timer; i++) {
        for (j = 0; j < 100; j++) {
            // Do nothing, just delay
        }
    }
}

void SendInstruction(unsigned char command) {
    LCD_RS = 0; 
    LCDPORT = command;
    LCD_EN = 1;
    lcd_delay(10);
    LCD_EN = 0;
    lcd_delay(10);
}

void SendData(unsigned char leddata) {
    LCD_RS = 1; // RS HIGH for DATA
    LCDPORT = leddata;
    LCD_EN = 1; // EN High
    lcd_delay(10);
    LCD_EN = 0; // EN Low; data sampled at EN falling edge
    lcd_delay(10);
}

void InitLCD(void) {
    ADCON1 = 0x0F; // Set digital I/O
    TRISB = 0x00; // Set data port as output
    TRISAbits.RA0 = 0; // RS pin
    TRISAbits.RA1 = 0; // EN pin

    // 8 bit mode, 2 line, 5x7 dots
    SendInstruction(0x38);
    SendInstruction(0x06); // Entry mode
    SendInstruction(0x0C); // Display ON, cursor OFF
    SendInstruction(0x01); // Clear display
    SendInstruction(0x80); // Set address to 1st line
}

unsigned char *String1 = "Aradhana Shukla"; // Initialize with a valid string
unsigned char *String2 = "Anushka Bankar"; // PIC-18F Board

void main(void) {
    InitLCD(); // Initialize the LCD

    while (*String1) {
        SendData(*String1);
        String1++;
    }

    // Set address to 2nd line
    SendInstruction(0xC0);

    while (*String2) {
        SendData(*String2);
        String2++;
    }

    while (1) {
        // Infinite loop
    }
}