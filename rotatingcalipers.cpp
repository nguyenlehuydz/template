long long rotatingCalipers(vector<Point> P) {
    int n = P.size();
    if (n == 2) return dist2(P[0], P[1]);
    long long res = 0;
    int j = 1;
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        while (abs(cross(P[i], P[ni], P[(j+1)%n])) > abs(cross(P[i], P[ni], P[j])))
            j = (j + 1) % n;
        res = max(res, dist2(P[i], P[j]));
    }
    return res;
}
