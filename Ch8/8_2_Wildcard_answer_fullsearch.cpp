// Q : given wildcard pattern, print all applicable input filenames in alphabetical order
// * : can be any length of string(0 included)
// ? : can be any char
// pattern and filenames are composed of alphabets and numbers

// Idea : full search algorithm
//        use one iterator
//        when encountering '*' recursive call for all possible matching of '*' until true

#include <iostream>
#include <algorithm>
using namespace std;

string arr[50];

bool match(const string& pattern, const string& filename);

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
        int i = 0;

        while(n--){
            string filename;
            cin >> filename;
            if(match(pattern, filename)){
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

// return true if filename is applicable for wildcard pattern
// recursive function call to handle '*'
bool match(const string& pattern, const string& filename){
    // iterator for comparing
    int i = 0;
    // advance until reached end or encountered '*'
    while(i < pattern.length() && i < filename.length() && (pattern[i] == '?' || pattern[i] == filename[i])) i++;
    // loop ends in following cases
    // 1. pattern ended 
    // 2. filename ended
    // 3. pattern and filename did not match
    // 4. met '*'
    
    // pull out true cases
    // pattern equals filename without having '*'
    if(i == pattern.length())
        return (i == filename.length());

    // met '*' -> recursive call
    if(pattern[i] == '*'){
        for(int skip = 0; i + skip <= filename.length(); skip++){
            if(match(pattern.substr(i + 1), filename.substr(i + skip)))
                return true;
        }
    }
    return false;
}

/* Key Points
1. If cases are complex, try to sort them by result, not process. then you can find which cases can be processed together
    -> match returns false and except some cases of true
2. Try to find how you can use recursion to cut out duplication
    -> recursive call to handle '*'
3. Use const & method of delivering parameters if possible
4. Usage of string.substr()
5. returning == equation
*/