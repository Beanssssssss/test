#include <iostream>
#include <vector>
#include <stack>
#define MAX 100001
using namespace std;

int id = 0, d[MAX];
bool visited[MAX];
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;
int group[MAX];
bool degree[MAX];
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
            group[t] = SCC.size() + 1;
            visited[t] = true;
            if(t == x) break;
        }
        SCC.push_back(scc);
    }
    return parent;
}
int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N, M;
        cin >> N >> M;
        id = 0;
        fill(d, d + MAX, 0);
        fill(visited, visited + MAX, false);
        fill(group, group + MAX, 0);
        fill(degree, degree + MAX, false);
        SCC.clear();
        for(int i = 0; i <= N; i++){
            v[i].clear();
        }
        for(int i = 0; i < M; i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        for(int i = 1; i <= N; i++){
            if(d[i] == 0) dfs(i);
        }
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < v[i].size(); j++){
                int y = v[i][j];
                if(group[i] != group[y])
                    degree[group[y]] = true;
            }
        }
        int rst = 0;
        for(int i = 1; i <= SCC.size(); i++){
            if(!degree[i]) rst++;
        }
        cout << rst << endl;
    }
    return 0;
}