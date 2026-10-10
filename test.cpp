#include "CrossArray.hpp"
#include <iostream>
int main(){
    sjtu::CrossArray ca(2);
    int a[] = {1,2,3};
    ca.InsertArrays(a,3);
    int b[] = {4,5};
    ca.InsertArrays(b,2);
    std::cout << ca.At(0,1) << " " << ca.At(1,0) << std::endl;
    sjtu::CrossArray ca2 = ca;
    std::cout << (ca.IsSame(ca2) ? "same" : "diff") << std::endl;
    return 0;
}
