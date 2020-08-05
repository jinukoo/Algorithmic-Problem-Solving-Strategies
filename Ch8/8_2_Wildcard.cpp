// Q : given wildcard pattern, print all applicable input filenames in alphabetical order
// * : can be any length of string(0 included)
// ? : can be any char
// pattern and filenames are composed of alphabets and numbers

// Idea : full search algorithm
//        how to handle '*' is the key problem

// time over

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool solve(string pattern, string filename);

int main(){
    // input test cases
    int c;
    cin >> c;
    while(c--){
        // input wildcard pattern
        string pattern;
        cin >> pattern;

        // input numbers of filenames
        int n;
        cin >> n;

        // vector to store applicable filenames
        vector<string> v;
        while(n--){
            string filename;
            cin >> filename;
            if(solve(pattern, filename))
                v.push_back(filename);
        }
        // sort in alphabetical order and print them
        sort(v.begin(), v.end());
        for(auto it = v.begin(); it != v.end(); it++){
            cout << *it << endl;
        }
        // clear for next test case
        v.clear();
    }
}

// return true if filename is applicable for wildcard pattern
bool solve(string pattern, string filename){
    bool res = true;
    int i = 0;
    int j = 0;
    for(; i < pattern.length(); i++){
        // filename out of range when pattern still exists
        if(j >= filename.length() && pattern[i] != '*'){
            return false;
        }

        // meet *
        if(pattern[i] == '*'){
            // get rid of continuous '*'s
            while(i < pattern.length() && pattern[i] == '*') i++;
            // * is the last  char -> always true
            if(i == pattern.length()) return true;

            // skip pattern until encounters another char
            while(i < pattern.length() && (pattern[i] == '*' || pattern[i] == '?')) {
                if(pattern[i] == '?') j++;      // for each ? -> advance j
                i++;
            }
            // filename reached end because of ?s
            if(j > filename.length()) return false;

            // pattern reached end -> always true
            if(i == pattern.length()) return true;
            // pattern is not over b/ filename is over -> false
            if(j == filename.length()) return false;

            // pattern and filename is not over
            char l = pattern[i];

            // skip filename until encounters l
            while(j < filename.length()){
                while(j < filename.length() && filename[j] != l) j++;
                // did not find l
                if(j == filename.length()) return false;
                // found l
                if(solve(pattern.substr(i, pattern.length() - i), filename.substr(j, filename.length() - j))){
                    return true;
                }
            }
            // did not find matching way
            return false;
        }
        // meet ?
        if(pattern[i] == '?'){
            j++;
            continue;
        }
            
        // not equal
        if(pattern[i] != filename[j]){
            return false;
        }
        else j++;
    }
    if(j < filename.length()) res = false;
    return res;
}