/* The Simpons' Theme Song
 * By Lita Cho
 * Music by Danny Elfman
 * 
 * Note: A lot of this code was taken from the Melody example. 
 *      This can be found here: http://www.arduino.cc/en/Tutorial/Melody
 *
 * This example uses a piezo speaker to play melodies.  It sends
 * a square wave of the appropriate frequency to the piezo, generating
 * the corresponding tone. The LED also lights up when a tone is being played.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note     frequency     period     timeHigh
 * F(#)         185 Hz          5406    2703
 * G            196 Hz          5102    2551
 * A            220 Hz          4546    2273
 * c             261 Hz             3830     1915     
 * d             294 Hz             3400     1700     
 * e             329 Hz             3038     1519     
 * f             349 Hz             2864     1432
 * s (f#)     370 Hz          2701    1351
 * g             392 Hz             2550     1275     
 * a             440 Hz             2272     1136     
 * b             493 Hz             2028    1014    
 * C            523 Hz            1912     956
 *
 */
  
int speakerPin = 12  ;

int length = 13; // the number of notes
char notes[] = "cesagecAFFFG "; // a space represents a rest
int beats[] = { 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 2, 5 };
int tempo = 100;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'F', 'G', 'A', 'c', 'd', 'e', 'f', 's', 'g', 'a', 'b', 'C' };
  int tones[] = { 2703, 2551, 2273, 1915, 1700, 1519, 1432, 1351, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 12; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // pause between notes
    delay(tempo / 2); 
  }
}
