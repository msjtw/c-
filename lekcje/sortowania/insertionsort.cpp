#include <iostream>

using namespace std;

const int ROZ = 10;

void insertionsort(int p, int q, int tab[]){
    for(int i = 1; i <= q; i++){
        int j = i-1;
        while(j >= 0 && tab[j] > tab[j+1]){
            swap(tab[j+1], tab[j]);
            j--;
        }
    }
}

int main(){
    int tab[10];
    for(int i = 0; i < 10; i++)
        cin >> tab[i];

    insertionsort(0, ROZ-1, tab);

    for(int i = 0; i < 10; i++)
        cout << tab[i] << " ";

    return 0;

    return 0;
}