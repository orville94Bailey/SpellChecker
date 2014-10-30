#ifndef TREINODE_HPP_INCLUDED
#define TREINODE_HPP_INCLUDED

#include <vector>
#include <string>
#include <iostream>

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
    ~node();
private:
    char nodeChar;
    bool isWordEnd;
    std::vector<node*> nodeVector;
};

#endif // TREINODE_HPP_INCLUDED
