#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstdio>
#include <cstring>
using namespace std;
int n, m;
int r[1000010];
int d[1000010], s[1000010], t[1000010];
int diff[1000010] = {0};
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i ++) {
        cin >> d[i] >> s[i] >> t[i];
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    int res = 0;
    int temp = m;
    for (int i = 1; i <= n; i ++) {
        int qwq = res + diff[i];
        while(qwq > r[i]) {
            diff[s[temp]] -= d[temp];
            diff[t[temp] + 1] += d[temp];
            if (s[temp] <= i && t[temp] >= i) {
                qwq -= d[temp];
            } 
            temp --;
        }
        res = qwq;
    }
    if (temp != m) {
        cout << -1 << endl << temp + 1;
    } else {
        cout << 0;
    }
}
