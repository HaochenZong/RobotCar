#include<AT89X52.H>		  //contain 51 Single Chip Microcomputer (SCM) heading
#include<HJ-4WD_PWM.H>	  //contain the definition of robot car driving I/O, etc
    
//main
void main(void)
{	

	unsigned char i;
    P1=0X00;	  

	TMOD=0X01;
    TH0= 0XFc;		  
    TL0= 0X18;
    TR0= 1;
    ET0= 1;
	 EA = 1;


	while(1)	
	{ 
	 
		//has signal: 0,  no signal: 1
		//define sensor R:right, L:left  
        if(Left_B_led==1&&Right_B_led==1)	 //no object forward

		run();

		else
		{			  
			if(Left_B_led==0&&Right_B_led==1)	    
			{
			
				Left_moto_go;						  
				Right_moto_Stop;
				 
			}
			   
			if(Right_B_led==0&&Left_B_led==1)		
			{	  
		
				Right_moto_go;					  
				Left_moto_Stop;
			}
		}	 
	 }
}