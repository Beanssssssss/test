#include <iostream>
#include <vector>
using namespace std;
vector<int> v[101];
bool visited[101];
int dfs(int start, int end, int cnt){
    visited[start] = true;
    if(start == end) return cnt;
    for(int next : v[start]){
        if(!visited[next]){
            int result = dfs(next, end, ++cnt);
            if(result != -1) return result;
            else --cnt;
        }
    }
    
    return -1;
}
int main(){
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << dfs(a, b, 0) << endl;
    return 0;
}
