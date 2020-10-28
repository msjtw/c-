#include <iostream>

using namespace std;

const int ROZ = 3;

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

// void scalanie(int l, int g, int p, int t[]){
//     int tmp[ROZ];
//     int i = l, j = g, k = l;
//     while(i<g && j<=p)
//         if(t[i] < t[j])
//             tmp[k++]=t[i++];
//         else
//             tmp[k++]=t[j++];
//     while(i < g)
//         tmp[k++] = t[i++];
//     while(j <= p)
//         tmp[k++] = t[j++];
//     for(int k=l; k <= p; k++)
//         t[k] = tmp[k];

// }

int main(){
    int tab[ROZ] {};

    for(int i = 0; i < ROZ; i++){
        cin >> tab[i];
    }

    scalanie(0, ROZ/2, ROZ, tab);

    for(int i = 0; i < ROZ; i++){
        cout << tab[i] << endl;
    }

}