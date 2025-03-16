#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 10001
int id = 0, d[MAX];
bool visited[MAX];
vector<int> v[MAX];
vector<vector<int>> SCC;
bool compareSCC(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
stack<int> s;
int dfs(int x){
    d[x] = ++id;
    s.push(x);
    int parent = d[x];
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        if(d[y] == 0) parent = min(parent, dfs(y));
        else if(!visited[y]) parent = min(parent, d[y]);
    }
    if(parent == d[x]){
        vector<int> scc;
        while(1){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            visited[t] = true;
            if(t == x) break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }
    return parent;
}
int main(){
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= V; i++){
        if(d[i] == 0) dfs(i);
    }
    sort(SCC.begin(), SCC.end(), compareSCC);
    cout << SCC.size() << endl;
    for(int i = 0; i < SCC.size(); i++){
        for(int j = 0; j < SCC[i].size(); j++){
            cout << SCC[i][j] << " ";
        }
        cout << -1 << endl;
    }
    return 0;
}