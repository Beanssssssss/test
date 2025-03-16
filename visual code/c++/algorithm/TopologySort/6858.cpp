#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void Tpsort(vector<vector<int>> &vec){
    vector<int> degree(7, 0);
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < 7; i++){
        for(int j : vec[i]){
            degree[j]++;
        }
    }
    for (int i = 0; i < 7; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while(!q.empty()){
        int node = q.top();
        q.pop();
        result.push_back(node + 1);
        for(int v : vec[node]){
            if(--degree[v] == 0){
                q.push(v);
            }
        }
    }
     if (result.size() == 7) {
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "Cannot complete these tasks. Going to bed." << endl;
    }
}

int main(){
    vector<vector<int>> v(7);
    v[0].push_back(6);
    v[0].push_back(3);
    v[1].push_back(0);
    v[2].push_back(3);
    v[2].push_back(4);
    for(int i = 0; i < 10; i++){
        int n, m;
        cin >> n;
        cin >> m;
        if(n + m == 0) break;
        v[n - 1].push_back(m -1);
    }
    Tpsort(v);
    return 0;
}