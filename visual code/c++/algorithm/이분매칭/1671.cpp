#include <iostream>
#include <vector>

using namespace std;



vector<int> v[51];
int stat[51][3];
int d[51];
bool c[51];

bool dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        int t = v[x][i];
        if (c[t]) continue;
        c[t] = true;
        if (d[t] == 0 || dfs(d[t])) {
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stat[i][0] >> stat[i][1] >> stat[i][2];
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            if(stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]){
                v[i].push_back(j);
            }
            else if(stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]){
                v[i].push_back(j);
            }
            else if(stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]){
                v[j].push_back(i);
            }
        }
    }

    int cnt = 0;
    for(int k = 0; k < 2; k++){
        for (int i = 1; i <= N; i++) {
            fill(c, c + N + 1, false);
            if (dfs(i)) cnt++;
        }
    }
    cout << N - cnt << endl;
    return 0;
}