#!/bin/bash

CYAN='\033[0;36m'
NC='\033[0m'
RED='\033[0;31m'
PURPLE='\033[0;35m'
GREEN='\033[0;32m'

echo -e "${PURPLE}What container you wannae test for output?\n{speed}{map}{vector}{stack}${NC}"
read var
if [ $var != map ] && [ $var != stack ] && [ $var != vector ] && [ $var != speed ]
then
	echo -e "${RED}THAT IS NO CONTAINER, BROTHER${NC}"
	exit
fi

if [ $var == speed ]
then
	echo -e "${GREEN}SPEEEEEEEEEEED TEEEEEEEEST\nProvide a seed${NC}"
	read seed
	echo -e "${CYAN}Compiling and running std::$var${NC}"
	make $var STL=1
	./container $seed
	echo -e "${RED}Compiling and running ft::$var${NC}"
	make $var 
	./container $seed
	make fclean
	exit
fi

echo -e "${CYAN}Compiling and running ft::$var${NC}"
make $var 
./container
./container > ft_$var.txt

echo ""
echo -e "${RED}Compiling and running std::$var${NC}"
make $var STL=1
./container
./container > std_$var.txt

echo ""
echo -e "${PURPLE}Running the difference on the two outputs: ${NC}"
diff ft_$var.txt std_$var.txt
if [ $? == 0 ]
then
	echo -e "${GREEN}Like your container, G${NC}"
else
	echo -e "${RED}YA DONE FUCKED SOMETHIN UP${NC}"
fi

make fclean

