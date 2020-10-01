#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

int main(){
    srand(time(0));

    int wylosowana = rand()%1001;
    int wczytana;
    int prob = 0;

    while(true){
        cout << "podaj liczbe w zakresie <0,1000>: ";
        cin >> wczytana;
        prob++;
        if(wczytana > wylosowana){
            cout << "za duzo" << endl;
        }
        else if(wczytana < wylosowana){
            cout << "za malo" << endl;
        }
        else{
            break;
        }
    }

    cout << "BRAWO, zgadles za " << prob << " razem";

    return 0;
}