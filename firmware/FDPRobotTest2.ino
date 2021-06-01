int step_time = 30;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);  
}
void loop()
{
  for(int i = 0; i < 5; i++)
  {
    forward();
  }
  for(int i = 0; i < 5; i++)
  {
    left();
  }
  for(int i = 0; i < 5; i++)
  {
    forward();
  }
  for(int i = 0; i < 5; i++)
  {
    right();
  }
}
void forward()
{
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);  
  delay(step_time);
  digitalWrite(9, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(2, HIGH);
  delay(step_time);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);  
  delay(step_time);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(5, HIGH);  
  delay(step_time);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW); 
  digitalWrite(3, LOW);
  digitalWrite(5, LOW); 
}

void left()
{
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  delay(step_time);
  digitalWrite(9, LOW);
  digitalWrite(6, HIGH);
  delay(step_time);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(step_time);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  delay(step_time);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW); 
}

void right()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(step_time);
  digitalWrite(5, LOW);
  digitalWrite(2, HIGH);
  delay(step_time);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  delay(step_time);
  digitalWrite(2, LOW);
  digitalWrite(5, HIGH);
  delay(step_time);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW); 
}



