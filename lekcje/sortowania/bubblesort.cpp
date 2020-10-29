#include <iostream>

using namespace std;

const int ROZ = 10;

void bubblesort(int p, int q, int tab[]){
    bool pop = true;
    do{
        pop = false;
        for(int i = 0; i < q; i++){
            if(tab[i] > tab[i+1]){
                pop = true;
                swap(tab[i], tab[i+1]);
            }
        }
    }while(pop);
}

int main(){
    int tab[10];
    for(int i = 0; i < 10; i++)
        cin >> tab[i];

    bubblesort(0, ROZ-1, tab);

    for(int i = 0; i < 10; i++)
        cout << tab[i] << " ";

    return 0;
}