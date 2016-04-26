//programm for legoNXT robot - finding and sorting colorful targets
//for robotics comptition 2012


#define REDPOL 9
#define REDKUB 8
#define GREENPOL 5
#define GREENKUB 4
#define SINPOL 0
#define SINKUB 2

mutex moveMutex;

int color_pol,r1,g1,b1;
int color_kubik,r2,g2,b2;
int sem=0; 
int i=0; 
int kub;

task sensors ()
{
while (TRUE)
{      ReadSensorHTColor(IN_3,color_pol,r1,g1,b1);
       ReadSensorHTColor(IN_4,color_kubik,r2,g2,b2);
}}


task kubiki ()
{

while (i<12)  
{
ClearScreen();
NumOut(10, LCD_LINE1, color_pol);
NumOut(10, LCD_LINE2, color_kubik);
NumOut(10, LCD_LINE5, SensorUS(IN_1));
NumOut(10, LCD_LINE6, SensorUS(IN_2));

//Wait(100);

//Acquire(moveMutex);
//OnFwd(OUT_AB,10);
//Release(moveMutex);
do {                    
Acquire(moveMutex);
OnFwdReg(OUT_AB,50,OUT_REGMODE_SPEED);
Wait(100);
Release(moveMutex);
}                                     
while (color_kubik == 17)
switch(color_kubik)
{                                     
case REDKUB: {
ClearScreen();
NumOut(10, LCD_LINE2, color_kubik);
TextOut(10, LCD_LINE3, "red");
            Acquire(moveMutex);
            Off(OUT_C);
            OnFwd(OUT_C,50); 
            Wait(300);
            Release(moveMutex);
            kub=REDPOL;
break;}
case GREENKUB: {
NumOut(10, LCD_LINE2, color_kubik);
NumOut(10, LCD_LINE2, color_kubik);
TextOut(10, LCD_LINE4, "green");
            Acquire(moveMutex);
            Off(OUT_C);
            OnFwd(OUT_C,50); 
            Wait(300);
            Release(moveMutex);
            kub=GREENPOL;
break;}
case SINKUB: {
NumOut(10, LCD_LINE2, color_kubik);
NumOut(10, LCD_LINE2, color_kubik);
TextOut(10, LCD_LINE5, "sin");
            Acquire(moveMutex);
            Off(OUT_C);
            OnFwd(OUT_C,50); 
            Wait(300);
            Release(moveMutex);
            kub=SINPOL;
break;}}                                     

do
{
            Acquire(moveMutex);
            OnFwdReg(OUT_AB,50,OUT_REGMODE_SPEED);
            Wait(100);
            Release(moveMutex);
}
while (color_pol != kub)
            Acquire(moveMutex);
            OnRev(OUT_C,50); 
            Wait(300);
            OnFwdReg(OUT_AB,50,OUT_REGMODE_SPEED);
            Wait(50);
            Release(moveMutex);
            i++;


{       
 Acquire(moveMutex);
 Off(OUT_AB);
 Wait(1000);
 Release(moveMutex);
}}} 




task dalnomer ()  
{
while (TRUE)
{
if ((SensorUS(IN_1)<15) || (SensorUS(IN_2)<15))
{
Acquire(moveMutex);
OnRevReg(OUT_AB,50,OUT_REGMODE_SPEED);
Wait(1000);
Off(OUT_AB);
OnFwd(OUT_A,50);
Wait(500);
Off(OUT_AB);
Release(moveMutex);
}}}


task white ()       
{
while (TRUE)
{
if (color_kubik ==17 && color_pol !=17)
{    
Acquire(moveMutex);
OnRevReg(OUT_AB,50,OUT_REGMODE_SPEED);
Wait(1000);
Off(OUT_AB);
OnFwd(OUT_A,50);
Wait(500);
Off(OUT_AB);
Release(moveMutex);
}}}






task withwhite1 ()

{
while (TRUE)
{
if (color_kubik ==REDKUB && color_pol !=REDPOL)
{    
Acquire(moveMutex);
OnRevReg(OUT_AB,50,OUT_REGMODE_SPEED);
Wait(1000);
Off(OUT_AB);
OnFwd(OUT_A,50);
Wait(500);
Off(OUT_AB);
Release(moveMutex);
}}}




task withwhite2 ()

{
while (TRUE)
{
if (color_kubik ==SINKUB && color_pol !=SINPOL)
{    
Acquire(moveMutex);
OnRevReg(OUT_AB,50,OUT_REGMODE_SPEED);
Wait(1000);
Off(OUT_AB);
OnFwd(OUT_A,50);
Wait(500);
Off(OUT_AB);
Release(moveMutex);
}}}




task withwhite3 ()

{
while (TRUE)
{
if (color_kubik ==GREENKUB && color_pol !=GREENPOL)
{    
Acquire(moveMutex);
OnRevReg(OUT_AB,50,OUT_REGMODE_SPEED);
Wait(1000);
Off(OUT_AB);
OnFwd(OUT_A,50);
Wait(500);
Off(OUT_AB);
Release(moveMutex);
}}}




task main ()
{
    SetSensorLowspeed(IN_1);       
    SetSensorLowspeed(IN_2);        
    SetSensorLowspeed(IN_3);      
    SetSensorLowspeed(IN_4);      
    OnRev(OUT_C,50); 
    Wait(300);
    Precedes(sensors, kubiki, dalnomer, white, withwhite1, withwhite2, withwhite3);
}


