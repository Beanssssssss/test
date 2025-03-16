#include <iostream>
#include <vector>

using namespace std;

vector<int> v[201];
int d[201];
bool c[201];
int N, M;
bool dfs(int x){
    for(int i = 0; i < v[x].size(); i++){
        int t = v[x][i];
        if(c[t]) continue;
        c[t] = true;
        if(d[t] == 0 || dfs(d[t])){
            d[t] = x;
            return true;
        }
    }
    return false;
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        int s;
        cin >> s;
        for(int j = 0; j < s; j++){
            int k;
            cin >> k;
            v[i].push_back(k);
        }
    }
    int count = 0;
    for(int i = 1; i <= N; i++){
        fill(c, c + M + 1, false);
        if(dfs(i)) count++;
    }
    cout << count << endl;
    return 0;
}