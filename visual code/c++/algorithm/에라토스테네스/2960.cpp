#include <iostream>
#include <vector>
using namespace std;
int Prime(int N, int K){
    vector<int> v(N + 1, 1);
    int cnt = 0;
    for(int i = 2; i <= N; i++){
        if(v[i] == 1){
            for(int j = i; j <= N; j+= i){
                if(v[j] == 0) continue;
                v[j] = 0;
                cnt++;
                if(cnt == K) {
                    return j;
                }
            }
        }
    }
    return 0;
}
int main(){
    int N, K;
    cin >> N >> K;
    cout << Prime(N, K) << endl;
    return 0;
}