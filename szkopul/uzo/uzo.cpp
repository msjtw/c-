#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct wall{
    bool left = false;
    bool down = false;
    bool right = false;
};

struct poz{
    int x;
    int y;
};

struct path{
    string steps;
    int length;
};

wall walls[1010][1010] {};
poz exit_poz;

path memo[1010][1010];

path path_search(int x, int y, char blockade){
    path result;
    if(memo[y][x].length == -1){
        if(x == exit_poz.x && y == exit_poz.y){
            result.length = 0;
            result.steps.clear();
        }
        else{
            path as_r, as_d, as_l;
            as_r.length = INT_MAX;
            as_d.length = INT_MAX;
            as_l.length = INT_MAX;
            if(!walls[y][x].right && blockade != 'r'){
                as_r = path_search(x+1,y,'l');
            }
            if(!walls[y][x].down){
                as_d = path_search(x,y-1,'u');
            }
            if(!walls[y][x].left && blockade != 'l'){
                as_l = path_search(x-1,y,'r');
            }
            if(as_r.length == INT_MAX && as_d.length == INT_MAX && as_l.length == INT_MAX)
                result.length = INT_MAX;
            else{
                if(as_r.length < as_d.length){
                    if(as_l.length < as_r.length){
                        result.length = as_l.length+1;
                        result.steps = "1" + as_l.steps;
                    }
                    else{
                        result.length = as_r.length+1;
                        result.steps = "3" + as_r.steps;
                    }
                }
                else{
                    if(as_l.length < as_d.length){
                        result.length = as_l.length+1;
                        result.steps = "1" + as_l.steps;
                    }
                    else{
                        result.length = as_d.length+1;
                        result.steps = "2" + as_d.steps;
                    }
                }

            }
        }
        memo[y][x].length = result.length;
        memo[y][x].steps = result.steps;
    }
    else{
        result.steps = memo[y][x].steps;
        result.length = memo[y][x].length;
    }
    //cout << "x: " << x << " y: " << y << ", steps: " << result.steps << ", length: " << result.length << endl;
    //cout << result.steps << endl;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int size_x, size_y;
    poz zocha;
    cin >> size_x >> size_y;
    size_y *= -1;
    cin >> zocha.x >> zocha.y;
    zocha.y *= -1;
    cin >> exit_poz.x >> exit_poz.y;
    exit_poz.y *= -1;

    int a, b, c;
    while(true){
        cin >> a >> b >>c;
        if(a == 0) break;
        if(a > 0){
            b *= -1;
            c *= -1;
            walls[max(b, c)][a].down = true;
        }    
        else{
            a *= -1;
            walls[a][min(b, c)].right = true;
            walls[a][max(b, c)].left = true;
        }
    }

    for(int i = 0; i <= size_y; i++){
        walls[i][1].left = true;
        walls[i][size_x].right = true;
    }
    for(int i = 0; i <= size_x; i++){
        walls[1][i].down = true;
    }

    for(int i = 0; i < 1010; i++){
        for(int j = 0; j < 1010; j++){
            memo[i][j].length = -1;
        }
    }
    path result = path_search(zocha.x, zocha.y, 'u');
    cout << result.steps;

    return 0;
}