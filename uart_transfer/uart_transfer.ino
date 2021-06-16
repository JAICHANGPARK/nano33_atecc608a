

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int buffCnt = 0;
uint8_t transBuff[128] = {};
int sum = 0;

void setup() {
  // initialize serial:
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {

  if (Serial.available()) {
    char inChar = (char)Serial.read();
    switch (inChar) {
      case '0': {
        Serial.println("Check Robot Status");
        transBuff[buffCnt++] = 0x55; // sop
        transBuff[buffCnt++] = 0x55; // sop
        transBuff[buffCnt++] = 0x06; // cmd
        transBuff[buffCnt++] = 0x00; // cmd
        transBuff[buffCnt++] = 0x00; // ml 
        transBuff[buffCnt++] = 0x00; // ml
        transBuff[buffCnt++] = 0x00; // 
        transBuff[buffCnt++] = 0x00; //
        
        for(int i = 0; i < buffCnt; i++){
          sum += transBuff[i];
        }
        transBuff[buffCnt++] = sum >> 8; //
        transBuff[buffCnt++] = sum & 0xFF; //

        Serial1.write(transBuff, buffCnt);
        for(int i = 0; i < buffCnt ; i++){
          Serial.print(transBuff[i], HEX);
        }
        Serial.println();
        break;
      }
       
      case '1':
        break;
      case '2':
        break;
      case '3':
        break;
      case '4':
        break;
      default:
        break;
    }
  }

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