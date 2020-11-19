#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROZ = 20+2;

int tab1[ROZ][ROZ];
int tab2[ROZ][ROZ];


int neighbour(int row, int col){
    int wynik = 0;
    for(int i = row-1; i < row+2; i++){
        for(int j = col-1; j < col+2; j++){
            if(!(i == row && j == col))
                wynik += tab1[i][j];
        }
    }
    return wynik;
}

void copy(){
    for(int i = 1; i < ROZ-1; i++){
        for(int j = 1; j < ROZ-1; j++){
            tab1[i][j] = tab2[i][j];
        }
    }
}

void make(){
    for(int i = 1; i < ROZ-1; i++){
        for(int j = 1; j < ROZ-1; j++){
            int s = neighbour(i, j);
            if(s == 3)
                tab2[i][j] = 1;
            else if(s == 2)
                tab2[i][j] = tab1[i][j];
            else 
                tab2[i][j] = 0;
        }
    }
}

void show(){
    system("cls");
    for(int i = 1; i < ROZ-1; i++){
        for(int j = 1; j < ROZ-1; j++){
            cout << tab2[i][j];
        }
        cout << endl;
    }
}

void init(){
    for(int i = 1; i < ROZ-1; i++){
        for(int j = 1; j < ROZ-1; j++){
            tab2[i][j] = rand()%2;
        }
    }
}

int main(){
    srand(time(NULL));
    init();
    for(int i = 0; i < 50; i++){
        copy();
        make();
        show();
        Sleep(500);
    }

    return 0;
}