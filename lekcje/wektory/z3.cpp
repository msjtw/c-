#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

int main()
{
    double wynik[100]{};
    std::cout << std::setprecision(2) << std::fixed;
    for (int i = 0; i < 100; i++)
    {
        int a, b;
        std::cin >> a >> b;
        wynik[i] = sqrt(a * a + b * b);
    }
    std::sort(wynik, wynik + 100);

    for (int i = 0; i < 100; i++)
    {
        std::cout << wynik[i] << std::endl;
    }

    return 0;
}
