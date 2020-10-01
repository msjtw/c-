#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool prostokotny(long long a, long long b, long long c) {
	long long boki[3];
	boki[0] = a;
	boki[1] = b;
	boki[2] = c;

	sort(boki, boki + 3);
	if (boki[0] * boki[0] + boki[1] * boki[1] == boki[2] * boki[2])
		return true;
	else
		return false;
}

int main() {

	double ppole = 0;
	bool tura_jana = false;
	int jan = 0, graz = 0;

	while (true) {

		double a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		double p = (a + b + c) / 2;

		double pole = 0;

		if (p * (p - a)*(p - b)*(p - c) > 0) {
			pole = sqrt(p * (p - a)*(p - b)*(p - c));
		}
		else
			pole = -1;

		int punkty = 0;

		if (pole != -1) {
			punkty = 1;
			if (pole <= 1.2*ppole && pole >= 0.8*ppole) {
				punkty = 2;
				if (prostokotny(a, b, c) == true) {
					punkty = 3;
				}
			}
		}



		if (tura_jana == false) {
			graz += punkty;
			tura_jana = true;
		}
		else{
			jan += punkty;
			tura_jana = false;
		}
        if(pole > 0)
		    ppole = pole;
		//cout << "punkty" << graz << ' ' << jan << endl;
	}
		cout << graz << ' ' << jan;

	return 0;
}