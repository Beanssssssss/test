#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<bool> is_prime;
unordered_set<int> d = {2, 3, 5, 7, 11, 13};

int count_prime_factors(int n) {
    int cnt = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if(n < i) break;
    }
    if (n > 1) cnt++;
    return cnt;
}

int main() {
    int a, b;
    cin >> a >> b;

    is_prime.assign(b + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= b; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= b; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int total_cnt = 0;
    for (int i = a; i <= b; i++) {
        if (!is_prime[i]) {
            int factor_cnt = count_prime_factors(i);
            if (d.count(factor_cnt)) total_cnt++;
        }
    }

    cout << total_cnt << endl;
    return 0;
}