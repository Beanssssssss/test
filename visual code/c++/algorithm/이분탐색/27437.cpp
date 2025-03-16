#include <iostream>

using namespace std;
string check(long long n, long long idx){
long long up, down;
    if(n % 2 == 0){
        up = n - idx;
        down = (n + 1) - up;
    } else{
        down = n -idx;
        up = (n + 1) - down;
    }
    return to_string(up) + "/" + to_string(down);
}
int main(){
    long long x;
    cin >> x;
    long long sum = 0;
    string s;
    for(long long i = 1; i <= x; i++){
        sum += i;
        if(sum >= x) {
            s = check(i, sum - x);
            break;
        }
    }
    cout << s << endl;
}