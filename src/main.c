#include <REG51.H>
sfr P0=0x80;
sfr P1=0x90;
sfr P2=0xA0;
sfr P3=0xB0;
sbit P1_0=P1^0;
sbit P1_1=P1^1;
sbit P1_2=P1^2;
#define YELLOW_LED P1_0
#define BLUE_LED P1_1
#define RED_LED P1_2

unsigned char temp[20] _at_ 0x30;
unsigned char i,aver,max,min;
unsigned int sum;
unsigned char xdata *p;
unsigned char xdata *m;
unsigned char xdata *q;
unsigned char xdata *n;

void ran_temp(void){
	m=(unsigned char xdata*)0x0000;
	for(i=0;i<20;i++){
		temp[i]=i+20;
		temp[i]=temp[i]+(i%3-1);//pianyi
		*(m+i)=temp[i];
	}
}//weisuiji temp20-39

void average_temp(void){
	sum=0;
	for(i=0;i<20;i++){
		sum+=temp[i];
	}
	aver=sum/20;
	p=(unsigned char xdata*)0x2000;
  *p=aver;
}//average
	
void max_temp(void){
	q=(unsigned char xdata*)0x2001;
	max=temp[0];
	for(i=0;i<20;i++){
	if(max<temp[i]){
		max=temp[i];
	}
	*q=max;
   }
}//max

void min_temp(void){
	n=(unsigned char xdata*)0x2002;
	min=temp[0];
	for(i=0;i<20;i++){
	if(min>temp[i]){
	min=temp[i];
	}
	*n=min;
  }
}//min

void yuzhi_temp(void){
	if(min<25){
		BLUE_LED=0;
	}
	if(max>35){
		YELLOW_LED=0;
	}
	
}//yuzhi

void fanwei_temp(){
	if((min<=25)&&(max>=35)){
		RED_LED=0;
	}
}//fanwei

void main(){
	BLUE_LED=1;
  YELLOW_LED=1;
  RED_LED=1;
	ran_temp();
	average_temp();
	max_temp();
	min_temp();
	yuzhi_temp();
	fanwei_temp();
	while(1);
}
	
		