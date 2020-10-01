#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath> 


using namespace std;

int main()
{
	double a, b, c;

	cin >> a >> b >> c;
    if(a > 0 && b > 0 && c > 0){

        double p = (a + b + c) / 2;

        if (p * (p - a)*(p - b)*(p - c) > 0) {
            cout << setprecision(2) << fixed;
            cout << sqrt(p * (p - a)*(p - b)*(p - c));
        }
        else
            cout << "TROJKAT NIE ISTNIEJE";
    }
    else
        cout << "BLEDNE DANE";

	return 0;
}