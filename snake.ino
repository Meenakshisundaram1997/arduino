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
unsigned long delaytime=500;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,2);
  /* and clear the display */
  lc.clearDisplay(0);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  randomSeed(7);
  digitalWrite(13,LOW);
}
void loop(){
  //int s=digitalRead(7);
  int a[8]={128,64,32,16,8,4,2,1};
 int b[8]={1,2,4,8,16,32,64,128};
  int r=7;
  int c=0;
  int r1=1;
  int l1=0;
  
  int x=0;
    int qwe,rty;
 
 
  while(1)
  {
    int i=c;
   int k;
   qwe=random(1,7);
rty=random(1,7);
 lc.setLed(0,qwe,rty,true);  
  int z=i;
  while(i<6||z>1)
  {
    
    if(r1==1)
    {
    k=a[i]+a[i+1]+a[i+2];
   
    }
    else if(l1==1)
    {
     k=a[z]+a[z-1]+a[z-2];
     
    } 
      
    lc.setRow(0,r,k);
    delay(500);
    int s=digitalRead(7);
    int d=digitalRead(4);
    if(s==1)
    {
      if(r==0)
        lc.shutdown(0,true);
      if(r1==1)
      {
      c=i+2;
      lc.setRow(0,r,a[i+1]+a[i+2]);
      lc.setColumn(0,c,a[r]+a[r-1]);
      delay(500);
      lc.setRow(0,r,a[c]);
      }
      else if(l1==1)
      {
        c=z-2;
      lc.setRow(0,r,a[z-2]+a[z-1]);
      lc.setColumn(0,c,a[r]+a[r-1]);
      delay(500);
      lc.setRow(0,r,a[c]);
      } 
      for(int j=r;j>=2;j--)
      {
        int k=a[j-2]+a[j-1]+a[j];
        int p;
        if(r1==1)
        p=i+2;
        else if(l1==1)
        p=z-2;
        lc.setColumn(0,p,k);
        delay(500);
        int f=digitalRead(6);
        int l=digitalRead(5);
        if(f==1)
        {
          r1=1;
          l1=0;
          r=j-2;
          if(c==7)
          {
          lc.shutdown(0,true);
          }
          lc.setColumn(0,c,a[j-2]+a[j-1]);
          lc.setRow(0,r,a[c]+a[c+1]);
          delay(500);
          lc.setColumn(0,c,a[j-2]);
          x=1;
          
          break;
        }  
        
        else if(l==1)
       {
          l1=1;
          r1=0;
          r=j-2;         
          if(c==0)
          {
          lc.shutdown(0,true);
          }
          lc.setColumn(0,c,a[j-2]+a[j-1]);
          lc.setRow(0,r,a[c]+a[c-1]);
          delay(500);
          lc.setColumn(0,c,a[j-2]);
          x=1;
          
          break;
        } 
       
       
          
        if(j==2)
        { 
          lc.shutdown(0,true);
          x=1;
        }
         
      
        
      }
      if(x==1)
      break;
       
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(d==1)
    {
      if(r==7)
        lc.shutdown(0,true);
      if(r1==1)
      {
        
      c=i+2;
      lc.setRow(0,r,a[i+1]+a[i+2]);
      lc.setColumn(0,c,a[r]+a[r+1]);
      delay(500);
      lc.setRow(0,r,a[c]);
      }
      else if(l1==1)
      {
        c=z-2;
      lc.setRow(0,r,a[z-2]+a[z-1]);
      lc.setColumn(0,c,a[r]+a[r+1]);
      delay(500);
      lc.setRow(0,r,a[c]);
      } 
      for(int j=r;j<6;j++)
      {
        int k=a[j+2]+a[j+1]+a[j];
        int p;
        if(r1==1)
        p=i+2;
        else if(l1==1)
        p=z-2;
        lc.setColumn(0,p,k);
        delay(500);
        int f=digitalRead(6);
        int l=digitalRead(5);
        if(f==1)
        {
          r1=1;
          l1=0;
          r=j+2;
          if(c==7)
          {
          lc.shutdown(0,true);
          }
          lc.setColumn(0,c,a[j+2]+a[j+1]);
          lc.setRow(0,r,a[c]+a[c+1]);
          delay(500);
          lc.setColumn(0,c,a[j+2]);
          x=1;
          
          break;
        }  
        
        else if(l==1)
       {
          l1=1;
          r1=0;
          r=j+2;         
          if(c==0)
          {
          lc.shutdown(0,true);
          }
          lc.setColumn(0,c,a[j+2]+a[j+1]);
          lc.setRow(0,r,a[c]+a[c-1]);
          delay(500);
          lc.setColumn(0,c,a[j+2]);
          x=1;
          
          break;
        } 
       
       
          
        if(j+2>=7)
        { 
          lc.shutdown(0,true);
          x=1;
        }
         
      
        
      }
      if(x==1)
      break;
       
    }
    
    
    
    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else
    {
      if(r1==1)
      i++;
      else if(l1==1)
      z--;
    }  
    if(r1==1&&i==6)
    lc.shutdown(0,true);
    if(l1==1&&z==1)
    lc.shutdown(0,true);
    
    }
    
  }
 
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*for(int g=7;g>=0;g--)
{  
  int r=g;
  for(int i=0;i<6;i++)
  {
    int k=a[i]+a[i+1]+a[i+2];
    lc.setRow(0,r,k);
    delay(500);
    if(i+2==7)
    { //lc.shutdown(0,true);
      k=a[i+1]+a[i+2];
      lc.setRow(0,r,k);
      lc.setColumn(0,7,a[r]+a[r-1]);
      delay(500);
      lc.setRow(0,r,a[7]);
      if(r!=1||r!=0)
      for(int j=r;j>=2;j--)
      {
        int k=a[j-2]+a[j-1]+a[j];
        lc.setColumn(0,7,k);
        delay(500);
        if(j==2)
        { 
          lc.shutdown(0,true);
        }
      }
      
      else if(r==1)
      {
        lc.setColumn(0,7,a[1]+a[0]);
      }  
      
    }
  }
  lc.shutdown(0,false);
  lc.setRow(0,g,0);
  lc.setColumn(0,7,0);
}  */

