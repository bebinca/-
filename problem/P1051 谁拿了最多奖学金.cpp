#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int money(int *score) {
    int ret = 0;
    if (score[0] > 80 && score[4] > 0) {
        ret += 8000;
    }
    if (score[0] > 85 && score[1] > 80) {
        ret += 4000;
    }
    if (score[0] > 90) ret += 2000;
    if (score[0] > 85 && score[3] > 0) ret += 1000;
    if (score[1] > 80 && score[2] > 0) ret += 850;
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int max = 0;
    string maxname ="";
    int all = 0;
    for (int i = 0; i < n; i ++) {
        string tempname;
        cin >> tempname;
        int qwq[5] = {0};
        cin >> qwq[0] >> qwq[1];
        string t1, t2;
        cin>>t1 >>t2;
        if (t1 == "Y") {
            qwq[2] = 1;
        } else {
            qwq[2] = 0;
        }
        if (t2 == "Y") {
            qwq[3] = 1;
        } else {
            qwq[3] = 0;
        }
        cin >> qwq[4];
        int ret = money(qwq);
        all += ret;
        if (ret > max) {
            max = ret;
            maxname = tempname;
        }
    }
    cout << maxname << endl << max << endl << all;
    return 0;
}