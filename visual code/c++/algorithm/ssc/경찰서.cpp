#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int d[101];
bool c[101];
vector<int> a[101];
vector<vector<int>> SCC;
vector<int> cost(101, 0);
stack<int> stacks;
int n, id = 0;
int dfs(int x){
    d[x] = ++id;
    stacks.push(x);
    int parent = d[x];
    for(int i = 0; i < a[x].size(); i++){
        int y = a[x][i];
        if(d[y] == 0) parent = min(parent, dfs(y));
        else if(!c[y]) parent = min(parent, d[y]);
    }
    if(parent == d[x]){
        vector<int> scc;
        while(1){
            int t = stacks.top();
            stacks.pop();
            c[t] = true;
            scc.push_back(t);
            if(t == x) break;
        }
        SCC.push_back(scc);
    }
    return parent;
}
int main(){
    cin >> n;
    for(int i = 1; i < n + 1; i++){
        cin >> cost[i];
    }
    for(int i = 1; i < n + 1; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                a[i].push_back(j + 1);
            }
        }
    }
    for(int i = 1; i < n + 1; i++){
        if(d[i] == 0) dfs(i);
    }
    int totalcost = 0;
    for(int i = 0; i < SCC.size(); i++){
        int mincost = 1000000;
        for(int k : SCC[i]){
            if(cost[k] < mincost){
                mincost = cost[k];
            }
        }
        totalcost += mincost;
    }

    cout << totalcost << endl;
    return 0;
}