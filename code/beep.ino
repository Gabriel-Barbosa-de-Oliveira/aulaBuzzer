const int buzzer = 12; 
 
void setup() {
  pinMode(buzzer,OUTPUT);
}

void loop() { 
  /* Ligamos o buzzer com uma frequencia de 1500hz*/
  tone(buzzer,1500);  
  delay(1000); 
 /*Delay 1 segundo*/
 
  noTone(buzzer);
  /*Desligamos o Buzzer*/
   
  delay(1000);
 /*Esperamos um segundo para finalizar o método*/
}
