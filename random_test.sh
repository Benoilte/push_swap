RED="\033[0;31m"
GREEN="\033[0;32m"
NONE="\033[0m"
ARG=$1

echo ""
echo "$GREEN RANDOM INT INPUT $NONE"
echo ""
echo ""
echo "./push_swap 30 number"
./push_swap 1749 1445 1911 1599 1030 751 1260 1686 1231 456 1383 785 1725 499 598 870 1103 1304 1475 1856 1947 1332 1532 1206 1934 1788 1889 1065 27 1699

echo ""
echo "./push_swap 10 number"
./push_swap 345 1874 1228 722 976 1433 1506 1995 1847 509


# echo ""
# echo "./push_swap 100 number"
# ./push_swap 1656 1108 732 1947 1164 821 1334 1758 632 89 1197 1771 1939 1427 383 1755 788 1237 1562 1535 1753 1256 1241 1309 443 61 276 1122 868 297 1560 1046 890 602 1297 1244 1553 903 828 1007 85 612 1722 1459 1777 1565 1394 1180 1543 394 1202 1229 1021 1725 835 1386 1116 1105 1525 1352 1303 1269 380 1144 1263 1828 1711 1943 1759 78 1606 477 479 1282 623 1130 440 568 1861 1979 597 1670 702 1564 1578 1070 1974 1680 363 1697 861 1806 1723 1254 619 94 1778 1873 819 1055 1751 1908 662



if [ "$1" != "" ]; then
	echo ""
	echo "./push_swap $ARG"
	./push_swap $ARG
fi