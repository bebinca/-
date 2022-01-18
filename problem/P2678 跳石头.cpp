#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int d[60000] = {0};
int l, n, m, minn;
int judge(int x) {
    int res = 0;
    int ll = 0, rr = 1;
    while(ll <= n+1 && rr <= n+1) {
        int dis = ll == 0 ? d[rr-1] : d[rr-1] - d[ll-1];
        if (dis >= x) {
            ll = rr, rr = rr + 1;
        } else {
            res ++;
            rr = rr + 1;
            if (res > m) return 0;
        }
    }
    if (res > m) return 0;
    return 1;
}
void find(int left, int right) {
    if (left == right || right - left == 1) {cout << left; return;}
    int mid = (left + right) / 2;
    if (judge(mid)) {
        find(mid, right);
    } else {
        find(left, mid);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> l >> n >> m;
    minn = l;
    for (int i = 0; i < n; i ++) {
        cin >> d[i];
        if (i == 0 && d[i] < minn) minn = d[i];
        else if (i > 0 && d[i] - d[i-1] < minn) minn = d[i] - d[i-1];
    }
    d[n] = l;
    if(l - d[n-1] < minn) minn = l - d[n-1];
    if (judge(l)) cout << l;
    else {
        find(minn, l);
    }
}