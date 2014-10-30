#include "treiNode.hpp"

int main()
{
    std::string fileName;

    node controller;
    controller.setChar(' ');
    std::cout<<"Enter a file to read from: ";
    std::cin>>fileName;
    controller.readFile(fileName);
    //controller.printDict("");
    return 0;
}
