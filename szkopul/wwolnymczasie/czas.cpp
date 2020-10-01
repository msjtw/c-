#include <iostream>

using namespace std;

int main(){
    int sec;
    cin >> sec;

    int godz = sec/3600;

    int minuty = sec/60 - godz*60;

    int sekundy = sec - godz*3600 - minuty*60;

    cout << godz << "g" << minuty << "m" << sekundy << "s";

    return 0;
}