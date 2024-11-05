#include <reg51.h>

void delay(){
    int i;
    for(i=0; i<=12; i++){
        TMOD = Ox01;
        TL0 = 0x00;
        TH0 = 0x00;
        TR0 = 1;
        while(TF0 == 0);
        TR0 = 0;
        TF0 = 0;
    }    
}

unsigned char codes[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f}

void main(){
    int k;
    while(1){
        for(k=0; k<11; k++){
            P2 = codes[k];
            delay();
        }
    }
}