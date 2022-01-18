#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
double res(double n, double a, double b, double c, double d) {
    return a * n * n * n + b * n * n + c * n + d;
}
int equal(double a, double b) {
    a = a > 0.0 ? (a * 100 + 0.5) : (a * 100 - 0.5);
    b = b > 0.0 ? (b * 100 + 0.5) : (b * 100 - 0.5);
    int x = a, y = b;
    if (x == y) return 1;
    else return 0;
}
void find(double left, double right, double a, double b, double c, double d) {
    if (equal(left, right)) {printf("%.2lf ", right); return;}
    double mid = (left + right) / 2;
    double t1 = res(left,a,b,c,d), t2 = res(mid, a,b,c,d), t3 = res(right, a,b,c,d);
    if (t1 * t2 < 0) find(left,mid,a,b,c,d);
    else if (t2*t3 < 0) find(mid,right, a,b,c,d);
    else if (t2 == 0) {printf("%.2lf ", mid); return;}
}
int main() {
    int s = 0;
    std::ios::sync_with_stdio(false);
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    for (double i = -100; i < 100; i ++) {
        double t1 = res(i,a,b,c,d), t2 = res(i+1,a,b,c,d);
        if (t1 * t2 > 0) continue;
        else if (t1 == 0) {
            printf("%.2lf ", i);
            s ++;
            if (s == 3) break;
        }
        else if (t1 * t2 < 0) {
            find(i, i + 1, a, b, c, d);
            s ++;
            if (s == 3) break;
        }
    }
    return 0;
}