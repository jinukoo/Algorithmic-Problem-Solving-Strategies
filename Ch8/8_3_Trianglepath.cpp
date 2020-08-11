// Q : from triangle shape of natural numbers, find the largest sum
//     starting from the top line to the bottom line
//     only able to pass to below number and the number right to the below number

// Idea : store the number in an array
//        use dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long tri[100][100];
// holds the largest sum starting from that index
// 0 : not calculated (inputs are larger than 0)
unsigned long long cache[100][100];
int n;                  // lines of triangle

unsigned long long solve(int i, int j);

int main(){
    // input test cases
    int c;
    cin >> c;
    while(c--){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i + 1; j++){
                // set tri
                cin >> tri[i][j];
                // initialize cache
                cache[i][j] = 0;
            }
        }
        cout << solve(0, 0) << endl;
    }
}

unsigned long long solve(int i, int j){
    // check if already calculated
    if(cache[i][j] != 0)
        return cache[i][j];
    // base case : reached the bottom line
    if(i == n - 1)
        return tri[i][j];
    // general case
    unsigned long long& res = cache[i][j];
    res = max(solve(i + 1, j), solve(i + 1, j + 1)) + tri[i][j];
    return res;
}