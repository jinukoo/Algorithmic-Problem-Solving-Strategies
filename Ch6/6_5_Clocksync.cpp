#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 123456789;
constexpr int SWITCHES = 10;
constexpr int CLOCKS = 16;

const char linked[SWITCHES][CLOCKS + 1] = {
        // 0123456789012345
        "xxx.............",
        "...x...x.x.x....", 
        "....x.....x...xx", 
        "x...xxxx........",
        "......xxx.x.x...",
        "x.x...........xx",
        "...x..........xx",
        "....xx.x......xx",
        ".xxxxx..........",
        "...xxx...x...x.."
    };


// checks if clocks are all 12
bool isAligned(int clocks[]);

void push(int clocks[], int swtch);

int solve(int clocks[], int swtch);

int min_pushes(int clock){
    // base case : reach end
    if(clock == 9){
        if(isAllTwelve(clocks))
            return 0;
        else return INF;
    }

    if(clock == 1 || clock == 4)
        return min_pushes(clock + 1);

    int res = INF;
    for(int i = 0; i < 4; i++){
        pushes[clock] = i;
        res = min(res, min_pushes(clock + 1) + i);
    }
    return res;
}

int main(){
    // input number of test cases
    int c;
    cin >> c;

    int clocks[CLOCKS];
    
    for(int i = 0; i < c; i++){
        // input clocks
        int input;
        for(int j = 0; j < CLOCKS; j++){
            cin >> input;
            clocks[j] = input;
        }

        // exception : clock 8 and 12 should be same time
        if(clocks[8] != clocks[12]){
            cout << -1 << endl;
            break;
        }
        
        // switches 1, 4, 9 are unique switches that can change clock
        const int make_twelve[] = {0, 0, 0, 3, 0, 0, 2, 0, 0, 1, 0, 0, 0};

        int res = solve(clocks, 0);
        if(res >= INF)
            res = -1;
        cout << res << endl;
        
    }
}


// checks if clocks are all 12
bool isAligned(int clocks[]){
    for(int i = 0; i < CLOCKS; i++){
        if(clocks[i] != 0)
            return false;
    }
    return true;
}


void push(int clocks[], int swtch){
    
}


int solve(int clocks[], int swtch){

}





/*
1. it's better to be simple than to reduce O(n) -> did not skip switches 1, 4, 9
-> try simpliest and easiest problem and then add
2. change problem constraints to a simpler form -> linked char type array


*/