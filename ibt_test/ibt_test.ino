int RPWM_Output = 3; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output = 2; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)
 
void setup()
{
  pinMode(RPWM_Output, OUTPUT);
  pinMode(LPWM_Output, OUTPUT);
}

void loop()
{
  int pwm;
  for(pwm=0;pwm<=255;pwm++)
  {
    analogWrite(RPWM_Output,pwm);
    analogWrite(LPWM_Output,pwm);
    delay(10);
  }
  for(pwm=255;pwm>=0;pwm--)
  {
    analogWrite(RPWM_Output,pwm);
    analogWrite(LPWM_Output,pwm);
    delay(10);
  }
}
