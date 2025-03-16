#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v;
void remove_str(const string& s) {
    string str = "";

    for (char c : s) {
        if (isdigit(c)) {
            str += c;
        } else if (!str.empty()) {
            while (str.length() > 1 && str[0] == '0') str.erase(0, 1);
            v.push_back(str);
            str = "";
        }
    }
    
    if (!str.empty()) {
        while (str.length() > 1 && str[0] == '0') str.erase(0, 1);
        v.push_back(str);
    }
}
bool compare(string &a, string &b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        remove_str(s);
    }
    sort(v.begin(), v.end(), compare);
    for(string x : v){
        cout << x << endl;
    }
    return 0;
}