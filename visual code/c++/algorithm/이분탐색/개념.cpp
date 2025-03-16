#include <iostream>
#define N 12
using namespace std;

int a[] = {1 ,3 ,5 ,7 ,9, 11, 14, 15, 18, 19, 25, 28};
int t = 7;
int search(int start, int end, int target){
    if(start > end) return -1;
    int mid = (start + end) / 2;
    if(a[mid] == target) return mid;
    else if(a[mid] > target) return search(start, mid - 1, target);
    else return search(mid + 1, end, target);
}
int main(){
    int result = search(0, N - 1, t);
    if(result != -1){
        cout << result + 1 << endl;
    }
}