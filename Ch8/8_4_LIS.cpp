// Q : find the Longest Increasing Sequence(LIS) from the given numbers of sequence

// Idea : Dynamic programming
//        overlapping calculation occurs when finding LIS starting from certain number

#include <iostream>
#include <algorithm>
using namespace std;

int seq[500];
// cache[i] corresponds to LIS starting from seq[i-1]
int cache[501];
int n;                  // numbers in sequence

int solve(int x);

int main(){
    // input test cases
    int c;
    cin >> c;
    while(c--){
        cache[0] = -1;
        cin >> n;
        for(int i = 0; i < n; i++){
            // input sequence of numbers
            cin >> seq[i];
            // initialize cache
            cache[i + 1] = -1;
        }
        // search longest LIS
        // -1 b/c there is no 0th element
        cout << solve(0) - 1 << endl;
    }
}

// return the largest length of LIS starting from the given index
// base on cache
int solve(int start){
    // memoization
    if(cache[start] != -1) return cache[start];

    // base case
    if(start == n) return cache[start] = 1;

    // general case
    int& res = cache[start] = 0;

    // for each numbers greater than last_num
    for(int next = start; next <= n; next++){
        if(seq[start - 1] < seq[next - 1])
            // find longest LIS
            res = max(solve(next), res);
    }
    // count seq[x] to the result
    return ++res;
}

/* Improvements:
1. Simpler code
while(x < n){
    // pass numbers smaller than last_num
    while(x < n && seq[x] <= last_num) x++;
    if(x >= n) break;
    // find longest LIS
    res = max(solve(x), res);
    x++;
}
            |
           \ /
// for each numbers greater than last_num
for(;x < n; x++){
    if(last_num < seq[x])
        // find longest LIS
        res = max(solve(x), res);
}

2. for loop in main to iterate all starting point is also overlapping
    -> use cache[0] = -1, cache[101], solve(0)
*/