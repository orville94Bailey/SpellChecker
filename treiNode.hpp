#ifndef TREINODE_HPP_INCLUDED
#define TREINODE_HPP_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class node
{
public:
    node();
    char getChar();
    void setChar(char);
    void scanWord(std::string);
    node* transverseTo(char);
    void printDict(std::string);
    void setEnd();
    void readFile(std::string);
    ~node();
private:
    char nodeChar;
    bool isWordEnd;
    std::vector<node*> nodeVector;
};

#endif // TREINODE_HPP_INCLUDED
