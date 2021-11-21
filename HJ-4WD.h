#ifndef _LED_H_
#define _LED_H_


    //define the I/O of the driving module of the car
	sbit IN1=P1^0;
	sbit IN2=P1^1;
	sbit IN3=P1^2;
	sbit IN4=P1^3;
	sbit IN5=P1^4;
	sbit IN6=P1^5;
	sbit IN7=P1^6;
	sbit IN8=P1^7;	

	// define buzzer wiring 
    sbit BUZZ=P3^2;

	//define 4 sensors of robot car chassis
    #define Left_1_led        P3_7	 
	#define Left_2_led        P3_6	 
    #define Right_1_led       P3_5	 
	#define Right_2_led       P3_4	 

	//define driving wiring of robot car 
    #define Left_moto_go      {P1_4=1,P1_5=0,P1_6=1,P1_7=0;}   
	#define Left_moto_back    {P1_4=0,P1_5=1,P1_6=0,P1_7=1;}    
	#define Left_moto_Stop    {P1_4=0,P1_5=0,P1_6=0,P1_7=0;}                        
	#define Right_moto_go     {P1_0=1,P1_1=0,P1_2=1,P1_3=0;}	
	#define Right_moto_back   {P1_0=0,P1_1=1,P1_2=0,P1_3=1;}	
	#define Right_moto_Stop   {P1_0=0,P1_1=0,P1_2=0,P1_3=0;}	  

//time delay	
void delay(unsigned int k)
{    
     unsigned int x,y;
	 for(x=0;x<k;x++) 
	   for(y=0;y<2000;y++);
}
/************************************************************************/
//go forward
void  run(void)
{    
     IN1=1;	 	 
     IN2=0;	 
	 IN3=1;	 
	 IN4=0; 
     IN5=1;	 	 
     IN6=0;	 
	 IN7=1;	 
	 IN8=0;
	 //P1=0X55;
}
/*********************************************************************/		 
/************************************************************************/
//go back
void  backrun(void)
{
     IN1=0;	 	 
     IN2=1;	 
	 IN3=0;	 
	 IN4=1; 
     IN5=0;	 	 
     IN6=1;	 
	 IN7=0;	 
	 IN8=1;
}
/*********************************************************************/	
/************************************************************************/
//turn left
void  leftrun(void)
{
     IN1=1;	 	 
     IN2=0;	 
	 IN3=1;	 
	 IN4=0; 
     IN5=0;	 	 
     IN6=1;	 
	 IN7=0;	 
	 IN8=1;
}
/*********************************************************************/	
/************************************************************************/
//turn right
     void  rightrun(void)
{
     IN1=0;	 	 
     IN2=1;	 
	 IN3=0;	 
	 IN4=1; 
     IN5=1;	 	 
     IN6=0;	 
	 IN7=1;	 
	 IN8=0;
}
/*********************************************************************/	
/************************************************************************/
//stop motor
void  stop(void)
{
     IN1=0;	 	 
     IN2=0;	 
	 IN3=0;	 
	 IN4=0; 
     IN5=0;	 	 
     IN6=0;	 
	 IN7=0;	 
	 IN8=0;
	 //P1=0X00;
}
/*********************************************************************/	

#endif