#include "CrossArray.hpp"
#include <iostream>
int main(){
    sjtu::CrossArray ca(2);
    int a[] = {1,2,3};
    bool ok = ca.InsertArrays(a,3);
    std::cout << "Insert ok=" << ok << "\n";
    int b[] = {4,5};
    ca.InsertArrays(b,2);
    std::cout << ca.At(0,0) << " " << ca.At(0,2) << " " << ca.At(1,1) << "\n";
    // Append to first line
    int c[] = {6,7};
    ca.AppendArrays(c,0,2);
    std::cout << ca.At(0,4) << "\n"; // should be 7
    // Double length
    ca.DoubleCrossLength();
    int d[] = {8,9,10,11};
    ca.InsertArrays(d,4); // should go to index 2
    std::cout << ca.At(2,3) << "\n";
    // copy
    sjtu::CrossArray ca2 = ca;
    std::cout << (ca.IsSame(ca2) ? "same" : "diff") << "\n";
    // WhichGreater
    sjtu::CrossArray ca3(1);
    int e[] = {100};
    ca3.InsertArrays(e,1);
    std::cout << (ca.WhichGreater(ca3).At(0,0)) << "\n"; // should be ca's first element 1
    return 0;
}
