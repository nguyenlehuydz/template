#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P { 
    ll x, y; 
};

ll dist2(const P &a, const P &b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx*dx + dy*dy;
}

// brute force cho n nhỏ
ll brute(vector<P>& pts, int l, int r){
    ll best = LLONG_MAX;
    for(int i=l;i<=r;i++)
        for(int j=i+1;j<=r;j++)
            best = min(best, dist2(pts[i], pts[j]));
    return best;
}

// tìm gần nhất trong [l..r] trên mảng pts sắp theo x
// trả về (best_distance_squared, and also fill aux vector sorted by y)
ll solve_rec(vector<P>& pts, int l, int r, vector<P>& aux){
    int n = r - l + 1;
    if(n <= 3){
        // tạo aux là danh sách theo y
        aux.clear();
        for(int i=l;i<=r;i++) aux.push_back(pts[i]);
        sort(aux.begin(), aux.end(), [](const P &a,const P &b){ return a.y < b.y; });
        return brute(pts, l, r);
    }
    int mid = (l + r) >> 1;
    ll midx = pts[mid].x;
    vector<P> leftY, rightY;
    ll dl = solve_rec(pts, l, mid, leftY);
    ll dr = solve_rec(pts, mid+1, r, rightY);
    ll d = min(dl, dr);

    // merge leftY and rightY (both sorted by y) -> aux (sorted by y)
    aux.clear();
    aux.reserve(leftY.size() + rightY.size());
    int i = 0, j = 0;
    while(i < (int)leftY.size() && j < (int)rightY.size()){
        if(leftY[i].y < rightY[j].y) aux.push_back(leftY[i++]);
        else aux.push_back(rightY[j++]);
    }
    while(i < (int)leftY.size()) aux.push_back(leftY[i++]);
    while(j < (int)rightY.size()) aux.push_back(rightY[j++]);

    // build strip (the points in aux with |x - midx| < sqrt(d))
    vector<P> strip;
    strip.reserve(aux.size());
    for(const P &p : aux){
        ll dx = p.x - midx;
        // compare dx*dx < d to avoid sqrt
        if(dx*dx < d) strip.push_back(p);
    }

    // check each point with up to next 7 points in strip
    for(size_t a=0; a<strip.size(); ++a){
        for(size_t b=a+1; b<strip.size() && b <= a+7; ++b){
            ll dy = strip[b].y - strip[a].y;
            if(dy*dy >= d) break; // no need further
            d = min(d, dist2(strip[a], strip[b]));
        }
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin >> n)) return 0;
    vector<P> pts(n);
    for(int i=0;i<n;i++) cin >> pts[i].x >> pts[i].y;
    sort(pts.begin(), pts.end(), [](const P &a, const P &b){
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    vector<P> aux;
    ll best2 = solve_rec(pts, 0, n-1, aux);
    cout << fixed << setprecision(6) << sqrt((long double)best2) << "\n";
    return 0;
}
