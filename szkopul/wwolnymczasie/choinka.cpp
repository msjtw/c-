#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    vector <int> last24_val;
    vector <int> last24_min;
    vector <int> last24_hour;

    last24_val.push_back(3);
    last24_min.push_back(3);
    last24_hour.push_back(3);

    string ptr ={};

    for(int i = 0; i < last24_val.size(); ++i){
        ptr += "['";
        ptr += last24_hour[i];
        ptr += ":";
        ptr += last24_min[i];
        ptr += "', ";
        ptr += last24_val[i];
        ptr += "],\n";
    }

    cout << ptr;

    return 0;
}