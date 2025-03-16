#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
string s;
vector<pair<tuple<int, int, int>, long>> dp;

long w(int a, int b, int c) {
    tuple<int, int, int> key = {a, b, c};

    for (auto &p : dp) {
        if (p.first == key) return p.second;
    }

    long result;
    if (a <= 0 || b <= 0 || c <= 0) {
        result = 1;
    }
    else if (a > 20 || b > 20 || c > 20) {
        result = w(20, 20, 20);
    }
    else if (a < b && b < c) {
        result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else {
        result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    dp.push_back({key, result});
    return result;
}

int main() {
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        s +=  "w(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ") = " + to_string(w(a, b, c)) + "\n";
    }
    cout << s;
    return 0;
}