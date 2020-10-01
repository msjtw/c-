#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int maximum = 0;
    int ilosc = 0;
    int liczb;
    cin >> liczb;
    vector<int> liczby(1000000, 0);

    for (int i = 0; i < liczb; i++) {
        int a;
        cin >> a;
        liczby[a]++;
    }

    bool lukasz = false;

    for (int i = 0; i < 1000000; i++) {
        //cout << liczby[i] << endl;
        if (liczby[i] % 2 == 1) {
            lukasz = true;
            break;
        }
    }
    cout << (lukasz ? "Lukasz" : "Marcin") << "\n";
    return 0;
}