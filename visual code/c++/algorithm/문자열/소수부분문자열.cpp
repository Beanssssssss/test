#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
string result;
void primeNum(string str){
    vector<int> v;
    
    for(int i = 1; i <= str.size(); i++){
        if(i > 6) break;
        for(int j = 0; j + i <= str.size(); j++){
            int x = stoi(str.substr(j, i));
            if(x > 100000) break;
            v.push_back(stoi(str.substr(j, i)));
        }
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = 2; j * j <= v[i]; j++){
            if(v[i] % j == 0){
                v[i] = 1;
                break;
            }
        }
    }
    auto it = max_element(v.begin(), v.end());
    result += to_string(*it);
    result += "\n";
}
int main(){
    while(true){
        string s;
        cin >> s;
        if(s == "0") break;
        primeNum(s);
    }
    cout << result;
    return 0;
}