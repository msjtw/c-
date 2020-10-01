#include <iostream>
#include <utility>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair <int,int> punkt1;
    pair <int,int> punkt2;
    pair <int,int> punkt3;
    pair <int,int> punkt4;

    cin >> punkt1.first >> punkt1.second >> punkt2.first >> punkt2.second;

    if(punkt1.second < punkt2.second){
        cout << punkt1.first << ' ' << punkt2.second << ' ';
        cout << punkt2.first << ' ' << punkt1.second << endl;
    }
    else{
        cout << punkt2.first << ' ' << punkt1.second << ' ';
        cout << punkt1.first << ' ' << punkt2.second << endl;
    }
    cout << abs(punkt2.first - punkt1.first) * abs(punkt1.second - punkt2.second);

    return 0;
}