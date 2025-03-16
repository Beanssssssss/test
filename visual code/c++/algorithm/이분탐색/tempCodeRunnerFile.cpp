#include <iostream>

using namespace std;
string check(int n, int idx){
    int up, down;
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
    int x;
    cin >> x;
    int sum = 0;
    string s;
    for(int i = 1; i <= x; i++){
        sum += i;
        if(sum >= x) {
            s = check(i, sum - x);
            break;
        }
    }
    cout << s << endl;
}