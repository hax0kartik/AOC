#include <fstream>
#include <string>
#include <iostream>
#include <queue>

int main(){
    std::fstream f("input.txt");
    std::string word {};
    std::priority_queue<int> pq;
    int count = 0;
    while(std::getline(f, word)){
        if(word.empty()){
            count = 0;
            continue;
        }
        count += std::stoi(word);
        pq.push(count);
    }
    
    int sum = 0;
    for(int i = 0; i < 3; i++){
        sum += pq.top();
        pq.pop();
    }
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}