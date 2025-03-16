#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> width;
vector<int> height;
int w, h;

int main() {
    cin >> w >> h;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k, s;
        cin >> k >> s;
        if (k == 0) height.push_back(s);
        else width.push_back(s);
    }

    vector<int> answ, ansh;

    if (!width.empty()) {
        sort(width.begin(), width.end());
        answ.push_back(width[0]);  
        answ.push_back(w - width.back());
        for (int i = 1; i < width.size(); i++) {
            answ.push_back(width[i] - width[i - 1]);
        }
    } else {
        answ.push_back(w);
    }

    if (!height.empty()) {
        sort(height.begin(), height.end());
        ansh.push_back(height[0]);
        ansh.push_back(h - height.back());
        for (int i = 1; i < height.size(); i++) {
            ansh.push_back(height[i] - height[i - 1]);
        }
    } else {
        ansh.push_back(h);
    }

    int maxW = answ.empty() ? w : *max_element(answ.begin(), answ.end());
    int maxH = ansh.empty() ? h : *max_element(ansh.begin(), ansh.end());

    int result = maxW * maxH;
    cout << result << endl;

    return 0;
}