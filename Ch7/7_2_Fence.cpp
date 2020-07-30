// Q : from fence made out of N woods, find the size of the largest reactange

// Idea : Brute Force
// find all possible reactangles and figure out the max size

#include <iostream>
#include <vector>

using namespace std;

int main(){
    // input test cases
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        // input number of woods
        int n;
        cin >> n;

        // input heights of woods
        int input;
        vector<int> heights;
        for(int j = 0; j < n; j++){
            cin >> input;
            heights.push_back(input);
        }

        int max = 0;
        for(int j= 0; j < n; j++){
            int length = 1;
            // find left side length
            for(int left = j - 1; left >= 0 && heights[left] >= heights[j]; left--){
                length++;
            }

            // find right side length
            for(int right = j + 1; right < n && heights[right] >= heights[j]; right++){
                length++;
            }

            // calculate area
            int area = length * heights[j];

            // save the largest area
            if(area > max)
                max = area;
        }
        cout << max << endl;
    }
}