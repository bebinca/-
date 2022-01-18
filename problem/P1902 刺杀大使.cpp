#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstdio>
#include <cstring>
using namespace std;
int n, m;
int minn = 1000, maxx = 0;
int p[1010][1010] = {0};
int vis[1010][1010] = {0};
int flag = 0;
void bst(int i, int j, int dir, int val) {
    if (i < 0 || j < 0 || i >= n || j >= m || p[i][j] > val || vis[i][j]) return;
    if (i == n - 1) {flag = 1; return;}
    vis[i][j] = 1;
    bst(i+1, j, 0, val);
    if (flag == 1) return;
    bst(i, j-1, 3, val);
    if (flag == 1) return;
    bst(i, j+1, 1, val);
    if (flag == 1) return;
    bst(i-1, j, 2, val);
    if (flag == 1) return;
}
int judge(int x) {
    flag = 0;
    memset(vis,0,sizeof(vis));
    bst(0,0,0,x);
    return flag;
}
void find(int min, int max) {
    if (min == max || max - min == 1) {cout << max; return;}
    int mid = (min + max) / 2;
    if (judge(mid)) {
        find(min, mid);
    } else {
        find(mid, max);
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> p[i][j];
            if (p[i][j] > maxx) maxx = p[i][j];
            if (p[i][j] < minn) minn = p[i][j];
        }
    }
    if (judge(minn)) cout << minn;
    else find(minn, maxx);
}
