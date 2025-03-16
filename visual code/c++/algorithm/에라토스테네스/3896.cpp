#include <iostream>
#include <string>

using namespace std;

string str;

bool IsPrime(int x){
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for(int i = 3; i * i <= x; i += 2){
        if(x % i == 0) return false;
    }
    return true;
}
void CountPrime(int n){
    int start = 0, end = 0;
    for(int i = n; i <= 1299709; i++){
        if(IsPrime(i) != 0){
            end = i;
            break;
        }
    }
    for(int i = n; i > 1; i--){
        if(IsPrime(i) != 0){
            start = i;
            break;
        }
    }
    str += to_string(end - start) + " \n";
}
int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        if(!IsPrime(N))
            CountPrime(N);
        else{
            str += "0 \n";
        }
    }
    cout << str;
}