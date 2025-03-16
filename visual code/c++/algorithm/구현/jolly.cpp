#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;
string ans;
int main(){
    string line;
    while(true){
        getline(cin, line);
        if(line.empty()) break;
        stringstream ss(line);
        vector<int> v;
        vector<int> a;
        int num;
        while(ss >> num){
            v.push_back(num);
        }
        for(int i = 2; i < v.size(); i++){
            a.push_back(abs(v[i] - v[i - 1]));
        }
        sort(a.begin(), a.end());
        string s = "Jolly";
        for(int i = 1; i < v[0]; i++){
            if(i != a[i - 1]){
                s = "Not jolly";
                break;
            }
        }
        ans += s + "\n";
    }
    cout << ans << endl;
    return 0;
}