#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
int main(){
    std::fstream f("input.txt");
    std::string line {}, firstline {}, secondline{}, thirdline{};
    int total = 0; 
    while(f.peek() != EOF){
        std::getline(f, firstline);
        std::getline(f, secondline);
        std::getline(f, thirdline);
        std::string common {};
        std::string words = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        for(auto& e: words){
            if(firstline.find(e) != std::string::npos
            && secondline.find(e) != std::string::npos 
            && thirdline.find(e) != std::string::npos){
                common += e;
            }
        }
        for(auto &e : common){
            if(e > 'A' && e < 'a'){
                total += (e - 'A') + 1 + 26;
            } else {
                total += (e - 'a') + 1;
            }
        }
    }
    std::cout << total << std::endl;
    return 0;
}