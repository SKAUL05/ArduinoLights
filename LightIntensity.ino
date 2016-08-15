/* Adjusting Light Intensity using Atmospheric Light*/
const int analog_in = 0;  // Analog Input Pin.
const int pwm_out = 3;   // Pulse Width Modulation output Pin. 

void setup()
{
    Serial.begin(9600);    // Setting Baud Rate to 9600 bps.
    pinMode(pwm_out,OUTPUT);
}
void loop()
{
    int value = analogRead(analog_in);    // To read the input from the photosensor.
    Serial.println(value);                // Printing the value on the serial moniter.
    
    if(value >= 30)
    {
        analogWrite(pwm_out,255);
    }
    else if(value >= 20)
    {  
        analogWrite(pwm_out,200);
    }
    else if(value >= 10)
    {
        analogWrite(pwm_out,120);
    } 
    else if(value >= 5)
    {
        analogWrite(pwm_out,50);
    } 
    else
    {
        analogWrite(pwm_out,0);      
    }
}
