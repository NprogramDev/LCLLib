#include "BINary.hpp"
#include <iostream>
using namespace LCLLib;
int main(int argc,char** argv){
    BINary a = BINary((unsigned int)33);
    a[3] = true;
    std::cout << (bool) a[0] << std::endl;
    std::cout << a.toString(true) << std::endl;
}