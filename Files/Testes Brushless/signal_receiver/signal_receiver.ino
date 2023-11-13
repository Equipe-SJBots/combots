/*
  Arduino FS-I6X Demo
  fsi6x-arduino-uno.ino
  Read output ports from FS-IA6B receiver module
  Display values on Serial Monitor
  
  Channel functions by Ricardo Paiva - https://gist.github.com/werneckpaiva/
  
  DroneBot Workshop 2021
  https://dronebotworkshop.com
*/
 
// Define Input Connections
#define CH1 3
#define CH2 5
#define CH3 6
#define CH4 9
#define CH5 10
#define CH6 11
 
/*
| CH | MIN | MAX |
| - | - | - |
| CH1 |  |  |
| CH2 |  |  |
| CH3 |  |  |
| CH4 |  |  |
| CH5 |  |  |
| CH6 |  |  |
*/

// Integers to represent values from sticks and pots
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value; 
int ch5Value;
int ch6Value;
 
int ch1Min = 1014;       // 1014/1015
int ch1Max = 1987;       // 1987
int ch2Min = 1053;       // 1053/1054
int ch2Max = 1987;       // 1987
int ch3Min = 1004;       // 1004/1005
int ch3Max = 1987;       // 1987
int ch4Min = 993;        // 993/994
int ch4Max = 1935;       // 1935/1941
int ch5Min = 993;        // 993/994
int ch5Max = 1987;       // 1987
int ch6Min = 993;        // 993/994
int ch6Max = 1987;       // 1987

int logicMin = 0;
int logicMax = 1000;

// Boolean to represent switch value
// bool ch6Value;
 
// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minFisic, int maxFisic, int minLogic, int maxLogic){
  int ch = pulseIn(channelInput, HIGH, 30000);
  // return ch;
  // if (ch < 100) return defaultValue;
  return map(ch, minFisic, maxFisic, minLogic, maxLogic);
}
 
// Read the switch channel and return a boolean value
// bool readSwitch(byte channelInput, bool defaultValue){
//   int intDefaultValue = (defaultValue)? 100: 0;
//   int ch = readChannel(channelInput, 0, 100, intDefaultValue);
//   return (ch > 50);
// }
 
void setup(){
  // Set up serial monitor
  Serial.begin(115200);
  
  // Set all pins as inputs
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
  pinMode(CH5, INPUT);
  pinMode(CH6, INPUT);
}

void myMonitor(int ch1Value, int ch2Value, int ch3Value, int ch4Value, int ch5Value, int ch6Value){
  Serial.print("Ch1: ");
  Serial.print(ch1Value);
  Serial.print("\tCh2: ");
  Serial.print(ch2Value);
  Serial.print("\tCh3: ");
  Serial.print(ch3Value);
  Serial.print("\tCh4: ");
  Serial.print(ch4Value);
  Serial.print("\tCh5: ");
  Serial.print(ch5Value);
  Serial.print("\tCh6: ");
  Serial.print(ch6Value);
  // Serial.print("\t |");
  Serial.print("\n");
}

void myPlotter(int ch1Value, int ch2Value, int ch3Value, int ch4Value, int ch5Value, int ch6Value){
  Serial.print("Ch1:");
  Serial.print(ch1Value);
  Serial.print(",Ch2:");
  Serial.print(ch2Value);
  Serial.print(",Ch3:");
  Serial.print(ch3Value);
  Serial.print(",Ch4:");
  Serial.print(ch4Value);
  Serial.print(",Ch5:");
  Serial.print(ch5Value);
  Serial.print(",Ch6:");
  Serial.print(ch6Value);
  // Serial.print("\t |");
  Serial.print("\n");
}
 
void loop() {
  
  // Get values for each channel
  ch1Value = readChannel(CH1, ch1Min, ch1Max, logicMin, logicMax);
  ch2Value = readChannel(CH2, ch2Min, ch2Max, logicMin, logicMax);
  ch3Value = readChannel(CH3, ch3Min, ch3Max, logicMin, logicMax);
  ch4Value = readChannel(CH4, ch4Min, ch4Max, logicMin, logicMax);
  ch5Value = readChannel(CH5, ch5Min, ch5Max, logicMin, logicMax);
  ch6Value = readChannel(CH6, ch6Min, ch6Max, logicMin, logicMax);
  
  // Print to Serial Monitor
  myPlotter(ch1Value, ch2Value, ch3Value, ch4Value, ch5Value, ch6Value);
  // myMonitor(ch1Value, ch2Value, ch3Value, ch4Value, ch5Value, ch6Value);

  
  // delay(500);
}