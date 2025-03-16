#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getmin(vector<string > v, int k){
    vector<char> vc;
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++){
        vc.insert(vc.end(), v[i].begin(), v[i].end());
    }
    sort(vc.begin(), vc.end());
    for(char c : vc){
        cout << c;
    }
    cout << endl;
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> vec;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        vec.push_back(s);
    }
    getmin(vec, k);
    return 0;
}