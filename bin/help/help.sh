#!/bin/bash

echo "WORK IN PROGRESS"

echo "What this is"
echo "___________________________________________________________________________________________"
echo ""
echo "        This piece of software is a fully funtioning Computer Algebra System that is used"
echo "        directly in the command line. There is support for nearly all algebraic problems"
echo "        such as simplification and factoring to graphing using unicode characters. The "
echo "        CAS takes a string of modified form of LaTeX and an argument."
echo ""

echo "For further information use the following commands:"
echo "        For more information of commands, type COMMANDS"
echo "        For more information on syntax, type SYNTAX"
echo "        To quit the help screen type QUIT-HELP"

while true;
do
    echo ""
    echo "COMMAND:"
    read COMMAND
    echo ""
    if [ "$COMMAND" = "COMMANDS" ]
    then
        echo "COMMANDS PLACEHOLDER"
    elif [ "$COMMAND" = "SYNTAX" ]
    then
        echo "SYNTAX PLACEHOLDER"
    elif [ "$COMMAND" = "QUIT-HELP" ]
    then
        break
    fi
done

echo ""