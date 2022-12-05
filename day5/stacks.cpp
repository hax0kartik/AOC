#include <cstring>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>

class Solution{
    public:
        std::vector<std::string> BreakIntoBrackets(const std::string &line){
            std::vector<std::string> res{};
            for(int i = 0; i < line.size(); i+=4){
                res.push_back(line.substr(i, 3));
            }
            return res;
        }

        void ReadInputFile(){
            std::fstream f("input.txt");
            std::string line {};
            while(f.peek() != EOF){
                std::getline(f, line);
                if(line.find("[") != std::string::npos){
                    auto res = BreakIntoBrackets(line);
                    if(m_stacks.size() == 0) m_stacks.resize(res.size());
                    for(int i = 0; i < res.size(); i++){
                        if(res[i][0] == '['){
                            m_stacks[i].push_back(res[i][1]);
                        }
                    }
                } else if (line.find("move") != std::string::npos){
                    int n = 0, from = 0, to = 0;
                    std::sscanf(line.c_str(), "move %d from %d to %d", &n, &from, &to);
                    std::vector <int> elems;
                    for(int i = 0; i < n; i++){
                        auto elem = m_stacks[from - 1].front();
                        m_stacks[from - 1].pop_front();
                        elems.push_back(elem);
                    }

                    for(int i = 0; i < elems.size(); i++){
                        m_stacks[to - 1].push_front(elems[elems.size() - i - 1]);
                    }
                }
            }

            std::string output {};
            for(int i = 0; i < m_stacks.size(); i++){
                output += m_stacks[i].front();
            }
            std::cout << output << std::endl;
        }
    

    private:
        std::vector<std::list<char>> m_stacks;
};

int main(){
    Solution s;
    s.ReadInputFile();
    return 0;
}