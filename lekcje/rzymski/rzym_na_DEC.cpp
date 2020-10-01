#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    string rzymski;
    cin >> rzymski;

    vector <int> DEC_z_RZ;

    for(int i = 0; i < rzymski.length(); ++i){
        switch(rzymski[i]){
            case 'I':
                DEC_z_RZ.push_back(1);
                break;
            case 'V':
                DEC_z_RZ.push_back(5);
                break;
            case 'X':
                DEC_z_RZ.push_back(10);
                break;
            case 'L':
                DEC_z_RZ.push_back(50);
                break;
            case 'C':
                DEC_z_RZ.push_back(100);
                break;
            case 'D':
                DEC_z_RZ.push_back(500);
                break;
            case 'M':
                DEC_z_RZ.push_back(1000);
                break;
        }
    }

    vector <int> neron;

    neron.push_back(DEC_z_RZ[0]);
    int pop = DEC_z_RZ[0];

    for(int i = 1; i< DEC_z_RZ.size(); i++){
        if(DEC_z_RZ[i] == pop){
            neron[neron.size()-1] += DEC_z_RZ[i];
        }
        else{
            neron.push_back(DEC_z_RZ[i]);
            pop = DEC_z_RZ[i];
        }
    }

    int liczba = 0;
    for(int i = 0; i < neron.size()-1; ++i){
        if(neron[i] < neron[i+1]){
            neron[i+1] -= neron[i];
        }
        else{
            liczba += neron[i];
        }
    }
    liczba += neron[neron.size()-1];

    cout << liczba;
    

    return 0;
}