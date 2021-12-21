#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arr[500010], sor[500010];
long long ans = 0;
void mergesort(int s, int t) {
    if (s == t) return;
    int mid = (s+t)/2;
    mergesort(s, mid);
    mergesort(mid+1, t);
    int i, j, k;
    for (i = s, j = mid+1, k = s; i <= mid && j <= t; k ++) {
        if (arr[i] <= arr[j]) {sor[k] = arr[i]; i ++; }
        else if (arr[i] > arr[j]) {sor[k] = arr[j]; j ++; ans += (mid - i + 1);}
    }
    while(i <= mid) {
        sor[k++] = arr[i++];
    }
    while(j <= t) {
        sor[k++] = arr[j++];
    }
    for (int i = s; i <= t; i ++) {
        arr[i] = sor[i];
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &arr[i]);
    }
    mergesort(0, n-1);
    printf("%lld", ans);
}