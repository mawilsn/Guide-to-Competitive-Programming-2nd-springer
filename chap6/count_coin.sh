# !/bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$parent_path"


echo creating executable from count_coin_1d.cpp

g++ -std=c++11 -O2 -Wall count_coin_1d.cpp -o count_coin_1d 

echo running min coin
./count_coin_1d