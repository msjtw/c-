#include <iostream>
#include <vector>

using namespace std;

int dziury[];

void dod(int poziom, int col){
    int pocz = 0, kon = dziury.size()-1;
    while(true){
        int pol = (pocz+kon)/2;
        if(col > dziury[pol].nr){
            pocz = pol;
        }
        else if(col < dziury[pol].nr){
            kon = pol;
        }
        else if(col == dziury[pol].nr){
            dziury[pol].poz.push_back(poziom);
            break;
        }
        if(pocz == kon && dziury[pol].nr != col){
            
            break;
        }
    }
}

int main(){


    return 0;
}