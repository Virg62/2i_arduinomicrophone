
int sensorpin = A5;
int sensorValue;
int values[120] ;
boolean sup;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    sup = false;
    for(int i=0; i<119; i++) {
      sensorValue = analogRead(sensorpin);
      values[i] = sensorValue;
    }

    for(int i=0; i<119; i++) {
      if (values[i] > 130) {
        sup = true;
      }
    }

    if (sup) {
      Serial.println("DETECT");
      digitalWrite(LED_BUILTIN, HIGH); 
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }

}
