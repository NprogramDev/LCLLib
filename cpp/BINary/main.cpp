#include "BINary.hpp"
#include <iostream>
using namespace LCLLib;
int main(int argc,char** argv){
    BINary a = BINary(23.5);
    std::cout << a.get(a.length()-2) << std::endl;
    std::cout << a.toString(true) << std::endl;
}