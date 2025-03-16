#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<char> stack;
    int to_remove = k;

    for (char c : s) {
        while (!stack.empty() && to_remove > 0 && stack.back() < c) {
            stack.pop_back();
            to_remove--;
        }
        stack.push_back(c);
    }

    while (to_remove > 0) {
        stack.pop_back();
        to_remove--;
    }

    for (char c : stack) cout << c;
    cout << endl;

    return 0;
}