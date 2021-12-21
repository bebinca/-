#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct stu{
    int id;
    int score;
    int power;
};
int cmp(const struct stu &s1, const struct stu &s2) {
    if (s1.score == s2.score) return s1.id < s2.id;
    else return s1.score > s2.score;
}
vector<struct stu> v;
int win[200010], lose[200010], res[200010];
int flag = 0;
void merge(int n) {
    int k = 0;
    for (int i = 0, j = 0; i < n || j < n; k ++) {
        if (i < n && ( j >= n || cmp(v[win[i]], v[lose[j]]) > 0)) { // i在前面
            res[k] = win[i]; i ++;
        } else if (j < n) {
            res[k] = lose[j]; j ++;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    int n, r, q;
    cin >> n >> r >> q;
    for (int i = 0; i < 2*n; i ++) {
        struct stu temp;
        int t;
        cin >> t;
        temp.id = i+1; temp.score = t;
        v.push_back(temp);
    }
    for (int i = 0; i < 2*n; i ++) {
        int t;
        cin >> t;
        v[i].power = t;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < n; j ++) {
            if (flag == 0) {
                if (v[2*j].power > v[2*j+1].power) {
                    v[2*j].score += 1;
                    win[j] = 2*j;
                    lose[j] = 2*j+1;
                }
                else {
                    v[2*j+1].score += 1;
                    win[j] = 2*j+1;
                    lose[j] = 2*j;
                }
            }
            if (flag == 1) {
                if (v[res[2*j]].power > v[res[2*j+1]].power) {
                    v[res[2*j]].score += 1;
                    win[j] = res[2*j];
                    lose[j] = res[2*j+1];
                }
                else {
                    v[res[2*j+1]].score += 1;
                    win[j] = res[2*j+1];
                    lose[j] = res[2*j];
                }
            }
        }
        merge(n);
        flag = 1;
    }
    cout << v[res[q-1]].id;
}