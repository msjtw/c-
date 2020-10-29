#include <iostream>

using namespace std;

const int ROZ = 20;

void quicksort(int p, int q, int tab[]){
	int i = p, j = q;
	int m = tab[(p+q)/2]; 
	
	while(i <= j){
		while(m > tab[i])
            i++;

		while(m < tab[j])
            j--;

        if(i <= j){
            swap(tab[i],tab[j]);
            i++;
            j--;
        }
	}
	if(j > p)
	    quicksort(p, j, tab);
	if(i < q)
	    quicksort(i, q, tab);
}

int main(){
    int tab[ROZ];
    for(int i = 0; i < ROZ; i++)
        cin >> tab[i];

    quicksort(0, ROZ-1, tab);

    for(int i = 0; i < ROZ; i++)
        cout << tab[i] << " ";
}