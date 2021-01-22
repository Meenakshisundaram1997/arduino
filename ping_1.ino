//We always have to include the library
#include "LedControlMS.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(5,INPUT);
  pinMode(4,INPUT);

}

void loop(){
int r=1,c=5;
int z=0,x=0;
int q=1,qu=1;
int f,k,d=35;
int a[]={128,64,32,16,8,4,2,1};
f=a[0]+a[1]+a[2];
lc.setRow(0,7,f);
k=f;
lc.setRow(0,0,k);
int df=100;
lc.setLed(0,r,c,true);
unsigned long curr,prev=0;
while(1)
{
  if(z==0)
  {
    lc.setLed(0,r,c,false);
    if(x==0)
    r++;
    else
    r--;
    
    c++;
    lc.setLed(0,r,c,true);
    
    if(c==7)

    {    
      z=1;
    }
    if(r==6)
    {
      if(c==q||c==q+1||c==q-1||c==q+2||c==q-2)
    x=1;
    else
    {
      delay(200);
     lc.shutdown(0,true);
    } 
    }
    if(r==1)
    {
      if(c==qu-1||c==qu+1||c==qu||c==qu+2||c==qu-2)
    x=0;
    else
    {
      delay(200);
     lc.shutdown(0,true);
    } 
    }
    
  }
  else
  {
      lc.setLed(0,r,c,false);
      if(x==0)
      r++;
      else
      r--;
      c--;
      lc.setLed(0,r,c,true);
      
      if(c==0)
        z=0;
        if(r==6)
    {
      if(c==q-1||c==q+1||c==q+2||c==q||c==q-2)
    x=1;
    else
    {
      delay(200);
     lc.shutdown(0,true);
    } 
    }
    if(r==1)
    {
      if(c==qu-1||c==qu+1||c==qu+2||c==qu||c==qu-2)
    x=0;
    else
    {
      delay(200);
     lc.shutdown(0,true);
    } 
    }
  }
  delay(d);  
if(digitalRead(6)==HIGH){
f=a[q+0]+a[q+1]+a[q+2];
lc.setRow(0,7,f);
q++;
if(q>4){q=5;}
}
delay(d);
if(digitalRead(7)==HIGH){
q--;
if(q<0){q=0;}
  f=a[q+0]+a[q+1]+a[q+2];
lc.setRow(0,7,f);

}
delay(d);

  if(digitalRead(5)==HIGH){
k=a[qu+0]+a[qu+1]+a[qu+2];
lc.setRow(0,0,k);
qu++;
if(qu>4){qu=5;}
}
delay(d);
if(digitalRead(4)==HIGH){
  qu--;
  if(qu<0){qu=0;}
k=a[qu+0]+a[qu+1]+a[qu+2];
lc.setRow(0,0,k);

}
//delay(300);
  curr=millis();
  if(curr-prev>=200)
  {
    df=df-2;
    prev=curr;
  } 
  if(df==0)
  df=10;
  delay(df);
}
      
















}
