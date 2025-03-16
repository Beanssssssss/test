#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

vector<int> a[MAX];
int degree[MAX];
int t[MAX];
vector<int> result(MAX);
int N, maxn = 0, maxi;
void tpsort(){
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(degree[i] == 0)
            q.push(i);
            result[i] = t[i];
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int k : a[node]){
            result[k] = max(result[k], result[node] + t[k]);
            if(--degree[k] == 0){
                q.push(k);
            }
        } 
    }
    int max = 0;
    for(int i = 1; i <= N; i++){
        if(max < result[i])
            max = result[i];
    }
    cout << max << endl;
    
}
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        int cost, n;
        scanf("%d %d", &cost, &n);
        t[i] = cost;
        for(int j = 0; j < n; j++){
            int x;
            scanf("%d" , &x);
            a[x].push_back(i);
            degree[i]++;
        }
    }
    tpsort();
    return 0;
}
