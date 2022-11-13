
//Defines
#define CLK 2
#define DT 3
#define SW 4
#define ledPin 13      // the number of the LED pin


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int currentStateCLK;
int currentStateDT;

int encoder0Pos = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(SW, INPUT_PULLUP);
  pinMode(CLK,INPUT);
  digitalWrite(CLK, HIGH);    
  pinMode(DT,INPUT);
  digitalWrite(DT, HIGH);

  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
}


void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(SW);

  
  // Show the state of pushbutton on serial monitor
  Serial.print("BTN: ");
  Serial.println(buttonState);
  Serial.print("encoder0Pos: ");
  Serial.print(encoder0Pos);
  Serial.println();

  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  // Added the delay so that we can see the output of button
  delay(100);
}

void doEncoder() {
  /* If pinA and pinB are both high or both low, it is spinning
     forward. If they're different, it's going backward.

     For more information on speeding up this process, see
     [Reference/PortManipulation], specifically the PIND register.
  */
  if (digitalRead(CLK) == digitalRead(DT)) {
    encoder0Pos--;
  } else {
    encoder0Pos++;
  }

  //Serial.println (encoder0Pos, DEC);
}
