#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void TpSort(vector<vector<int>> &vec, int N){
    vector<int> degree(N, 1);
    vector<int> Max(N , 1);
    queue<int> pq;
    for(int i = 0; i < N; i++){
        for(int j : vec[i]){
            degree[j] = 1;
            degree[j] += Max[i];
            if(degree[j] > Max[j]){
                Max[j] = degree[j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << Max[i] << " ";
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
    TpSort(v, N);
}