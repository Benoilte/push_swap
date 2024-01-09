
RED="\033[0;31m"
GREEN="\033[0;32m"
NONE="\033[0m"
ARG=$1

echo ""
echo "$GREEN Combinaisons pour 1 2 3 4 : $NONE"
echo ""

echo "./push_swap 1 2 3 4 => 1 2 3 4"
./push_swap 1 2 3 4
./push_swap 1 2 3 4 | ./checker 1 2 3 4

echo ""
echo "./push_swap 1 2 4 3 => 1 2 3 4"
./push_swap 1 2 4 3
./push_swap 1 2 4 3 | ./checker 1 2 4 3

echo ""
echo "./push_swap 1 3 2 4 => 1 2 3 4"
./push_swap 1 3 2 4
./push_swap 1 3 2 4 | ./checker 1 3 2 4

echo ""
echo "./push_swap 1 3 4 2 => 1 2 3 4"
./push_swap 1 3 4 2
./push_swap 1 3 4 2 | ./checker 1 3 4 2

echo ""
echo "./push_swap 1 4 2 3 => 1 2 3 4"
./push_swap 1 4 2 3
./push_swap 1 4 2 3 | ./checker 1 4 2 3

echo ""
echo "./push_swap 1 4 3 2 => 1 2 3 4"
./push_swap 1 4 3 2
./push_swap 1 4 3 2 | ./checker 1 4 3 2

echo ""
echo "./push_swap 2 1 3 4 => 1 2 3 4"
./push_swap 2 1 3 4
./push_swap 2 1 3 4 | ./checker 2 1 3 4

echo ""
echo "./push_swap 2 1 4 3 => 1 2 3 4"
./push_swap 2 1 4 3
./push_swap 2 1 4 3 | ./checker 2 1 4 3

echo ""
echo "./push_swap 2 3 1 4 => 1 2 3 4"
./push_swap 2 3 1 4
./push_swap 2 3 1 4 | ./checker 2 3 1 4

echo ""
echo "./push_swap 2 3 4 1 => 1 2 3 4"
./push_swap 2 3 4 1
./push_swap 2 3 4 1 | ./checker 2 3 4 1

echo ""
echo "./push_swap 2 4 1 3 => 1 2 3 4"
./push_swap 2 4 1 3 
./push_swap 2 4 1 3 | ./checker 2 4 1 3

echo ""
echo "./push_swap 2 4 3 1 => 1 2 3 4"
./push_swap 2 4 3 1
./push_swap 2 4 3 1 | ./checker 2 4 3 1

echo ""
echo "./push_swap 3 1 2 4 => 1 2 3 4"
./push_swap 3 1 2 4
./push_swap 3 1 2 4 | ./checker 3 1 2 4

echo ""
echo "./push_swap 3 1 4 2 => 1 2 3 4"
./push_swap 3 1 4 2
./push_swap 3 1 4 2 | ./checker 3 1 4 2

echo ""
echo "./push_swap 3 2 1 4 => 1 2 3 4"
./push_swap 3 2 1 4
./push_swap 3 2 1 4 | ./checker 3 2 1 4

echo ""
echo "./push_swap 3 2 4 1 => 1 2 3 4"
./push_swap 3 2 4 1
./push_swap 3 2 4 1 | ./checker 3 2 4 1

echo ""
echo "./push_swap 3 4 1 2 => 1 2 3 4"
./push_swap 3 4 1 2
./push_swap 3 4 1 2 | ./checker 3 4 1 2

echo ""
echo "./push_swap 3 4 2 1 => 1 2 3 4"
./push_swap 3 4 2 1
./push_swap 3 4 2 1 | ./checker 3 4 2 1

echo ""
echo "./push_swap 4 1 2 3 => 1 2 3 4"
./push_swap 4 1 2 3
./push_swap 4 1 2 3 | ./checker 4 1 2 3

echo ""
echo "./push_swap 4 1 3 2 => 1 2 3 4"
./push_swap 4 1 3 2
./push_swap 4 1 3 2 | ./checker 4 1 3 2

echo ""
echo "./push_swap 4 2 1 3 => 1 2 3 4"
./push_swap 4 2 1 3 
./push_swap 4 2 1 3 | ./checker 4 2 1 3

echo ""
echo "./push_swap 4 2 3 1 => 1 2 3 4"
./push_swap 4 2 3 1
./push_swap 4 2 3 1 | ./checker 4 2 3 1

echo ""
echo "./push_swap 4 3 1 2 => 1 2 3 4"
./push_swap 4 3 1 2
./push_swap 4 3 1 2 | ./checker 4 3 1 2

echo ""
echo "./push_swap 4 3 2 1 => 1 2 3 4"
./push_swap 4 3 2 1
./push_swap 4 3 2 1 | ./checker 4 3 2 1

if [ "$1" != "" ]; then
	echo ""
	echo "./push_swap $ARG"
	./push_swap $ARG
	./push_swap $ARG | ./checker $ARG
fi

echo ""
echo "Fin des combinaisons."
