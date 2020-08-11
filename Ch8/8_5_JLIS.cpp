// Q : find the Joined Longest Increasing Sequence(JLIS) from the given numbers of sequences
//     make LIS out of each sequence and join the two LIS to make JLIS
//     find the larges JLIS

// Idea : Dynamic programming ->

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int seqA[101];
int seqB[101];
// cache[i][j] saves calculation of solve[i][j]
// length of JLIS; cannot be negative
int cache[101][101];
int n;                  // numbers in sequence A
int m;                  // numbers in sequence B

int solve(int indexA, int indexB);

int main(){
    // input test cases
    int c;
    cin >> c;
    while(c--){
        // input seq A and B
        // seqA and seqB starts from 1
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> seqA[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> seqB[i];
        }
        // initialize cache
        fill(&cache[0][0], &cache[100][100], -1);

        cout << solve(0,0) - 2 << endl;         // -2 for solve(0,0)
    }
}

// returns the length of JLIS that includes seqA[indexA] and seqB[indexB]
// && seqA[indexA] and seqB[indexB] are the smallest elements of JLIS
// index starts from 1
int solve(int indexA, int indexB){
    // memoization
    int& res = cache[indexA][indexB];
    if(res != -1)
        return res;

    // JLIS inlcudes indexA and indexB as the smallest element of JLIS
    res = 2;
    
    // next element should be larger than indexA and indexB
    long long a = (indexA == 0) ? NEGINF : seqA[indexA];
    long long b = (indexB == 0) ? NEGINF : seqB[indexB];
    long long cond = max(a, b);
    
    // find next element of JLIS
    for(int nextA = indexA + 1; nextA <= n; nextA++){
        if(cond < seqA[nextA])
            res = max(solve(nextA, indexB) + 1, res);
    }
    for(int nextB = indexB + 1; nextB <= m; nextB++){
        if(cond < seqB[nextB])
            res = max(solve(indexA, nextB) + 1, res);
    }
    
    return res;
}

/*
1. instead of picking elements for seqA and seqB, pick smaller one -> makes merging easier and simpler
2. make stronger precondition to minimize overlapping -> solve function's two index are the smallest elements of JLIS
    -> cases including elements in between the two parameters are calculated when that element becomes the parameter
3. A[indexA] == B[indexB] case is removed from the comparision
4. instead of using double for loop, use two for loops independently
5. each element is 32bit signed integer -> use 64bit long long type to express -INF
    (there is no condition for sign)
6. numberic_limits<type>::min()/max() returns min or max for that type
7. name variables indexA, indexB, nextA, nextB instead of using x, y, i, j
*/