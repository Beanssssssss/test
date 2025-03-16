#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void Tpsort(vector<vector<int>> &vec, int N){
    vector<int> degree(N , 0);
    queue<int> q;
    for(int i = 0; i < N; i++){
        for(int j : vec[i]){
            degree[j]++;
        }
    }
    for(int i = 0; i < N; i++){
        if(degree[i] == 0)
            q.push(i);
    }
    vector<int> result;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node + 1);
        for(int v : vec[node]){
            if(--degree[v] == 0)
                q.push(v);
        }
    }
    for(int i = 0; i < N; i++){
        cout << result[i] << " ";
    }
    cout << endl;
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N);
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        v[A - 1].push_back(B - 1);
    }
    Tpsort(v, N);
    return 0;
}