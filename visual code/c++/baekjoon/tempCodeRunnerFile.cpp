#include <iostream>
#include <vector>
using namespace std;
void PrimeNum(int M, int N){
    vector<int> v(N + 1, 1);
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i * i <= N; i++) {
        if (v[i] == 1){
            for(int j = i * i; j <= N; j += i){
                v[j] = 0;
            }
        }
    }
    for(int i = M; i <= N; i++){
        if(v[i] == 1)
            cout << i << endl;
    }
}
int main(){
    int M, N;
    cin >> M >> N;
    PrimeNum(M, N);
    return 0;
}