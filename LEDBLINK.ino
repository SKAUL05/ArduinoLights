#define a 13
#define b 12
#define c 8

void setup()
{
  Serial.begin(9600);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  
}
boolean a_flag = LOW;
boolean b_flag = LOW;
boolean c_flag = LOW;

void loop()
{
  while (Serial.available() == 0);
  
  int val = Serial.parseInt(); 
  if(val == 1)      // Toogle first LED.
  {
    a_flag = !a_flag;
    digitalWrite(a,a_flag);  
  }
  else if(val == 2)   // Toogle Second LED.
  {
    b_flag = !b_flag;
    digitalWrite(b,b_flag);  
  }
  else if(val == 3)   // Toogle Third LED.
  {
    c_flag = !c_flag;
    digitalWrite(c,c_flag);  
  }
  else              // Turn Off all the LED.
  {
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
  }
  
  Serial.println(val);
}
