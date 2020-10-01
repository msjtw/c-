#include <iostream>
#include <string>

using namespace std;

int main(){
    int tab[255] = {};

    string tekst;
    getline(cin, tekst);

    for(int i = 0; i < tekst.length(); i++){
        tekst[i] = toupper(tekst[i]);
    }

   //cout << tekst << endl;
     
     for(int i = 0; i < tekst.length(); ++i){
         tab[int(tekst[i])] += 1;
     }

     for(int i = 'A'; i <= 'Z'; i++){
         if(tab[i] > 0)
            cout << char(i) << ' ' << tab[i] << endl;
     }

    return 0;
}