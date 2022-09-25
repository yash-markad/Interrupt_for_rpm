
const byte interruptPin = 2;
volatile long n=0;
volatile long RPM=0;
volatile boolean flag=0;
long RPMperiod;
unsigned long previoustime=0;


void setup()
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(interruptPin), sensor, FALLING);

}

void loop()
{
    if(flag)
  {
    RPM=(60000000UL/RPMperiod);   //One (1) signal per rotation.
    interrupts();
    Serial.print("RPM = ");
    Serial.println(RPM );
    flag=0;
  }
}

void sensor()
{unsigned long currenttime=micros();
  RPMperiod=float ( currenttime- previoustime);
  flag=1;
  previoustime = currenttime;

}
