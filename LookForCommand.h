/*
this function provide an object that look for a string ("command") inside a string ("Srequest") 
commands are part of a list - defined in an array commandList
function return {-1,-1} in case no matching found
function return {number,position} if found: 
				number of the matching element in the array (commandList) (in order to be used as a command)
				position in the position inside SRequest of the first byte just after the match (command) (in order to be used as parameter of the command)
*/

#include <Arduino.h>
#ifndef LookForCommand_h_included
#define LookForCommand_h_included
#define maxCommandNumber 100

typedef struct  {int idxCommand; int idxPos;} commandReturn;
class LookForCommand
{
public:
LookForCommand(String commandList[maxCommandNumber], int commandNumber);
int GetMaxCommandNumber();
commandReturn GetCommand(String Srequest);
};
#endif