#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct poziom{
    int bez ;
    int koszt ;
    int ost_dziura ;
};

vector <vector <int>> dziury;
vector <poziom> poziomy;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int poziomow, dlugosc, p;
    cin >> poziomow >> dlugosc >> p;
    dziury.resize(poziomow+5);
    poziomy.resize(poziomow+5);
    for(int i = 1; i <= poziomow; i++){
        int a, b;
        cin >> a;
        poziomy[i].ost_dziura = a-1;
        poziomy[i].bez = 0;
        poziomy[i].koszt = 0;
        for(int j = 0; j < a; j++){
            cin >> b;
            dziury[i].push_back(b);
        }
    }

    int h = 1;

    poziomy[poziomow].bez = dziury[poziomow][poziomy[poziomow].ost_dziura]+1;

    if(dziury[1].size() > 0){
        for(int ak_poz = poziomow; ak_poz > 0; ak_poz--){
            while(poziomy[ak_poz].ost_dziura >= 0 && dziury[ak_poz][poziomy[ak_poz].ost_dziura] >= poziomy[ak_poz].bez){
                poziomy[ak_poz].ost_dziura--;
            }
            if(poziomy[ak_poz].ost_dziura == -1)
                poziomy[ak_poz].bez = 0;
            else{
                poziomy[ak_poz].bez = dziury[ak_poz][poziomy[ak_poz].ost_dziura]+1;

                if(ak_poz != poziomow){
                    poziomy[ak_poz+1].bez = dziury[ak_poz][poziomy[ak_poz].ost_dziura];
                    poziomy[ak_poz+1].koszt = poziomy[ak_poz].koszt + 1;
                    while(poziomy[ak_poz+1].ost_dziura >= 0 && dziury[ak_poz+1][poziomy[ak_poz+1].ost_dziura] >= poziomy[ak_poz+1].bez)
                        poziomy[ak_poz+1].ost_dziura--;
                    if(poziomy[ak_poz+1].ost_dziura == -1)
                        poziomy[ak_poz+1].bez = 0;
                    else
                        poziomy[ak_poz+1].bez = dziury[ak_poz+1][poziomy[ak_poz+1].ost_dziura]+1;
                }
                poziomy[ak_poz-1].bez = dziury[ak_poz][poziomy[ak_poz].ost_dziura];
                while(poziomy[ak_poz-1].ost_dziura >= 0 && dziury[ak_poz-1][poziomy[ak_poz-1].ost_dziura] >= poziomy[ak_poz-1].bez)
                    poziomy[ak_poz-1].ost_dziura--;
                if(poziomy[ak_poz-1].ost_dziura == -1)
                    poziomy[ak_poz-1].bez = 0;
                else
                    poziomy[ak_poz-1].bez = dziury[ak_poz-1][poziomy[ak_poz-1].ost_dziura]+1;
                
            }
            h = ak_poz-1;
        }

        do{
            for(int ak_poz = poziomow; ak_poz > h; ak_poz--){
                if(poziomy[ak_poz].bez > 0){
                    poziomy[ak_poz].ost_dziura--;
                    poziomy[ak_poz].koszt++;
                    if(poziomy[ak_poz].ost_dziura != -1)
                        poziomy[ak_poz].bez = dziury[ak_poz][poziomy[ak_poz].ost_dziura]+1;
                    else 
                        poziomy[ak_poz].bez = 0;
                }
                if(poziomy[ak_poz].bez > 0){
                    poziomy[ak_poz+1].bez = poziomy[ak_poz].bez+1;
                    while(poziomy[ak_poz+1].ost_dziura >= 0 && dziury[ak_poz+1][poziomy[ak_poz+1].ost_dziura] >= poziomy[ak_poz+1].bez){
                        poziomy[ak_poz+1].ost_dziura--;
                    }
                    if(poziomy[ak_poz+1].ost_dziura == -1)
                        poziomy[ak_poz+1].bez = 0;
                    else
                        poziomy[ak_poz+1].bez = dziury[ak_poz+1][poziomy[ak_poz+1].ost_dziura]+1;
                    poziomy[ak_poz+1].koszt = poziomy[ak_poz].koszt+1;
                    

                    poziomy[ak_poz-1].bez = poziomy[ak_poz].bez-1;
                    if(ak_poz > 1){
                        while(poziomy[ak_poz-1].ost_dziura >= 0 && dziury[ak_poz-1][poziomy[ak_poz-1].ost_dziura] >= poziomy[ak_poz-1].bez){
                            poziomy[ak_poz-1].ost_dziura--;
                        }
                        if(poziomy[ak_poz-1].ost_dziura == -1)
                            poziomy[ak_poz-1].bez = 0;
                        else
                            poziomy[ak_poz-1].bez = dziury[ak_poz-1][poziomy[ak_poz-1].ost_dziura]+1;
                    }
                } 
            }
        }while(poziomy[poziomow].bez > 0);
    }

    

    // for(int i = 1; i <= poziomow; i++){
    //     cout << poziomy[i].bez << '\t' << poziomy[i].koszt << '\t' << poziomy[i].ost_dziura << endl;
    // }
    // cout << h;

    while(p--){
        int a;
        cin >> a;
        cout << poziomy[a].koszt << '\n';
    }
    return 0;
}