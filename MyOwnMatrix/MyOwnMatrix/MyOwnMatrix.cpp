#include "Matrix.h"

#include <iostream>

int main()
{
    Matrix matrix(10, 10);

    matrix.set_value(0, 0, 228);
    matrix.output();
    
    return 0;
}