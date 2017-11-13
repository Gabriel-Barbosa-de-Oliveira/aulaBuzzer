const int buzzer = 12; 

void setup() 
{
	pinMode(buzzer,OUTPUT); //Pino do buzzer
}

void loop()
{
    music();
}

void music (){
        delay(2000);
    tone(buzzer,262,200); //DO
    delay(200);
    tone(buzzer,294,300); //RE
    delay(200);
    tone(buzzer,330,300); //MI
    delay(200);
    tone(buzzer,349,300); //FA
    delay(300);
    tone(buzzer,349,300); //FA
    delay(300);
    tone(buzzer,349,300); //FA
    delay(300);
    tone(buzzer,262,100); //DO
    delay(200);
    tone(buzzer,294,300); //RE
    delay(200);   
    tone(buzzer,262,100); //DO
    delay(200);
    tone(buzzer,294,300); //RE
    delay(300);
    tone(buzzer,294,300); //RE
    delay(300);
    tone(buzzer,294,300); //RE
    delay(300);
    tone(buzzer,262,200); //DO
    delay(200);
    tone(buzzer,392,200); //SOL
    delay(200);
    tone(buzzer,349,200); //FA
    delay(200);
    tone(buzzer,330,300); //MI
    delay(300);
    tone(buzzer,330,300); //MI
    delay(300);
    tone(buzzer,330,300); //MI
    delay(300);
    tone(buzzer,262,200); //DO
    delay(200);
    tone(buzzer,294,300); //RE
    delay(200);
    tone(buzzer,330,300); //MI
    delay(200);
    tone(buzzer,349,300); //FA
    delay(300);
    tone(buzzer,349,300); //FA
    delay(300);
    tone(buzzer,349,300); //FA
    delay(300);
}