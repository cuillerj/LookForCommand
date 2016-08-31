#include <LookForCommand.h> // include the function
#define commandnumber 11    // define the number of defined command
String commandList[commandnumber] = {"SSID1=", "PSW1=", "SSID2=", "PSW2=", "ShowWifi", "Restart", "DebugOn", "DebugOff", "ScanWifi", "SSID=1", "SSID=2"};
LookForCommand Command1 (commandList, commandnumber);   // define the object

void setup() {
  Serial.begin(38400);
  // put your setup code here, to run once:
  Serial.println(Command1.GetMaxCommandNumber());   // get the maximum supported commands
}

void loop() {
  // put your main code here, to run repeatedly:
  commandReturn rc = Command1.GetCommand("PSW2=");  // loook for a string
  Serial.println(rc.idxCommand);          // return the command number in string (-1 not found)
  Serial.println(rc.idxPos);              // return the position in string just after the end of the tring to eventualy get parameter
  delay(5000);


}
