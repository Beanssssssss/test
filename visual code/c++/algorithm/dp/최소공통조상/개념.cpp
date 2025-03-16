#include <iostream>
#include <vector>
#define MAX 1001
#define LOG 11
using namespace std;

int n, m, parent[MAX][LOG], d[MAX];
bool c[MAX];
vector<int> a[MAX];
//바로 위 부모 찾기
void dfs(int x, int depth){
    c[x] = true;
    d[x] = depth;
    for(int i = 0; i < a[x].size(); i++){
        int y = a[x][i];
        if(c[y]) continue;
        parent[y][0] = x;
        dfs(y, depth + 1);
    }
}
void setParent(){
    dfs(0, 0);
    for(int j = 1; j < LOG; j++){
        for(int i = 0; i < n; i++){
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}
int LCA(int x, int y){
    if(d[x] > d[y]){
        swap(x, y);
    }
    for(int i = LOG - 1; i >= 0; i--){
        if(d[y] - d[x] >= (1 << i)){
            y = parent[y][i];
        }
    }
    if(x == y) return x;
    for(int i = LOG - 1; i >= 0; i--){
        if(parent[x][i] != parent[y][i]){
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}
int main(){
    n = 21;
    a[0].push_back(1);
    a[1].push_back(0);

    a[0].push_back(2);
    a[2].push_back(0);

    a[1].push_back(3);
    a[3].push_back(1);

    a[1].push_back(4);
    a[4].push_back(1);

    a[2].push_back(5);
    a[5].push_back(2);

    a[2].push_back(6);
    a[6].push_back(2);

    a[3].push_back(7);
    a[7].push_back(3);
    
    a[3].push_back(8);
    a[8].push_back(3);

    a[4].push_back(9);
    a[9].push_back(4);

    a[4].push_back(10);
    a[10].push_back(4);

    setParent();

}