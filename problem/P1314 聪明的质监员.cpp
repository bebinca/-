#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstdio>
#include <cstring>
using namespace std;
int n, m;
long long s;
int w[200010], v[200010];
vector<int> w1;
int l[200010], r[200010];
long long vall[200010], posit[200010];
long long cal(int para) {
    memset(vall, 0, sizeof(vall));
    memset(posit, 0, sizeof(posit));
    long long t1 = 0, t2 = 0;
    for (int i = 1; i <= n; i ++) {
        if (w[i-1] >= para) {
            t1 = t1 + 1;
            t2 = t2 + v[i-1];
        }
        posit[i] = t1;
        vall[i] = t2;
    }
    long long res = 0;
    for (int i = 0; i < m; i ++) {
        res = res + (posit[r[i]] - posit[l[i]-1]) * (vall[r[i]] - vall[l[i]-1]);
    }
    return res - s;
}
void find(int left, int right, long long lv, long long rv) {
    if (left == right) {
        cout << abs(lv);
        return;
    }
    if (right - left == 1) {
        long long a1 = abs(lv), a2 = abs(rv);
        cout << (a1 < a2 ? a1 : a2);
        return;
    }
    int mid = (left + right) / 2;
    long long val = cal(w1[mid]);
    if (val > 0) { // >s
        find(mid, right, val, rv);
    } else if (val < 0) { // <s
        find(left, mid, lv, val);
    } else { // ==s
        cout << 0;
        return;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    for (int i = 0; i < n; i ++) {
        cin >> w[i] >> v[i];
        w1.push_back(w[i]);
    }
    sort(w1.begin(), w1.end());
    for (int i = 0; i < m; i ++) {
        cin >> l[i] >> r[i];
    }
    long long n1 = cal(w1[0]), n2 = cal(w1[n-1]);
    if (n1 == 0 || n2 == 0) {
        cout << 0;
    } else if (n1 > 0 && n2 > 0) {
        cout << n2;
    } else if (n1 < 0 && n2 < 0) {
        cout << -n1;
    } else {
        find(0, n-1, n1, n2);
    }
}
