#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    unordered_set<string> setn;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        setn.insert(s);
    }
    int cnt = 0;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(setn.find(s) != setn.end()) cnt++;  
    }
    cout << cnt << endl;
    return 0;
}