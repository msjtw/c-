#include <iostream>
#include <vector>

using namespace std;

string dec2all(int, int);

int main(){
    int pod;
    cin >> pod;
    int liczba;
    cin >> liczba;

    cout << dec2all(liczba, pod);

    return 0;
}

string dec2all(int liczba, int pod){
    string wynik = "";
    int pot = pod;
    if(pod > 10){
        while(liczba > 0){
            int znak = liczba%pot;
            if(znak > 9){
                wynik = char(znak-10+'A') + wynik;
            }
            else{
                wynik = to_string(znak) + wynik;
            }
            liczba /= pot;
        }
    }
    else{
        while(liczba > 0){
        wynik = to_string(liczba%pot) + wynik;
        liczba /= pot;
        //pot *= pod;
        }
    }
    

    return wynik;
}