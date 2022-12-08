#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

bool isVisible(auto &vc, int r, int c, int& score){
    int counter = 0, this_score = 0;
    score = 1; 

    /* if on edge - true */
    if(c == (vc[r].size() - 1) || r == (vc.size() - 1) || c == 0 || r == 0)
        return true;

    for(int i = r + 1; i < vc.size(); i++){
        this_score++;
        if(vc[i][c] >= vc[r][c]){
            counter++;
            break;
        }
    }
    
    score *= this_score;
    this_score = 0;

    for(int i = r - 1; i >= 0; i--){
        this_score++;
        if(vc[i][c] >= vc[r][c]){
            counter++;
            break;
        }
    }

    score *= this_score;
    this_score = 0;

    for(int i = c + 1; i < vc[r].size(); i++){
        this_score++;
        if(vc[r][i] >= vc[r][c]){
            counter++;
            break;
        }
    }

    score *= this_score;
    this_score = 0;

    for(int i = c - 1; i >= 0; i--){
        this_score++;
        if(vc[r][i] >= vc[r][c]){
            counter++;
            break;
        }
    }

    score *= this_score;
    return counter == 4 ? false : true;
}

int main(){
    std::fstream f("input.txt");
    std::string line {};
    int total = 0, score = 0, maxscore = 0; 
    std::vector<std::vector<int>> trees;

    while(f.peek() != EOF){
        std::getline(f, line);
        std::vector<int> tmp {};
        for(auto &e: line){
            if(e >= '0')
                tmp.push_back(e-'0');
        }
        trees.push_back(std::move(tmp));
    }
    
    for(int i = 0; i < trees.size(); i++){
        for(int j = 0; j < trees[i].size(); j++){
            auto x = isVisible(trees, i, j, score);
            if(x) total++;
            maxscore = std::max(score, maxscore);
        }
    }

    std::cout << total << std::endl;
    std::cout << maxscore << std::endl;

    return 0;
}