#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

long long area(Point a, Point b, Point c) {
    // giá trị "diện tích có dấu" của tam giác ABC
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool onSegment(Point a, Point b, Point c) {
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

bool intersect(Point a, Point b, Point c, Point d) {
    long long s1 = area(a, b, c);
    long long s2 = area(a, b, d);
    long long s3 = area(c, d, a);
    long long s4 = area(c, d, b);

    // kiểm tra hai phía khác nhau
    if (s1 * s2 < 0 && s3 * s4 < 0) return true;

    // kiểm tra các trường hợp thẳng hàng
    if (s1 == 0 && onSegment(a, b, c)) return true;
    if (s2 == 0 && onSegment(a, b, d)) return true;
    if (s3 == 0 && onSegment(c, d, a)) return true;
    if (s4 == 0 && onSegment(c, d, b)) return true;

    return false;
}

int main() {
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    cout << (intersect(A, B, C, D) ? "YES\n" : "NO\n");
}
