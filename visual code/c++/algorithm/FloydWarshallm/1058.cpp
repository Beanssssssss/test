#include <iostream>

using namespace std;
int **a;
void FloydWarshall(int N){
    int d[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            d[i][j] = a[i][j];
        }
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(d[i][k] +  d[k][j] < d[i][j]){// i+1->k + 1갔다 k+1->j+1로 가는게 i+1->j+1
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    
    int maxcnt = 0;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j= 0; j < N; j++){
            if(i == j) continue;
            if(d[i][j] <= 2) cnt++;
        }
        if(cnt > maxcnt){
            maxcnt = cnt;
        }
    }
    cout << maxcnt << endl;
}
int main(){
    int N;
    cin >> N;
    a = new int*[N];
    for(int i = 0; i < N; i++){
        a[i] = new int[N];
    }
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < N; j++){
            if(str[j] == 'Y'){
                a[i][j] = 1;
            } else{
                a[i][j] = 10000;
            }
        }
    }
    FloydWarshall(N);
}