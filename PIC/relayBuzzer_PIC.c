#include<p18F4550.h>
void delay(){
    unsigned int i;
    for(i=0;i<30000;i++);
}
void main(){
    unsigned char i,key=0;
    TRISB=0x00;
    //LATB=0x00;
    ADCON1=0x0F;
    TRISAbits.TRISA2=1;
    TRISAbits.TRISA3=1;
    TRISAbits.TRISA5=0;
    TRISAbits.TRISA4=0;
    while(1){
        //LATAbits.LA2=1;
        //LATAbits.LA3=1;
        if(PORTAbits.RA2==0) key=0;
        if(PORTAbits.RA3==0) key=1;
        if(key==0){
            PORTAbits.RA4==0;
            PORTAbits.RA5==1;
            for(i=0;i<8;i++)
            {
                PORTB=1<<i;
                delay();
                PORTB =0X00;
                delay();
            }
        }
        if(key==1){
            PORTAbits.RA4=0;
            PORTAbits.RA5=1;
            for(i=7;i>0;i--){
                PORTB=1<<i;
                delay();
                PORTB=0x00;
                delay();

            }
        }
    }
}