#include <iostream>
#include <vector>

using namespace std;
string str;
void Prime(int n) {
    vector<pair<int, int>> factors;
    if(n % 2 == 0)
        factors.push_back(make_pair(2, 0));
    while (n % 2 == 0) {
        factors[0].second++;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if(n % i == 0)
            factors.push_back(make_pair(i, 0));
        while (n % i == 0) {
            factors[factors.size() - 1].second++;
            n /= i;
        }
    }

    if (n > 1) {
        factors.push_back(make_pair(n , 1));
    }

    for (size_t i = 0; i < factors.size(); i++) {
       str += to_string(factors[i].first) + " " + to_string(factors[i].second);
       str += "\n";
    }

}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int N;
        cin >> N;
        Prime(N);
    }
    cout << str;
    return 0;
}