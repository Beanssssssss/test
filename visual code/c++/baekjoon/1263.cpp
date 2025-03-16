// 백준 1263번 시간관리<골드5>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check[1000001];
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    int N;
    cin >> N;
    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++)
    {
        int T, S;
        cin >> T >> S;
        v.push_back(make_pair(T, S));
    }
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < N; i++) {
        int time = v[i].second;
        int total = v[i].first;
        int cnt = 0;
        for(int j = time - 1; j >= 0; j--) {
            if(cnt == total) break;
            if(!check[j]){
                check[j] = true;
                cnt++;
            }
        }
        if(cnt < total){
            cout << -1;
            return 0;
        }

    }
    for(int i = 0; i < 1000001; i++) {
        if(check[i]) {
            cout << i << endl;
            return 0;   
        }
    }
    return 0;
}