#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

cd ../

make

testFiles()
{
	./Sed_is_for_losers test/$1 "$2" "$3"
	echo -e "\n$GREEN->$1, replace $2 $3 $RESET"
	echo -e "  $RED"Original file :$RESET
	cat test/$1
	echo -e "  $RED"Replaced file :$RESET
	cat test/$1.replace
}

testFiles noNewLine 42 84
testFiles shuffle "Hello 42" ""
testFiles multiple 42 84

make fclean
#rm -f test/*.replace