#include <iostream>
#include <vector>

using namespace std;

int main(){
    // input test cases
    int c;
    cin >> c;
    while(c--){
        string input;
        vector<int> idols, fans;
        // input idols
        cin >> input;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == 'M')
                idols.push_back(1);
            else
                idols.push_back(0);
        }
        // input fans
        cin >> input;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == 'M')
                fans.push_back(1);
            else
                fans.push_back(0);
        }

        int hugs = 0;
        // exception : idols are greater than fans
        if(idols.size() > fans.size())
            cout << 0 << endl;
        else{
            // for each hugging incidents
            for(int i = 0; i < fans.size() - idols.size() + 1; i++){
                // check if M - M hugging occurs
                int j = 0;
                for(; j < idols.size(); j++){
                    if(idols[j] * fans[i + j]){
                        break;
                    }
                }
                // no M - M hugging occurred
                if(j == idols.size())
                    hugs++;
            }
            cout << hugs << endl;
        }
        
    }
    return 0;
}