#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maketable(string pattern){
    int ptsize = pattern.size();
    vector<int> table(ptsize, 0);
    int j = 0;
    for(int i = 1; i < ptsize; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j - 1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return *max_element(table.begin(), table.end());
}
int main(){
    string s;
    cin >> s;
    int max = 0;
    for(int i = 0; i < s.size(); i++){
        int k = maketable(s.substr(i));
        if(k > max) max = k;
    }
    
    cout << max << endl;
}