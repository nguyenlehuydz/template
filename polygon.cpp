#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define Task "polygon"

typedef pair<int,int>ii;
typedef pair<ii,int>iii;

const int MOD = 1e9+7;
const int INF = 1e9+7;
const int Maxn = 2e5+7;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

struct Point {
    long double x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point &o) {
        return x == o.x && y == o.y;
    }
    bool operator!=(const Point &o) {
        return !(*this == o);
    }
    Point operator-(const Point &o) {
        return Point(x - o.x, y - o.y);
    }
    long double length() const {
        return sqrt(1LL * x * x + 1LL * y * y);
    }
};

vector<Point>p;
Point a[Maxn],b[Maxn];

long double dot(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y;
}

long double calcAngle(const Point &A, const Point &B) {
    return acos(dot(A, B) / A.length() / B.length());
}

long double cross(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

int ccw(const Point &A, const Point &B, const Point &C) {
    long double S = cross(A, B, C);
    if (S < 0) return -1;
    if (S == 0) return 0;
    return 1;
}

vector<Point> convexHull(vector<Point> p, int n) {
    for (int i = 1; i < n; ++i) {
        if (p[0].y > p[i].y || (p[0].y == p[i].y && p[0].x > p[i].x)) {
            swap(p[0], p[i]);
        }
    }
    sort(p.begin() + 1, p.end(), [&p](const Point &A, const Point &B) {
        int c = ccw(p[0], A, B);
        if (c > 0) return true;
        if (c < 0) return false;
        return A.x < B.x || (A.x == B.x && A.y < B.y);
    });
    vector<Point> hull;
    hull.push_back(p[0]);
    for (int i = 1; i < n; ++i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p[i]) < 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    return hull;
}

bool cmp(Point i,Point j){
    if (i.x==j.x) return i.y<j.y;
    return i.x<j.x;
}

void run_case(){
    int n,m;
    cin>>n;
    p.clear();
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i].x>>b[i].y;
    for(int i=1;i<=n;i++) p.push_back(a[i]);
    for(int i=1;i<=m;i++) p.push_back(b[i]);
    int k=p.size();
    vector<Point>ans=convexHull(p,k);
    sort(ans.begin(),ans.end(),cmp);
    for(int i=1;i<=m;i++){
        int l=0,r=ans.size()-1,pos=-1;
        while(l<=r){
            int g=(l+r)/2;
            if (ans[g].x==b[i].x){
                if (ans[g].y==b[i].y){
                    pos=g;
                    break;
                }
                if (ans[g].y>b[i].y) r=g-1;
                else l=g+1;
            }
            else if (ans[g].x>b[i].x) r=g-1;
            else l=g+1;
        }
        if (pos!=-1){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen(Task ".inp", "r"))
    {
        freopen(Task ".inp", "r", stdin);
        freopen(Task ".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while(t--){
        run_case();
    }
}
