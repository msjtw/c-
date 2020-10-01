#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct rzym {
    string znak;
    int wartosc;
};


int main(){
    const int ilosc_liczb = 13;

    rzym liczby[ilosc_liczb];
    liczby[0].znak = "I";
    liczby[0].wartosc = 1;

    liczby[1].znak = "IV";
    liczby[1].wartosc = 4;
    liczby[2].znak = 'V';
    liczby[2].wartosc = 5;

    liczby[3].znak = "IX";
    liczby[3].wartosc = 9;
    liczby[4].znak = 'X';
    liczby[4].wartosc = 10;

    liczby[5].znak = "XL";
    liczby[5].wartosc = 40;
    liczby[6].znak = 'L';
    liczby[6].wartosc = 50;

    liczby[7].znak = "XC";
    liczby[7].wartosc = 90;
    liczby[8].znak = 'C';
    liczby[8].wartosc = 100;

    liczby[9].znak = "CD";
    liczby[9].wartosc = 400;
    liczby[10].znak = 'D';
    liczby[10].wartosc = 500;

    liczby[11].znak = "CM";
    liczby[11].wartosc = 900;
    liczby[12].znak = 'M';
    liczby[12].wartosc = 1000;

    int liczba;
    cin >> liczba;

    reverse(liczby, liczby+13);

    string wynik = "";
    while(liczba != 0){
        int i =0;
        while(liczba < liczby[i].wartosc) 
            i++;
        liczba -= liczby[i].wartosc;
        wynik += liczby[i].znak;
    }

    cout << wynik;

    return 0;
}