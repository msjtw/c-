#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool find(int liczba, int tabilca[6]){
    for(int i =0 ; i < 6; i++){
        if(tabilca[i] == liczba){
            return true;
        }
    }
    return false;
}

int main(){
    srand (time(NULL));

    int wylosowane[6] = {};
    int liczba;

    for(int i =0; i < 6; ++i){
        do{
            liczba = rand()%49 + 1;
        }while(find(liczba, wylosowane));
        wylosowane[i] = liczba;
    }

    cout << "wylosowano 6 liczb z  z zakresu <1,49>:\n";

    for(int a : wylosowane){
        cout << a << endl;
    }

    return 0;
}