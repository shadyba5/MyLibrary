

#include <iostream>


void swap(int* x, int* y) {

}


int main()
{

    int x = 5;
    int y = 8;

    x = x + y;
    y = x - y;
    x = x - y;


    std::cout << x << ' ' << y << std::endl;


    return 0;

}

