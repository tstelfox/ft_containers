CYAN='\033[0;36m'
NC='\033[0m'
RED='\033[0;31m'
PURPLE='\033[0;35m'
GREEN='\033[0;32m'

echo -e "${CYAN}Compiling and running ft::map${NC}"
make map 
./container
./container > ft_map.txt

echo ""
echo -e "${RED}Compiling and running std::map${NC}"
make map STL=1
./container
./container > std_map.txt

echo ""
echo -e "${PURPLE}Running the difference on the two outputs: ${NC}"
diff ft_map.txt std_map.txt
if [ $? == 0 ]
then
	echo -e "${GREEN}Like your container, G${NC}"
else
	echo -e "${RED}YA DONE FUCKED SOMETHIN UP${NC}"
fi

make fclean