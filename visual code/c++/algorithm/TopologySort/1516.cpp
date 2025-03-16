#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int *degree;
int *timecheck;
int *result;
void tpsort(vector<vector<int>> &vec, int N){
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(degree[i] == 0)
            q.push(i);
            result[i] = timecheck[i];
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int x : vec[node]){
            result[x] = max(result[x], result[node] + timecheck[x]);
            if(--degree[x] == 0) q.push(x);
        }
    }
    for(int i = 0; i < N; i++){
        printf("%d\n", result[i]);
    }
}
int main(){
    int N;
    scanf("%d", &N);
    degree = new int[N];
    timecheck = new int[N];
    result = new int[N];
    vector<vector<int>> v(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &timecheck[i]);
        while(true){
            int x;
            scanf("%d", &x);
            if(x == -1) break;
            degree[i]++;
            v[x - 1].push_back(i);
        }
    }
    tpsort(v, N);
    delete[] degree;
    delete[] timecheck;
    delete[] result;

    return 0;
}