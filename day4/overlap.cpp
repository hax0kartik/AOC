#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

bool isWithin(int a, int b, int c, int d){
    if(a <= c && d <= b)
        return true;
    return false; 
}

int main(){
    std::fstream f("input.txt");
    std::string line {}, firstline {}, secondline{}, thirdline{};
    int total = 0; 
    while(f.peek() != EOF){
        std::getline(f, line);
        std::stringstream ss(line);
        std::string firsthalf {}, secondhalf {};
        std::getline(ss, firsthalf, ',');
        std::getline(ss, secondhalf);
        int minOfHalf1 = std::stoi(firsthalf.substr(0, firsthalf.find_first_of('-')));
        int maxOfHalf1 = std::stoi(firsthalf.substr(firsthalf.find_first_of('-') + 1));

        int minOfHalf2 = std::stoi(secondhalf.substr(0, secondhalf.find_first_of('-')));
        int maxOfHalf2 = std::stoi(secondhalf.substr(secondhalf.find_first_of('-') + 1));

        if(isWithin(minOfHalf1, maxOfHalf1, minOfHalf2, maxOfHalf2) || isWithin(minOfHalf2, maxOfHalf2, minOfHalf1, maxOfHalf1)){
            total++;
        }
    }
    std::cout << total << std::endl;
    return 0;
}