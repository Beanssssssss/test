#include <iostream>
#include <vector>
#include <stack>

using namespace std;
string s;
vector<stack<int>> v(3);
bool findindstack(stack<int> s, int n){
    while(!s.empty()){
        if(s.top() == n) return true;
        s.pop();
    }
    return false;
}

int crazyhanoi(int n){
    int cnt = 0;
    if(findindstack(v[1], n)){
        while(v[1].top() != n){
            v[2].push(v[1].top());
            v[1].pop();
            s += "1 2\n";
            cnt++;
        }
        v[1].pop();
        cnt++;
        s += "1 3\n";
    } else{
        while(v[2].top() != n){
            v[1].push(v[2].top());
            v[2].pop();
            s += "2 1\n";
            cnt++;
        }
        v[2].pop();
        cnt++;
        s += "2 3\n";
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[1].push(x);
    }
    int ans = 0;
    for(int i = n; i > 0; i--){
        ans += crazyhanoi(i);
    }
    cout << ans << '\n';
    cout << s;
}