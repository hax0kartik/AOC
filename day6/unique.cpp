#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
int main(){
    std::fstream f("input.txt");
    int total = 0; 
    std::stringstream buffer;
    buffer << f.rdbuf();
    int i = 0, scan = 0;
    std::unordered_map <char, int> map {};
    for(; i < buffer.str().size(); i++){
        if(map.find(buffer.str()[i]) != map.end()){
                i = i - scan;
                map.clear();
                scan = 0;
            } else {
                map[buffer.str()[i]]++;
                scan++;
            }
        if(scan == 14) break;
    }
    std::cout << (i+1) << std::endl;
    return 0;
}