#include <iostream>
#include <algorithm>
using namespace std;

void stringmaker(string s) {
    int maxLen = 1;

    for (size_t i = 0; i < s.length(); i++) {
        string sub = s.substr(i); 
        string rev_sub = sub;
        reverse(rev_sub.begin(), rev_sub.end());

        if (sub == rev_sub) {
            maxLen = max(maxLen, (int)sub.length());
        }
    }

    int len = (s.length() - maxLen) * 2;
    cout << maxLen + len << endl;
}

int main() {
    string str;
    cin >> str;
    stringmaker(str);
    return 0;
}
