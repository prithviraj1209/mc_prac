#include <p18f4550.h>

void timer2Init(void)
{
    T2CON = 0b00000100; // Prescaler = 16; Timer2 ON (set the TMR2ON bit here)
    PR2 = 0x95; // Period Register for 200us
}

void delay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1000; j++);
}

void main(void)
{
    unsigned int i;
    TRISCbits.TRISC1 = 0; // RC1 pin as output
    TRISCbits.TRISC2 = 0; // CCP1 pin as output
    LATCbits.LATC1 = 0;

    CCP1CON = 0b00111100; // Select PWM mode; Duty cycle LSB
    CCP1CONbits.CCP1M3 = 1; // Set bit 3
    CCP1CONbits.CCP1M2 = 1; // Set bit 2

    CCPR1L = 0x0F; // Duty cycle 10%
    timer2Init(); // Initialize Timer2

    TMR2ON = 1; // Timer2 ON

    while (1) // Loop forever
    {
        for (i = 15; i < 150; i++)
        {
            CCPR1L = i; // Adjust duty cycle
            delay(100); // Delay for visibility
        }
        for (i = 150; i > 15; i--)
        {
            CCPR1L = i; // Adjust duty cycle
            delay(100); // Delay for visibility
        }
    }
}