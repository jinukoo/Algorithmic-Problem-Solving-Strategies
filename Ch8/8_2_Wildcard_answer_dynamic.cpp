// Q : given wildcard pattern, print all applicable input filenames in alphabetical order
// * : can be any length of string(0 included)
// ? : can be any char
// pattern and filenames are composed of alphabets and numbers

// Idea : dynamic programming
//        reduce overlapped calculation from full search algorithm
//        express every possible case by [100][100] array


#include <iostream>
#include <algorithm>
using namespace std;

string arr[50];
int cache[100][100];

string pattern;
string filename;

bool match(int p, int f);

int main(){
    // input test cases
    int c;
    cin >> c;
    while(c--){
        // input wildcard pattern
        cin >> pattern;

        // input numbers of filenames
        int n;
        cin >> n;
        int i = 0;

        while(n--){
            fill(cache[0], &cache[99][99], -1);
            cin >> filename;
            if(match(0, 0)){
                arr[i] = filename;
                i++;
            }
        }
        // sort in alphabetical order and print them
        sort(arr, &arr[i]);
        for(int j = 0; j < i; j++){
            cout << arr[j] << endl;
        }
    }
}

// return true if pattern.substr(p) and filename.substr(f) are applicable
// p : iterator for pattern
// f : iterator for filename
bool match(int p, int f){
    // return already calculated result
    int& res = cache[p][f];
    if(res != -1) return bool(res);

    // if did not reached end or encountered '*' advance
    if(p < pattern.length() && f < filename.length() && (pattern[p] == '?' || pattern[p] == filename[f]))
        return res = match(p + 1, f + 1);
    // proceeds in following cases
    // 1. pattern ended 
    // 2. filename ended
    // 3. pattern and filename did not match
    // 4. met '*'
    
    // pull out true cases
    // pattern equals filename without having '*'
    if(p == pattern.length())
        return res = (f == filename.length());

    // met '*' -> recursive call
    if(pattern[p] == '*'){
        return res = (match(p + 1, f) || match(p + 1, f + 1));
    }
    return false;
}

/* Key Points
1. use return assignment to return and assign to cache
2. 
*/