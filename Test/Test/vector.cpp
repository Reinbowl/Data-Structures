#include <iostream>
#include <vector>

using namespace std;

int main()

{

    int* ptr = new int;

    int* ptr2 = ptr;

    delete ptr2;

    return 0;

}