#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    int id;
    int score;
};
vector<struct student> val;

int cmp(const struct student &s1, const struct student &s2) {
    if (s1.score != s2.score) return s1.score > s2.score;
    else return s1.id < s2.id;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int num = m * 1.5;
    for (int i = 0; i < n; i ++) {
        int t1, t2;
        cin >> t1 >> t2;
        struct student temp;
        temp.id = t1;
        temp.score = t2;
        val.push_back(temp);
    }
    sort(val.begin(), val.end(), cmp);
    int score = val[num-1].score;
    int nn = 0;
    for (int i = 0; val[i].score >= val[num-1].score; i ++) {
        nn ++;
    }
    cout << val[num-1].score  << " " << nn << endl;
    for (int i = 0; val[i].score >= val[num-1].score; i ++) {
        cout << val[i].id << " " << val[i].score << endl;
    }
    return 0;
}