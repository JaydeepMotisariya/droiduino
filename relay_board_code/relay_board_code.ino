
const int relayPin1 = 8; // forward
const int relayPin2 = 9; // reverse
const int relayPin3 = 10; // turn left
const int relayPin4 = 11; // turn right
String cmdText; // Command message from Android
int cmdInt;


void setup() {
  // Pin and RC Channel setup
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  digitalWrite(relayPin3, HIGH);
  digitalWrite(relayPin4, HIGH);

  // Bluetooth Setup
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {

  // Read command from Android
  if (Serial.available() > 0){
    cmdText = Serial.readString();
    cmdInt = cmdText.toInt();
    Serial.println(cmdText);
  }

  if (cmdText == "<forward>"){
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, HIGH);
  } else {
      if (cmdText == "<reverse>"){
        digitalWrite(relayPin1, HIGH);
        digitalWrite(relayPin2, LOW);
      } else {
          if (cmdText == "<stop moving>"){
            digitalWrite(relayPin1, HIGH);
            digitalWrite(relayPin2, HIGH);
        }
    }
  }

  if (cmdText == "<left>"){
    digitalWrite(relayPin3, LOW);
    digitalWrite(relayPin4, HIGH);
  } else {
      if (cmdText == "<right>"){
        digitalWrite(relayPin3, HIGH);
        digitalWrite(relayPin4, LOW);
      } else {
          if (cmdText == "<stop turning>"){
            digitalWrite(relayPin3, HIGH);
            digitalWrite(relayPin4, HIGH);
        }
    }
  }

//  switch(cmdInt){
//    case 123:
//      digitalWrite(relayPin1, LOW);
//      digitalWrite(relayPin2, HIGH);
//      break;
//    case 345:
//      digitalWrite(relayPin1, HIGH);
//      digitalWrite(relayPin2, LOW);
//      break;
//    case 567:
//      digitalWrite(relayPin3, LOW);
//      digitalWrite(relayPin4, HIGH);
//      break;  
//    case 789:
//      digitalWrite(relayPin3, HIGH);
//      digitalWrite(relayPin4, LOW);
//      break;  
//    case 1000000:
//      digitalWrite(relayPin1, HIGH);
//      digitalWrite(relayPin2, HIGH);
//      break;
//    
//  }
  
//  digitalWrite(relayPin1, LOW);
//  digitalWrite(relayPin2, HIGH);
//  digitalWrite(relayPin3, HIGH);
//  digitalWrite(relayPin4, HIGH);
//  delay(1000);
//  digitalWrite(relayPin1, HIGH);
//  digitalWrite(relayPin2, LOW);
//  digitalWrite(relayPin3, HIGH);
//  digitalWrite(relayPin4, HIGH);
//  delay(1000);
//  digitalWrite(relayPin1, HIGH);
//  digitalWrite(relayPin2, HIGH);
//  digitalWrite(relayPin3, LOW);
//  digitalWrite(relayPin4, HIGH);
//  delay(1000);
//  digitalWrite(relayPin1, HIGH);
//  digitalWrite(relayPin2, HIGH);
//  digitalWrite(relayPin3, HIGH);
//  digitalWrite(relayPin4, LOW);
//  delay(1000);
  

}
