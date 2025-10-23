#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

// Kiểm tra điểm P có nằm trên đoạn AB không
bool onSegment(Point A, Point B, Point P) {
    double cross = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    if (fabs(cross) > 1e-9) return false; // Không thẳng hàng
    if (min(A.x, B.x) - 1e-9 <= P.x && P.x <= max(A.x, B.x) + 1e-9 &&
        min(A.y, B.y) - 1e-9 <= P.y && P.y <= max(A.y, B.y) + 1e-9)
        return true;
    return false;
}

// Hàm kiểm tra P có nằm trong đa giác không
bool inPolygon(vector<Point> poly, Point P) {
    int n = poly.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        Point A = poly[i], B = poly[j];

        // Nếu nằm trên cạnh
        if (onSegment(A, B, P)) return true;

        // Xét giao điểm với tia song song Ox
        bool intersect = ((A.y > P.y) != (B.y > P.y)) &&
                         (P.x < (B.x - A.x) * (P.y - A.y) / (B.y - A.y) + A.x);
        if (intersect)
            inside = !inside;
    }
    return inside;
}

int main() {
    vector<Point> poly = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    Point P = {5, 5};
    
    if (inPolygon(poly, P))
        cout << "YES\n";
    else
        cout << "NO\n";
}
