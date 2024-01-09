RED="\033[0;31m"
GREEN="\033[0;32m"
NONE="\033[0m"
ARG="4 67 3 87 23 1304 42 34 8456 4587945 41258 1"

for i in {1..100}; do 
	./push_swap $ARG | ./checker $ARG
done
