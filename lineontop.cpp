#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define Task "lineontop"

typedef pair<int,int>ii;
typedef pair<ii,int>iii;

const int MOD = 1e9+7;
const int INF = 1e9+7;
const int Maxn = 1e5+7;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

struct Point{
    long double x,y;
};

Point a[Maxn],b[Maxn];
bool f[Maxn];

long double area(Point a, Point b, Point c) {
    return 1.0*(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool onSegment(Point a, Point b, Point c) {
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

bool intersect(Point a, Point b, Point c, Point d) {
    long double s1=area(a, b, c);
    long double s2=area(a, b, d);
    long double s3=area(c, d, a);
    long double s4=area(c, d, b);
    if (s1*s2<0 && s3*s4<0) return true;
    if (s1==0 && onSegment(a,b,c)) return true;
    if (s2==0 && onSegment(a,b,d)) return true;
    if (s3==0 && onSegment(c,d,a)) return true;
    if (s4==0 && onSegment(c,d,b)) return true;
    return false;
}

void run_case(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
    memset(f,1,sizeof(f));
    vector<int>ans;
    for(int i=n;i>=1;i--){
        if (f[i]) ans.push_back(i);
        if (ans.size()>=1000) break;
        for(int j=1;j<i;j++){
            if (!f[j]) continue;
            if (intersect(a[j],b[j],a[i],b[i])){
                f[j]=0;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<" ";
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen(Task ".inp", "r"))
    {
        freopen(Task ".inp", "r", stdin);
        freopen(Task ".out", "w", stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--){
        run_case();
    }
}


