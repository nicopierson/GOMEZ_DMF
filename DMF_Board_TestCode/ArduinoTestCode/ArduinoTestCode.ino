int control = 0;   // for incoming serial data

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Ready.");

DDRD = DDRD | B11111100;  // this is safer as it sets pins 2 to 7 as outputs
DDRB = DDRB | B00000111;  // this is safer as it sets pins 8 to 10 as outputs

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
                // read the incoming byte:
                control = Serial.read();

                // say what you got:
                if (control >= 49 && control <=57){
                Serial.print("I received: ");
                Serial.println(control, DEC);
                }
                else{
                  Serial.println("Invalid key pressed.");
                }
        }

if (control <= '9' && control >= '1') {
       switch(control) {
        case '1':
          PORTD = B00000100;
          break;
        case '2':
          PORTD = B00001000;
          break;
        case '3':
          PORTD = B00010000;
          break;
        case '4':
          PORTD = B00100000;
          break;
        case '5':
          PORTD = B01000000;
          break;
        case '6':
          PORTD = B10000000;
          break;
        case '7':
          PORTB = B00000001;
          break;
        case '8':
          PORTB = B00000010;
          break;
        case '9':
          PORTB = B00000100;
          break;
       }
}


}
