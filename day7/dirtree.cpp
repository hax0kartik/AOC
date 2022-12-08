#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

struct Node{
    long size;
    std::string path;
    std::list<Node*> subdirs;
    Node *parent;
    
    Node(const std::string &path, int sz = 0){
        this->path = path;
        size = sz;
        parent = nullptr;
    }

    Node(const std::string &path, Node *parent, int sz = 0){
        this->path = path;
        this->parent = parent;
        size = sz;
    }

    int GetTotal(int max){
        int total = size >= max ? 0 : size;
        std::for_each(subdirs.begin(), subdirs.end(), [&](Node *e){ total += e->GetTotal(max); });
        return total;
    }

    int FindDirectory(int t, int m){
        int min = size >= m ? size : t;
        std::for_each(subdirs.begin(), subdirs.end(), [&](Node *e){ 
            min = std::min(min, e->FindDirectory(t, m)); 
        });
        return min;
    }
};

class DirectoryTree{
    public:
        DirectoryTree(const std::string &root){
            m_root = new Node(root);
            m_curr = m_root;
        }

        void AddSize(long size){
            m_curr->size += size;
            Node *temp = m_curr;
            while(temp->parent != nullptr){
                temp->parent->size += size;
                temp = temp->parent;
            }
        }

        void AddNodeAndChangeTo(const std::string &s){
            auto* node = new Node(s, m_curr);
            m_curr->subdirs.push_back(node);
            m_curr = node;
        }

        void GoBack(){
            m_curr = m_curr->parent;
        }

        void Part1(const int max){
            std::cout << "P1: " << m_root->GetTotal(max) << std::endl;
        }

        void Part2(const int total, const int minimum_required){
            int min_to_delete = minimum_required - (total - m_root->size);
            std::cout << "P2: " << m_root->FindDirectory(total, min_to_delete) << std::endl;
        }

    private:
        Node *m_root;
        Node *m_curr;
};

int main(){
    std::fstream f("input.txt");
    int total = 0; 
    std::string word {};
    f >> word;
    DirectoryTree *tree;
    do{
        /* command */
        std::string cmd {};
        f >> cmd;
        if(cmd == "cd"){
            /* cd */
            f >> word;
            if(word == "/")
                tree = new DirectoryTree(word);
            else if(word == "..")
                tree->GoBack();
            else
                tree->AddNodeAndChangeTo(word);
            f >> word;
        } else {
            /* ls */
            word = "";
            while(word != "$" && f.peek() != EOF){
                f >> word;
                if(word == "dir") {
                    f >> word;
                } else if(word != "$") {
                    tree->AddSize(std::stol(word));
                    f >> word;
                }
            }
        }
    } while(word == "$" && f.peek() != EOF);
    tree->Part1(100000);
    tree->Part2(70000000, 30000000);
    return 0;
}