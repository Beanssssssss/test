#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
int d[1001];
bool c[1001];
int N, M;
bool dfs(int a){
    for(int i = 0; i < v[a].size(); i++){
        int t = v[a][i];
        if(c[t]) continue;
        c[t] = true;
        if(d[t] == 0 || dfs(d[t])){
            d[t] = a;
            return true;
        }
    }
    return false;
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        fill(c, c + M + 1, false);
        if(dfs(i)) cnt++;
    }
    for(int i = 1; i <= N; i++){
        fill(c, c + M + 1, false);
        if(dfs(i)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}