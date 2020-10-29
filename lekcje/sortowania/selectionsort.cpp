#include <iostream>

using namespace std;

const int ROZ = 10;

void selectionsort(int p, int q, int tab[]){
    for(int i = 0 ; i <= q; i ++){
        for(int j = i; j <= q; j++){
            if(tab[i] > tab[j])
                swap(tab[i], tab[j]);
        }
    }
}

int main(){
    int tab[10];
    for(int i = 0; i < 10; i++)
        cin >> tab[i];

    selectionsort(0, ROZ-1, tab);

    for(int i = 0; i < 10; i++)
        cout << tab[i] << " ";

    return 0;

    return 0;
}