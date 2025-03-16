#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> maketable(string pattern){
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
    return table;
}
int main(){
    string s;
    cin >> s;
    vector<int> a = maketable(s);
    cout << *max_element(a.begin(), a.end()) << endl;
}