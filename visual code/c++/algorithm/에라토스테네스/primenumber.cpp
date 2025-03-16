#include <iostream>
#include <vector>

using namespace std;

void sieve(int N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false; 

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) { 
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    sieve(N);
    return 0;
}