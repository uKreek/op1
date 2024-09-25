#include <iostream>
#include <cmath>

// Написать программу, которая рассчитает главную диагональ прямоугольного параллелепипеда. 
// Входные данные – стороны A,B,C (целые числа, 0 < A,B,C < 3*10^4)


int main() 
{
    short A;
    short B;
    short C;
    std::cout << "A = ";
    std::cin >> A;
    std::cout << "B = ";
    std::cin >> B;
    std::cout << "C = ";
    std::cin >> C;
    std::cout << sqrt(A*A + B*B + C*C) << std::endl;

    return 0;
}