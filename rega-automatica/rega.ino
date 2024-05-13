
const int pinoSensorUmidade = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(pinoSensorUmidade,INPUT);
 
}
 
void loop()
{
  Serial.println(analogRead(pinoSensorUmidade));
  delay(500);
}