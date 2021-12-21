#include <iostream>
#include <vector>
using namespace std;
int arr[100000] = {0};

void quickSort1(int begin, int end, int* arr) {
    int i = begin, j = end;
    int mid = arr[(i+j)/2];
    while(i <= j) {              // 有等号是为了让i++, j--, 分散到mid两边
        while(arr[i] < mid) i ++;
        while(arr[j] > mid) j --;
        if (i <= j) {           // 有等号是因为在mid两边遇到=mid的值时也要继续前进
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i ++;
            j --;
        }
    }
    if(begin < j)quickSort1(begin, j, arr);
    if(i < end)quickSort1(i, end, arr);
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        arr[i] = temp;
    }
    quickSort1(0, n-1, arr);
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
}
// sb写法
void quickSort(int begin, int end, int key, int* arr) {
    if (begin >= end) return;
    int i = begin, j = end;
    while(j!= i) {
        for (; j > key; j --) {
            if (arr[j] < arr[key]) {
                int temp = arr[j];
                arr[j] = arr[key];
                arr[key] = temp;
                key = j;
                break;
            }
        }
        for (; i < key; i ++) {
            if (arr[i] > arr[key]) {
                int temp = arr[i];
                arr[i] = arr[key];
                arr[key] = temp;
                key = i;
                break;
            }
        }
    }
    quickSort(begin, key-1, begin, arr);
    quickSort(key+1, end, key+1, arr);
    return;
}
