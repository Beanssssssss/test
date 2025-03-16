#include <iostream>
using namespace std;
bool visited[4];
int main(){
    int N, M;
    cin >> N >> M;
    if(N == 1) cout << "1" << endl;
    else if(N == 2){
        if((M + 1) / 2 > 4) cout << 4 << endl;
        else cout << (M + 1) / 2 << endl;
    }
    else{
        if(M >= 7) cout << M - 2 << endl;
        else cout << min(M, 4) << endl;
    }
}