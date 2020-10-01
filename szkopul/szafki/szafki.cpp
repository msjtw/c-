#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> wzrosty;

    int suma = 0;

    int liczb;
    cin >> liczb;

    for(int i =0 ;i < liczb; ++i){
        int a;
        cin >> a;
        wzrosty.push_back(a);
        suma += a;
    }
    int srednia = suma / wzrosty.size();

    int wieksi = 0;

    for(int a : wzrosty){
        if(a > srednia)
            wieksi++;
    }

    cout << srednia << endl;

    if(wieksi > wzrosty.size()-wieksi){
        cout << "TAK";
    }
    else{
        cout << "NIE";
    }

    return 0;
}