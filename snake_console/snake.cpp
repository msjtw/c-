#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;

struct xy
{
    int x;
    int y;
};

xy fruit; 
xy snake;

int score;

vector <xy> tail;

int window_width = 20;
int window_height = 20;
int delay = 200;

bool game_over = false;

enum direction{STOP, UP, DOWN, LEFT, RIGHT};
direction edir;

void draw();

void logic();

void input();

void setup();

int main(){

    setup();

    while(!game_over){
        draw();
        input();
        logic();
    }

    return 0;
}

bool porownanie(xy left, xy right) {
        if (left.y == right.y) {
            if (left.x == right.x) {
                return false;
            }
            else return left.x > right.x;
        }
        else return left.y > right.y;
}

void draw(){

    system("cls");

    vector <xy> drawtail = tail;
    int i = 0;

    sort(drawtail.begin(), drawtail.end(), porownanie);

    for(int y = 0;y < window_width + 1; ++y){
        for(int x = 0; x < window_height + 1; ++x){
            if(x == 0 || x == window_width || y == 0 || y == window_height)
                cout << '#';
            else
                if(y == fruit.y && x == fruit.x)
                    cout << 'f';
                else if (snake.x == x && snake.y == y)
                    cout << 'O';
                else {

                    bool print = false;
                    for(xy point : drawtail){
                        if(point.x == x && point.y == y){
                            cout << 'o';
                            print = true;
                        }  
                    }
                    if(!print)
                            cout << ' ';
                }
        }
        cout << endl;
        
    }
    cout << endl << "score: " << score << endl << "press x to end";
    Sleep(delay);
}

void logic(){
    switch(edir){
        case UP:
            snake.y--;
            break;
        case DOWN:
            snake.y++;
            break;
        case LEFT:
            snake.x--;
            break;
        case RIGHT:
            snake.x++;
            break;
    }

    if(snake.x == 0 || snake.y == window_height || snake.y == 0 || snake.x == window_width)
        game_over = true;

    for(int i = 1; i < tail.size(); ++i){
        if(tail[i].x == snake.x && tail[i].y == snake.y)
            game_over = true;
    }

    if(snake.x == fruit.x && snake.y == fruit.y ){
        score++;
        fruit.x = rand() % window_width;
        fruit.y = rand() % window_height;
    }

    tail.push_back(snake);

    if(tail.size() > score + 1)
        tail.erase(tail.begin());
        
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w' :
                edir = UP;
                break;
            case 's' :
                edir = DOWN;
                break;
            case 'd' :
                edir = RIGHT;
                break;
            case 'a' :
                edir = LEFT;
                break;
            case 'x' :
                game_over = true;
                break;
        }
    }
}

void setup(){
    cout << "SNAKE V1" << endl;
    cout << "width: ";
    cin >> window_width;
    cout << "heigth: ";
    cin >> window_height;
    cout << "dealy(ms): ";
    cin >> delay;


    edir = STOP;
    fruit.x = rand() % window_width;
    fruit.y = rand() % window_height;
    snake.x = window_width / 2;
    snake.y = window_height / 2;
    score = 0;
}
