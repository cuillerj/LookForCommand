#include <Arduino.h>
#include "LookForCommand.h"
int _commandNumber;
String _commandList[maxCommandNumber];

LookForCommand::LookForCommand (String commandList[maxCommandNumber], int commandNumber)
	{
		_commandNumber=commandNumber;
		for (int i=0;i<min(_commandNumber,maxCommandNumber);i++)
		{
			_commandList[i]=commandList[i];
		}
		
	}

int LookForCommand::GetMaxCommandNumber() 
{
	return maxCommandNumber;
}

commandReturn LookForCommand::GetCommand(String Srequest) 

{
  commandReturn rc = { -1, -1};
  Serial.print("request:");
  Serial.println(Srequest);
  for (int cmdIdx = 0; cmdIdx < _commandNumber; cmdIdx++)
  {
    String needle = _commandList[cmdIdx];
    if (Srequest.length() >= needle.length() ) {
      for (int posIdx = 0; (posIdx < Srequest.length() - needle.length() + 1); posIdx++) {
        if (Srequest.substring(posIdx, needle.length() + posIdx) == needle) {
          commandReturn rc = {cmdIdx, posIdx + needle.length()};
          return (rc);
        }
      }
    }
  }
  return (rc);
}
