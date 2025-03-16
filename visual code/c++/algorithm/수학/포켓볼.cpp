#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<int> triangularNumbers;
unordered_set<int> perfectSquares;

void preprocess(int limit) {
    for (int i = 1;; i++) {
        int tri = (i * (i + 1)) / 2;
        if (tri > limit) break;
        triangularNumbers.push_back(tri);
    }

    for (int i = 1; i * i <= limit; i++) {
        perfectSquares.insert(i * i);
    }
}

int countValidX(int a, int b) {
    int count = 0;
    for (int x : triangularNumbers) {
        if (x >= b - 1) break;
        if (x >= a && perfectSquares.count(x + 1)) {
            count++;
        }
    }
    return count;
}

int main() {
    preprocess(1e9);

    int a, b, caseNum = 0;
    
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        
        int count = countValidX(a, b);
        cout << "Case " << ++caseNum << ": " << count << "\n";
    }

    return 0;
}