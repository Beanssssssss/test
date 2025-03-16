#include <iostream> 
#include <numeric>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 5001
using namespace std;
int r[MAX][MAX];
int n;
void FW(){
    vector<vector<int>> d(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = r[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][k] +  d[k][j] < d[i][j]){// i+1->k + 1갔다 k+1->j+1로 가는게 i+1->j+1
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int cnt[n];
    for(int i = 0; i < n; i++){
        cnt[i] = accumulate(d[i].begin(), d[i].end(), 0);
    }
    cout << (min_element(cnt, cnt + n) - cnt) + 1 << endl;
}
int main(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) r[i][j] = 0;
            else r[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        r[a - 1][b - 1] = 1;
        r[b - 1][a - 1] = 1;
    }
    FW();

    return 0;
}