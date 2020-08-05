// Q : given a n*n board, you can either move right or down by the number in that block
//     find wether you can reach bottom right from the top left corner.

// Idea : Dynamic Programming and express each jump as a recursive function call

#include <iostream>
#include <algorithm>
using namespace std;

bool solve(int y, int x);

const int MAX = 100;

int board[MAX][MAX];
int cache[MAX][MAX];
int n;

int main(){
    // input test cases
    int c;
    cin >> c;
    while(c--){
        // input size of board
        cin >> n;
        
        // initialize board
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }

        // initialize cache to -1
        fill(cache[0], &cache[MAX-1][MAX-1],-1);

        if(solve(0, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

// return true if corresponding location can reach bottom right
bool solve(int y, int x){
    // base case : reached end
    if(x == n - 1 && y == n - 1) return true;

    // use already calculated data
    if(cache[y][x] != -1) return bool(cache[y][x]);

    int move = board[y][x];
    if((x + move < n && solve(y, x + move)) || (y + move < n && solve(y + move, x))){
        cache[y][x] = 1;
        return true;
    }
    else{
        cache[y][x] = 0;
        return false;
    }
}

/* Improvements:
1. if maximum is given, prefer array than vector -> board, cache
    - no need to assign and free memory each time
2. use common and constant parameter as a global variable -> n
3. way of using fill to assign value to two dimensional array
*/