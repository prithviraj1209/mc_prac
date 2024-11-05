#include<p18f4550.h>
void delay(unsigned int time)
{
    unsigned int i,j;
    for(i=0;i<time;i++)
        for(j=0;j<5000;j++);
}
void main(void)
{
    TRISB=0x00;
    while(1)
    {
        PORTB=0x00;
        delay(100);
        PORTB=0xFF;
        delay(100);
    }
}