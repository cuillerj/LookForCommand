# LookForCommand
This function look for command inside a string
commands are part of a list - defined in an array commandList
function return {-1,-1} in case no matching found
function return {number,position} if found: 
				number of the matching element in the array (commandList) (in order to be used as a command)
				position in the position inside SRequest of the first byte just after the match (command) (in order to be used as parameter of the command)
