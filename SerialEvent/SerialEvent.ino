String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  if (Serial1.available()) {
  
    // get the new byte:
    char inChar = (char)Serial1.read();
    Serial.println(inChar);
    // add it to the inputString:
   
  }  
  
  // // print the string when a newline arrives:
  // if (stringComplete) {
  //   Serial.println(inputString);
  //   // clear the string:
  //   inputString = "";
  //   stringComplete = false;
  // }
}