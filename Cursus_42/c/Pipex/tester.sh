#!/bin/bash

BLUE='\033[1;94m'
RED="\033[1;31m" 
GREEN="\033[1;32m"

make re

./pipex tfile cat cat P
< tfile cat | cat > outfile
diff P outfile > /dev/null
make re_bonus

if [ $? -eq 0 ];
	then echo "${GREEN}[OK]  ${BLUE}tfile cat P"
else
	echo "${RED}[KO]  ${BLUE}tfile cat P"
fi

rm P
rm outfile
./pipex tfile cat cat cat cat cat P
< tfile cat | cat | cat | cat | cat > outfile
diff P outfile > /dev/null

if [ $? -eq 0 ];
	then echo "${GREEN}[OK]  ${BLUE}tfile cat cat cat cat cat P"
else
	echo "${RED}[KO]  ${BLUE}tfile cat cat cat cat cat P"
fi

./pipex tfile "echo o" "echo o" "echo o" "echo o" "echo o"  P
< tfile echo o | echo o | echo o | echo o | echo o > outfile
diff P outfile > /dev/null

if [ $? -eq 0 ];
	then echo "${GREEN}[OK]  ${BLUE}tfile echo o echo o echo o echo o echo o P"
else
	echo "${RED}[KO]  ${BLUE}tfile echo o echo o echo o echo o echo o P"
fi

rm P
rm outfile
./pipex tfile cat "echo o" P
< tfile cat | echo o > outfile
diff P outfile > /dev/null

if [ $? -eq 0 ];
	then echo "${GREEN}[OK]  ${BLUE}tfile cat 'echo o' P"
else
	echo "${RED}[KO]  ${BLUE}tfile cat 'echo o' P"
fi

rm P
rm outfile
./pipex tfile cat "not-existing" P
< tfile cat | not-existing > outfile
diff P outfile > /dev/null

if [ $? -eq 0 ];
	then echo "${GREEN}[OK]  ${BLUE}tfile cat 'not-existing' P"
else
	echo "${RED}[KO]  ${BLUE}tfile cat | not-existing > outfile"
fi

rm P
rm outfile
./pipex tfile cat cat "echo o" "not-existing" P
< tfile cat | cat | echo o | not-existing > outfile
diff P outfile > /dev/null

if [ $? -eq 0 ];
	then echo "${GREEN}[OK]  ${BLUE}tfile cat cat echo o'not-existing' P"
else
	echo "${RED}[KO]  ${BLUE}tfile | cat | cat | echo o | | not-existing > outfile"
fi

rm P
rm outfile
./pipex tfile "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" "cat -E" P
< tfile cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E | cat -E > outfile
diff P outfile > /dev/null

if [ $? -eq 0 ];
	then echo "${GREEN}[OK]  ${BLUE}tfile cat * 20 P"
else
	echo "${RED}[KO]  ${BLUE}tfile cat * 20 > outfile"
make fclean
fi
