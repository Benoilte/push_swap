RED="\033[0;31m"
GREEN="\033[0;32m"
NONE="\033[0m"


echo ""
echo "$GREEN STANDARD WORKING INPUT $NONE"
echo ""
echo "./push_swap 1 3 5 +9 20 -4 50 60 04 08 => $GREEN OK $NONE"
./push_swap 1 3 5 +9 20 -4 50 60 04 08

echo ""
echo "./push_swap '3 4 6 8 9 74 -56 +495' => $GREEN OK $NONE"
./push_swap "3 4 6 8 9 74 -56 +495"

echo ""
echo "./push_swap '95 99 -9 10 9' => $GREEN OK $NONE"
./push_swap "95 99 -9 10 9"

echo ""
echo "$RED STANDARD ERROR INPUT $NONE"
echo ""
echo "./push_swap 1 3 dog 35 80 -3 => $RED ERROR $NONE"
./push_swap 1 3 dog 35 80 -3

echo ""
echo "./pushswap a => $RED ERROR $NONE"
./push_swap a

echo ""
echo "./push_swap 1 2 3 5 67b778 947 => $RED ERROR $NONE"
./push_swap 1 2 3 5 67b778 947

echo ""
echo "./push_swap ' 12 4 6 8 54fhd 4354' => $RED ERROR $NONE"
./push_swap " 12 4 6 8 54fhd 4354"

echo ""
echo "./push_swap 1 --    45 32 => $RED ERROR $NONE"
./push_swap 1 --    45 32

echo ""
echo "$RED DUPLICATE ERROR INPUT $NONE"
echo ""
echo "./push_swap 1 3 58 9 3 => $RED ERROR $NONE"
./push_swap 1 3 58 9 3

echo ""
echo "./push_swap 3 03 => $RED ERROR $NONE"
./push_swap 3 03

echo ""
echo "./push_swap ' 49 128     50 38   49' => $RED ERROR $NONE"
./push_swap " 49 128     50 38   49"

echo ""
echo "$GREEN INT_MAX INT_MIN WORKING INPUT $NONE"
echo ""
echo "./push_swap 2147483647 2 4 7 => $GREEN OK $NONE"
./push_swap 2147483647 2 4 7

echo ""
echo "./push_swap 99 -2147483648 23 545 => $GREEN OK $NONE"
./push_swap 99 -2147483648 23 545

echo ""
echo "./push_swap '2147483647 843 56544 24394' => $GREEN OK $NONE"
./push_swap "2147483647 843 56544 24394"

echo ""
echo "./push_swap '2147483647 843 56544 24394' => $GREEN OK $NONE"
./push_swap "2147483647 843 56544 24394"

echo ""
echo "$RED INT_MAX INT_MIN ERROR INPUT $NONE"
echo ""

echo ""
echo "./push_swap 54867543867438 3 => $RED ERROR $NONE"
./push_swap 54867543867438 3

echo ""
echo "./push_swap -2147483647765 4 5 => $RED ERROR $NONE"
./push_swap -2147483647765 4 5

echo ""
echo "./push_swap "214748364748385 28 47 29" => $RED ERROR $NONE"
./push_swap "214748364748385 28 47 29"

echo ""
echo "$GREEN MIXED STRING INT WORKING INPUT $NONE"
echo ""
echo "./push_swap '1 2 4 3' 76 90 '348' 05 => $GREEN OK $NONE"
./push_swap "1 2 4 3" 76 90 "348" 05