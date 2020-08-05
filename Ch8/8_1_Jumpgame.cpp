#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(int y, int x, int n);

vector<vector<int>> board;
vector<vector<int>> cache;

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        
        // initialize board
        int input;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                cin >> input;
                temp.push_back(input);
            }
            board.push_back(temp);
        }

        // initialize cache
        vector<int> tmp(n);
        fill(tmp.begin(), tmp.end(), -1);
        for(int i = 0; i < n; i++){
            cache.push_back(tmp);
        }

        if(solve(0, 0, n)) cout << "YES" << endl;
        else cout << "NO" << endl;

        // clear for next test case
        board.clear();
        cache.clear();
    }
}

bool solve(int y, int x, int n){
    // base case
    if(x == n - 1 && y == n - 1) return true;

    // use already calculated data
    if(cache[y][x] != -1) return bool(cache[y][x]);

    int move = board[y][x];
    if((x + move < n && solve(y, x + move, n)) || (y + move < n && solve(y + move, x, n))){
        cache[y][x] = 1;
        return true;
    }
    else{
        cache[y][x] = 0;
        return false;
    }
}