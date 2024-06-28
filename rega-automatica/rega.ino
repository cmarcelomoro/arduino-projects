
const int pinoSensorUmidade = A0;
const int pinoRele = 12;
const int pinoLedVerde = 3;
const int pinoLedAmarelo = 4;
const int pinoLedVermelho = 5; 
int valorUmidade;



void setup()
{
  Serial.begin(9600);
  pinMode(pinoSensorUmidade,INPUT);
  pinMode(pinoRele, OUTPUT);

  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);

}
 
void loop()
{


  valorUmidade = analogRead(pinoSensorUmidade);
  Serial.println(valorUmidade);
  delay(10000);

  if(valorUmidade >= 600){

    digitalWrite(pinoLedVermelho,HIGH);
    digitalWrite(pinoLedVerde,LOW);
    digitalWrite(pinoLedAmarelo,LOW);

    Serial.println("o solo está seco");
    digitalWrite(pinoRele,LOW);
    Serial.println("Abrindo válvula por 30 segundos");
    delay(30000);
    Serial.println("Fechando válvula");
    digitalWrite(pinoRele,HIGH);
    
  }
   if(valorUmidade > 300 && valorUmidade < 550){
    
    digitalWrite(pinoLedVermelho,LOW);
    digitalWrite(pinoLedVerde,LOW);
    digitalWrite(pinoLedAmarelo,HIGH);

    Serial.println("o solo está com umidade média");
    
  }



  if(valorUmidade <= 500){
    Serial.println("O solo está umido");

    digitalWrite(pinoLedVermelho,LOW);
    digitalWrite(pinoLedVerde,HIGH);
    digitalWrite(pinoLedAmarelo,LOW);

    Serial.println("o solo está umido");
    digitalWrite(pinoRele,LOW);
    
  }
}