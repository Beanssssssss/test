#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
vector<int> vec[MAX];
vector<bool> c(MAX, false);
int check[MAX];
int idx = 0;
void dfs(int start){
    c[start] = true;
    check[start] = ++idx;
    for(int next : vec[start]){
        if(!c[next]) dfs(next);
    }
}
int compare(int a, int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m ,r;
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(vec[i].begin(), vec[i].end(), compare);
    }
    dfs(r);
    for(int i = 1; i <= n; i++){
        cout << (check[i] > 0 ? check[i] : 0) << "\n";
    }
    return 0;
}