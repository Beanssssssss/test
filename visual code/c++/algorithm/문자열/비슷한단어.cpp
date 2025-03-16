#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<multiset<char>> vec(101);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        vec[i] = multiset<char>(s.begin(), s.end());
    }
    int result = 0;
    vector<vector<char>> v;
    for (int i = 1; i < n; i++) {
        if(abs((int)vec[i].size() - (int)vec[0].size()) > 1) continue;
        multiset<char> set0;
        multiset<char> seti;
        set_difference(vec[0].begin(), vec[0].end(), vec[i].begin(), vec[i].end(), inserter(set0, set0.begin()));
        set_difference(vec[i].begin(), vec[i].end(), vec[0].begin(), vec[0].end(), inserter(seti, seti.begin()));
        if(set0.size() <= 1 && seti.size() <= 1){
            result++;
        }
    }
    cout << result << endl;
    return 0;
}