#include <reg51.h>

sbit wave = P2^1;

void timer0(void) interrupt 1
{
    wave = ~wave;
}

void main()
{
    while(1)
    {
        TMOD = 0x01;
        TH0 = 0xFF;
        TL0 = 0xF9;
        IE = 0x82;
        TR0 = 1;
    }
}