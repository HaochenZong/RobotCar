#ifndef _LED_H_
#define _LED_H_

    //define motor units I/O
	sbit IN1=P1^0;	   
	sbit IN2=P1^1;	   
	sbit IN3=P1^2;	   
	sbit IN4=P1^3;	   

	sbit IN5=P1^4;	   
	sbit IN6=P1^5;	   
	sbit IN7=P1^6;	   
	sbit IN8=P1^7;	   

	// define buzzer wiring 
    sbit BUZZ=P2^6;

	//define sensor R:right, L:left  
    //sensor of tracking X, left: P3.5, right: P3.6
	#define Left_X_led        P3_5	 
	#define Right_X_led       P3_6	 

	//sensor of avoiding obstacles B, left: P3.4, right: P3.7  
 	#define Left_B_led        P3_4	 
	#define Right_B_led       P3_7	 
		
	//motor PWM controls speed I/O definition 
	#define Left_moto_pwm	  P1_1	 
	#define Left_moto_pwm1	  P1_3	
	#define Right_moto_pwm	  P1_5
	#define Right_moto_pwm1	  P1_7								 
	//define motor steering 						 
	#define Left_moto_go      {P1_0=1,P1_2=1;}     
	#define Left_moto_Stop    {P1_0=0,P1_2=0;}    
		                    
	#define Right_moto_go     {P1_4=1,P1_6=1;}	
	#define Right_moto_Stop   {P1_4=0,P1_6=0;}	  
	//define variables
	unsigned char pwm_val_left  =0;
	unsigned char push_val_left =0;
	unsigned char pwm_val_right =0;
	unsigned char push_val_right=0;
	bit Right_moto_stop=1;
	bit Left_moto_stop =1;
	unsigned  int  time=0;
   
/************************************************************************/	
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
     push_val_left=4;	 
	 push_val_right=4;
	 Left_moto_go ;   
	 Right_moto_go ;  
}



//turn left
     void  leftrun(void)
{	 
     push_val_left=4;
	 push_val_right=4;
	 Left_moto_go ;   
//	 Right_moto_back ;  
}

//turn right
     void  rightrun(void)
{ 
	 push_val_left=4;
	 push_val_right=4;
//	 Left_moto_back ;  
	 Right_moto_go ;  
}


/************************************************************************/
/*                    PWM controls motor rotational speed               */
/************************************************************************/
/*                    left motor controls speed                         */
void pwm_out_left_moto(void)
{  
   if(Left_moto_stop)
   {
    if(pwm_val_left<=push_val_left)
	       {
		     Left_moto_pwm=1; 
		     Left_moto_pwm1=1; 
		   }
	else 
	       {
	         Left_moto_pwm=0;
		     Left_moto_pwm1=0; 
		   }
	if(pwm_val_left>=10)
	       pwm_val_left=0;
   }
   else    
          {
           Left_moto_pwm=0;
           Left_moto_pwm1=0; 
		  }
}
/******************************************************************/
/*                    right motor controls speed                  */  
void pwm_out_right_moto(void)
{ 
  if(Right_moto_stop)
   { 
    if(pwm_val_right<=push_val_right)
	      {
	       Right_moto_pwm=1; 
		   Right_moto_pwm1=1; 
		   }
	else 
	      {
		   Right_moto_pwm=0;
		   Right_moto_pwm1=0; 
		  }
	if(pwm_val_right>=10)
	       pwm_val_right=0;
   }
   else    
          {
           Right_moto_pwm=0;
           Right_moto_pwm1=0; 
	      }
}
       
/***************************************************/
 	void timer0()interrupt 1   using 2
{
     TH0=0XFc;	  
	 TL0=0X18;
	 time++;
	 pwm_val_left++;
	 pwm_val_right++;
	 pwm_out_left_moto();
	 pwm_out_right_moto();
 }	

/*********************************************************************/	

#endif