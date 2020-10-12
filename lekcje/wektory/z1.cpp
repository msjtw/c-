#include <iostream>

int main()
{
    int licznik = 0;
    for (int i = 0; i < 100; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a == 0 || b == 0)
        {
            std::cout << a << " " << b << std::endl;
            licznik++;
        }
    }
    std::cout << licznik;
}