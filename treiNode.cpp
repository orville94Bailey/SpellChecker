#include "treiNode.hpp"

node::node()
{
    isWordEnd = false;
}

char node::getChar()
{
    return nodeChar;
}

void node::setChar(char ch)
{
    nodeChar = ch;
}

void node::scanWord(std::string toParse)
{
    if(toParse.length()>0)
    {
        if(transverseTo(toParse[0])==NULL)
            //next node does not exist so we create a node then
            //check to see if we have more data to parse
            //if we do we call scanWord on the last n-1 characters
            //where n is the string length
        {
            node* holder;
            holder = new node;
            holder->setChar(toParse[0]);
            nodeVector.push_back(holder);
            if(toParse.length()>1)
            {
                holder->scanWord(toParse.substr(1,toParse.length()-1));
            }
            else if(toParse.length()==0)
                //this is the last character in a word, so we mark it as being
                //the end of a word
            {
                holder->setEnd();
            }
        }
        else //next node exists so we transverse to the next node
             //and call scanWord on the last n-1 characters where n
             //is the length of the string
        {
            if(toParse.length()>1)
            {
                transverseTo(toParse[0])->scanWord(toParse.substr(1,toParse.length()-1));
            }
            else if(toParse.length()==0)
                //here we are in the last node in a word, so we mark it
                //as being the end of a word
            {
                setEnd();
            }
        }
    }
}

node* node::transverseTo(char ch)
{
    int looper;
    for(int looper = 0;looper<nodeVector.size();looper++)
    {
        if(nodeVector[looper]->getChar()==ch)
        {
            return nodeVector[looper];
        }
    }
    return NULL;
}

void node::printDict(std::string helper)
{
    helper = helper + " ";
    helper[helper.length()-1]=getChar();
    if(nodeVector.size()>0)
    {
        for(int looper = 0;looper<nodeVector.size();looper++)
        {
            nodeVector[looper]->printDict(helper);
        }
    }
    else
    {
        helper = helper + " ";
        helper[helper.length()-1] = getChar();
    }


}

void node::setEnd()
{
    isWordEnd=true;
}
