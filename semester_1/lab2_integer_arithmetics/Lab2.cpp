
#include <iostream>
#include <cmath>
int main()
{
    int a;
    std::cout << "Enter a: ";
    std::cin >> a;
    int b;
    std::cout << "Enter b: ";
    std::cin >> b;
    int num = 0;
    
    
    
    for (int i = 1; num <= b;i++) {
        num = std::pow(2, i) - 1;
        if (num >= a && num <= b) {
            std::cout << num << " ";
        }
        num = std::pow(2, i) - 1;

    }




    return 0;
        
}
