 #include<reg51.h>
 void main(void)
 {
 unsigned char x,y,z;
 x=0x05;
 y=0x03;
 z=x-y;
 P0=z;
 }