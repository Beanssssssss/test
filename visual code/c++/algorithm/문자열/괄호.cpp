#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
string result;
void checkVPS(string str){

    // 짝이 맞는지
    if(str.length() % 2 != 0){
        result += "NO\n";
        return;
    }
    //개수 맞는지
    char target = '(';
    int check_count = count(str.begin(), str.end(), target);
    if(check_count != str.length() / 2){
        result += "NO\n";
        return;
    }
    // 쌍을 이루는지
    stack<char> stk;
    
    for (char c : str) {
        if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            if (!stk.empty() && stk.top() == '(') {
                stk.pop();  // 올바른 짝이면 스택에서 제거
            } else {
                result += "NO\n";
                return;
            }
        }
    }
    if (stk.empty()) {
        result += "YES\n";
    } else {
        result += "NO\n";
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        checkVPS(s);
    }
    cout << result;
    return 0;
}