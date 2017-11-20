int buzzer = 13;
int botao = 9;
int botao_next = 8;
int botao_previous = 10;
int estadoBtn;

float half = 0.5;
float one = 1.0;
float one_half = 1.5;
float two = 2.0;
float two_half = 2.5;

int tempo = 400;

int musicaHP[] = {824,980,873,824,1234,1100,925,824,980,873,777,873,617};
int duracaoHP[] = {tempo * one,tempo * one_half,tempo * half,tempo * one,tempo * two,tempo * one,tempo * two_half,tempo * two_half,tempo * one_half,tempo * half,tempo * one,tempo * two,tempo * one,tempo * two_half};              

//Intro do zelda

int zelda_tempo[] = {750,250,1000,500,500,250,250,250,250,1000,3000,750,250,1000,500,500,250,250,250,250,3000,375,375,375,2750,250,500,250,250,750,250,2000,500,500,750,250,2000,500,500,500,250,250,2000,500,500,500,250,250,2000,1000,4000}
int zelda_notas[] = {466,37,349,37,466,466,523,587,622,698,37,466,37,349,37,466,466,523,587,622,698,698,739,830,932,932,932,830,739,830,739,698,698,698,622,698,739,698,622,554,554,622,698,622,554,523,523,587,659,783,698}

//Liga da justiça - sem limites

jl_notas[] = {698,1046,1396,37,1244,1174,1244,1174,932,698,1046,1396,37,1244,1174,1244,1174,932,1396,1567,1661,1567,1396,1244,1174,1244,1396,932,1046,1396,1567,1661,1864,1661,1567,1396,1567,1661,1396,1244,2093}
jl_tempo[] = {1500,1500,1000,500,500,500,500,500,1000,1500,1500,1000,500,500,500,500,500,1500,500,500,3000,500,500,3000,500,500,2000,1000,4000,500,500,3000,500,500,3000,500,500,2000,1000,1000,3000}

//Sadness and sorrow

naruto_notas[] = {739,659,493,659,783,880,659,783,739,783,880,587,987,880,739,659,493,659,783,880,659,783,739,783,880,587,659}
naruto_tempo[] = {250,250,2500,500,500,1000,3000,2000,500,500,500,500,2000,2000,250,250,2500,500,500,1000,3000,2000,500,500,500,500,4000}

//ARRAY DE TESTE - MUDEI ALGUNS TONS SOMENTE PARA TESTE - FUNCIONOU

int musicaTeste[] = {1100,500,873,1100,1234,1100,925,824,980,873,777,873,777};
int duracaoTeste[] = {tempo * two,tempo * one_half,tempo * half,tempo * half,tempo * two,tempo * half,tempo * two_half,tempo * one,tempo * two,tempo *half, tempo * one,tempo * two,tempo * one,tempo * two_half}; 


void setTone(int pin, int note, int duration) {
  tone(pin, note, duration);
  delay(duration);
  noTone(pin);
}


void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT);
}
    int music_index = 0;
    int musicList_index = 0;
    int btn_play = 0;
    int musicList_len = 1;

void loop(){
    //Alterna o botão entre play e pause
    if(digitalRead(botao) == 1) {
        if(btn_play == 1) {
            delay(500);
            btn_play = 0;
        }
        else {
            btn_play = 1;
        }
    }
  
  if((digitalRead(botao_next) == 1)||(digitalRead(botao_previous) == 1)){
    btn_play = 1;
  }
  
  //Botão de próxima musica
    if(digitalRead(botao_next) == 1) {
        musicList_index++;
        //se indice de musicas for maior que 2 ele volta para a primeira musica
        if(musicList_index > 2) {
            musicList_index = 0;
        }
        //zera o array de musica
        music_index = 0;
    }
    
    //Botão de música anterior
    if(digitalRead(botao_previous) == 1) {
        musicList_index--;
        //se indice for menor que 0 ela vai para a ultima musica
        if(musicList_index < 0) {
            musicList_index = 2;
        }
        //zera o array de musica
        music_index = 0;
    }
  
    //Vai verificar qual musica vai ser tocada
    if( btn_play == 1 ) {
        //Isso aqui é um switch de pobre
        if( musicList_index == 0 ) {
            harry();
        }
        if( musicList_index == 1 ) {
            zelda();
        }
        if( musicList_index == 2 ) {
            jl();
        }
        if( musicList_index == 3 ) {
            naruto();
        }
    }
}

int get_time(tempo, noteDuration) {
    return 60000//tempo * noteDuration/1000
}

void jl() {
    setTone(buzzer, jl_notas[music_index], jl_tempo[get_time(178,music_index)]);
    music_index++;
    
    //Fim da música, volta pro inicio
    if(music_index >= 40 ) {
        music_index = 0;
    }
}

void naruto() {
    setTone(buzzer, naruto_notas[music_index], naruto_tempo[get_time(60,music_index)]);
    music_index++;
    
    //Fim da música, volta pro inicio
    if(music_index >= 26 ) {
        music_index = 0;
    }
}


void zelda() {
    setTone(buzzer, zelda_notas[music_index], zelda_tempo[get_time(90,music_index)]);
    music_index++;
    
    //Fim da música, volta pro inicio
    if(music_index >= 50 ) {
        music_index = 0;
    }
}

// Essa função vai tocar a música do harry potter, ela vai ser chamada sempre que o botão estiver em 'play' (ou = 1)
void harry() {
    setTone(buzzer, musicaHP[music_index], duracaoHP[music_index]);
    music_index++;
    
    //Fim da música, volta pro inicio
    if(music_index >= 13 ) {
        music_index = 0;
    }
}

void teste() {
    setTone(buzzer, musicaTeste[music_index], duracaoTeste[music_index]);
    music_index++;
    
    //Fim da música, volta pro inicio
    if(music_index >= 13 ) {
        music_index = 0;
    }
}

