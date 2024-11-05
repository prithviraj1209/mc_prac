#include<reg51.h>
void delay();
void main()
{
unsigned char dat;
while(1)
{
dat=0x01;
P2=dat;
delay();
dat=0x02;
P2=dat;
delay();
dat=0x04;
P2=dat;
delay();
dat=0x08;
P2=dat;
delay();
}
}
void delay()
{
TMOD=0X10;
TH1=0X00;
TL1=0X00;
TR1=1;
while(TF1==0);
TR1=0;
TF1=0;
}