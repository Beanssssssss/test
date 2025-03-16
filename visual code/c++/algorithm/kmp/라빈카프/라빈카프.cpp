#include <iostream>
#include <string>
using namespace std;

const int d = 256;  // 알파벳 개수
const int q = 101;  // 소수 (해시 충돌 방지)

void rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int h = 1;
    int p = 0, t = 0; // 패턴 해시값(p)과 텍스트 현재 해시값(t)

    // 해시값을 계산할 때 사용될 h = d^(m-1) % q 값 구하기
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // 패턴과 첫 번째 윈도우의 해시값 계산
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // 슬라이딩 윈도우로 비교
    for (int i = 0; i <= n - m; i++) {
        // 해시값이 같으면 실제 문자열 비교
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) cout << "패턴 발견 at index " << i << endl;
        }

        // 다음 윈도우의 해시값 업데이트 (롤링 해시)
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;  // 해시 값이 음수가 되지 않도록 처리
        }
    }
}

int main() {
    string text = "ababacabacaabacaaba";
    string pattern = "abacaaba";

    rabinKarp(text, pattern);

    return 0;
}