#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int ROZ = 100000;

void BubbleSort(int p, int k, int *t){
    bool pop = true;
    do{
        pop = false;
        for(int i = 0; i < k; i++){
            if(t[i] > t[i+1]){
                pop = true;
                swap(t[i], t[i+1]);
            }
        }
    }while(pop);
}

void SelectionSort(int p, int k, int *t){
    for(int i = 0 ; i <= k; i ++){
        for(int j = i; j <= k; j++){
            if(t[i] > t[j])
                swap(t[i], t[j]);
        }
    }
}

void InsertionSort(int p, int k, int *t){
    for(int i = 1; i <= k; i++){
        int j = i-1;
        while(j >= 0 && t[j] > t[j+1]){
            swap(t[j+1], t[j]);
            j--;
        }
    }
}

void scalanie(int p, int q, int k, int tab[]){
    int wynik[ROZ];
    for(int i = p, pi = p, qi = q; i < k; i++){
        wynik[i] = tab[pi] > tab[qi] ? tab[qi++] : tab[pi++];
        qi = qi >= k || qi < pi ? pi : qi;
        pi = pi >= q ? qi : pi;
    }
    for(int i = p ;i < k; i++)
        tab[i] = wynik[i];
}

void MergeSort(int p, int k, int *t){
    if(p < k){
        int s = (p+k)/2;
        MergeSort(p, s, t);
        MergeSort(s+1, k, t);
        scalanie(p, s+1, k+1, t);
    }
}

void QuickSort(int p, int k, int *t){
	int i = p, j = k;
	int m = t[(p+k)/2]; 
	
	while(i <= j){
		while(m > t[i])
            i++;

		while(m < t[j])
            j--;

        if(i <= j){
            swap(t[i],t[j]);
            i++;
            j--;
        }
	}
	if(j > p)
	    QuickSort(p, j, t);
	if(i < k)
	    QuickSort(i, k, t);
}

int main(){
    unsigned long tim;

    srand(time(NULL));
    //while(true){
        int tab[ROZ];
        for(int i = 0; i < ROZ; i++)
            tab[i] = (rand() % 201) - 100;

        int a[ROZ];

        cout << "\tBubbleSort\tSelectionSort\tInsertionSort\tMergeSort\tQuickSort" << endl << "losowe\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        BubbleSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        SelectionSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        InsertionSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        MergeSort(0, ROZ-1, a);
        cout << double(clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        QuickSort(0, ROZ-1, a);
        cout << double(clock()-tim)/CLOCKS_PER_SEC << "s\t\t" << endl << "rosnace\t";

        sort(tab, tab+ROZ);

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        BubbleSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        SelectionSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        InsertionSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        MergeSort(0, ROZ-1, a);
        cout << double(clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        QuickSort(0, ROZ-1, a);
        cout << double(clock()-tim)/CLOCKS_PER_SEC << "s\t\t" << endl << "malejac\t";

        reverse(tab, tab+ROZ);

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        BubbleSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        SelectionSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        InsertionSort(0, ROZ-1, a);
        cout << (clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        MergeSort(0, ROZ-1, a);
        cout << double(clock()-tim)/CLOCKS_PER_SEC << "s\t\t";

        for(int i = 0; i < ROZ; i++)
            a[i] = tab[i];

        tim = clock();
        QuickSort(0, ROZ-1, a);
        cout << double(clock()-tim)/CLOCKS_PER_SEC << "s\t\t" << endl;

    //}
    return 0;
}