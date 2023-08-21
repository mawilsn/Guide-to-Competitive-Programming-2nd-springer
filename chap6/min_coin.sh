# !/bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$parent_path"


echo creating executable from min_coin.cpp

g++ -std=c++11 -O2 -Wall min_coin.cpp -o min_coin 

echo running min coin
./min_coin