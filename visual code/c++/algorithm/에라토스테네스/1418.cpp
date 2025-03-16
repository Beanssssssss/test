#include <iostream>
#include <vector>

using namespace std;

int countK(int N, int K) {
    vector<int> max_prime(N + 1, 0);

    for (int i = 2; i <= N; i++) {
        if (max_prime[i] == 0) {
            for (int j = i; j <= N; j += i) {
                max_prime[j] = i;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (max_prime[i] <= K) count++;
    }
    
    return count;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << countK(N, K) << endl;
    return 0;
}