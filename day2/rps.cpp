#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

int main(){
    std::fstream f("input.txt");
    std::string line {};
    int total = 0;
    while(std::getline(f, line)){
        std::stringstream ss(line);
        std::string opponent {};
        ss >> opponent;
        std::string choice {};
        ss >> choice;
        std::cout << opponent << " " << choice << std::endl;
        /* find distance from ascii of A */
        int oppscore = (opponent[0] - 'A');
        int myscore = 0;
        switch(choice[0]){
            case 'X': /* lose */
                myscore = (oppscore - 1 < 0) ? 2 : oppscore - 1;  
                break;
            case 'Y': /* tie */
                myscore = oppscore;
                break;
            case 'Z': /* win */
                myscore = (oppscore + 1) % 3;
                break;
        }
        total += myscore + 1;
        if(myscore == ((oppscore + 1) % 3)){
            total += 6;
        } else if(myscore == oppscore){
            total += 3;
        }
    }
    std::cout << total << std::endl;
    return 0;
}