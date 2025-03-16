#include <iostream>
#include <vector>
using namespace std;
void PrimeNum(int M, int N){
    vector<bool> v(N + 1, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (v[i] == 1){
            for(int j = i * i; j <= N; j += i){
                v[j] = 0;
            }
        }
    }
    for(int i = M; i <= N; i++){
        if(v[i] == true)
            cout << i << endl;
    }
}
int main(){
    int M, N;
    cin >> M >> N;
    PrimeNum(M, N);
    return 0;
}