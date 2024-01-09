RED="\033[0;31m"
GREEN="\033[0;32m"
NONE="\033[0m"
ARG=$1

echo ""
echo "$GREEN RANDOM INT INPUT $NONE"
echo ""
ARG1="1749 1445 1911 1599 1030 751 1260 1686 1231 456 1383 785 1725 499 598 870 1103 1304 1475 1856 1947 1332 1532 1206 1934 1788 1889 1065 27 1699"
echo ""
echo "./push_swap 30 number"
echo "$GREEN"; ./push_swap $ARG1 | wc -l; echo "$NONE"
./push_swap $ARG1 | ./checker $ARG1

ARG2="345 1874 1228 722 976 1433 1506 1995 1847 509"
echo ""
echo "./push_swap 10 number"
echo "$GREEN"; ./push_swap $ARG2 | wc -l; echo "$NONE"
./push_swap $ARG2 | ./checker $ARG2


if [ "$1" != "" ]; then
	echo ""
	echo "./push_swap $ARG"
	./push_swap $ARG
fi
