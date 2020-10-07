int Pin2 = 2;
int Pin3 = 3;
int Pin4 = 4;
int Pin5 = 5;
int LED1 = 8;
int LED2 = 9;
int LED3 = 10;
int LED4 = 11;
int State2 = 0;
int State3 = 0;
int State4 = 0;
int State5 = 0;

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin4, INPUT);
  pinMode(Pin5, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  State2 = digitalRead(Pin2);
  State3 = digitalRead(Pin3);
  State4 = digitalRead(Pin4);
  State5 = digitalRead(Pin5);
  //Serial.print("State2");
  //Serial.println(State2);


  if (State2 == HIGH) {
    digitalWrite (LED1, HIGH);
    Serial.println("LED BLUE");
    }
    else{
    digitalWrite (LED1, LOW);
    }

    if (State3 == HIGH) {
    digitalWrite (LED2, HIGH);
    Serial.println("LED YELLOW");
    }
    else{
    digitalWrite (LED2, LOW);
    }

    if (State4 == HIGH) {
    digitalWrite (LED3, HIGH);
    Serial.println("LED GREEN");
    }
    else{
    digitalWrite (LED3, LOW);
    }

    if (State5 == HIGH) {
    digitalWrite (LED4, HIGH);
    Serial.println("LED RED");
    }
    else{
    digitalWrite (LED4, LOW);
    }
}
