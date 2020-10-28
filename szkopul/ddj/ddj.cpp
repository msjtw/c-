#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int domy[210];
    int domow, graz, pien;
    cin >> domow >> graz >> pien;

    for(int i = 0; i < domow; i++){
        cin >> domy[i];
    }

    int i = graz-1;
    while((domy[i] > pien || domy[i] == 0) && i < domow){
        i++;
    }
    int prawo = INT_MAX;
    if(i != domow && graz != domow-1)
        prawo = i - (graz-1);

    reverse(domy, domy+domow);
    graz += (domow/2)-graz;

    i = graz-1;
    while((domy[i] > pien || domy[i] == 0) && i < domow){
        i++;
    }
    int lewo = INT_MAX;
    if(i != domow && graz != domow-1)
        lewo = i - (graz-1);

    cout << 10*min(lewo, prawo);
}