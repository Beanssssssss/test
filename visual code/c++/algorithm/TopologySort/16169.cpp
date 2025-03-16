#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Computer {
    int level;
    int time;
    int index;  // 컴퓨터 번호
};

int main() {
    int n;
    cin >> n;
    
    vector<Computer> computers(n);
    vector<int> max_time(n + 1, 0);
    vector<int> last_completed_computer(n + 1, 0);  // 각 레벨별로 마지막으로 완료된 컴퓨터 번호
    
    for (int i = 0; i < n; i++) {
        cin >> computers[i].level >> computers[i].time;
        computers[i].index = i + 1;  // 컴퓨터 번호는 1부터 시작
    }
    
    sort(computers.begin(), computers.end(), [](const Computer& a, const Computer& b) {
        return a.level < b.level;
    });
    
    int total_time = 0;
    for (int i = 0; i < n; i++) {
        int level = computers[i].level;
        int time = computers[i].time;
        if(max_time[level])
        max_time[level] = max(max_time[level], max_time[level - 1]) + time;
        total_time = max(total_time, max_time[level]);
        last_completed_computer[level] = computers[i].index;  // 해당 레벨에서 마지막으로 완료된 컴퓨터 번호 저장
    }
    for (int i = 1; i <= n; i++) {
        cout << last_completed_computer[i] << endl;
    }
    // 전송 시간 계산
    for (int level = 2; level <= n; level++) {
        int transfer_time = (last_completed_computer[level] - last_completed_computer[level - 1]) * (last_completed_computer[level] - last_completed_computer[level - 1]);
        total_time += transfer_time;
    }
    
    cout << total_time << endl;
    return 0;
}
