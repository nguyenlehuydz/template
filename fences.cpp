#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define Task "fences"

typedef pair<int,int>ii;
typedef pair<ii,int>iii;

const int MOD = 1e9+7;
const int INF = 1e9+7;
const int Maxn = 1e5+7;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

int n,m;

struct Point{
    long double x,y;
};
Point a[Maxn],b[Maxn],c[Maxn];
vector<int>g[Maxn],par[Maxn];
int f[Maxn],sz[Maxn],d=0,child[Maxn];
ii dp[Maxn];

bool check(Point a,Point b,Point c,Point d){
    if (a.x==c.x && a.y==c.y) return true;
    if (a.x==d.x && a.y==d.y) return true;
    if (b.x==c.x && b.y==c.y) return true;
    if (b.x==d.x && b.y==d.y) return true;
    return false;
}

void init(){
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        if (!f[i]){
            g[++d].push_back(i);
            f[i]=d;
        }
        for(int j=i+1;j<=n;j++){
            if (f[j]) continue;
            if (check(a[i],b[i],a[j],b[j])){
                g[f[i]].push_back(j);
                f[j]=f[i];
            }
        }
    }
}

bool inPolygon(Point P,int pos) {
    bool inside = false;
    for(int id:g[pos]){
        Point A=a[id],B=b[id];
        bool intersect=((A.y>P.y)!=(B.y>P.y))&&
                         (P.x<(B.x-A.x)*(P.y-A.y)/(B.y-A.y)+A.x);
        if (intersect) inside=!inside;
    }
    return inside;
}

bool inside(int i,int j){
    for(int id:g[i]){
        Point A=a[id],B=b[id];
        if (!inPolygon(A,j)) return false;
        if (!inPolygon(B,j)) return false;
    }
    return true;
}

bool cmp(ii i,ii j){
    return i.fi>j.fi;
}

void process(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=d;j++){
            if (inPolygon(c[i],j)) sz[j]++;
        }
    }
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            if (i==j) continue;
            // i inside j
            if (inside(i,j)){
                par[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=d;i++) dp[i]={par[i].size(),i};
    sort(dp+1,dp+d+1,cmp);
    int ans=0;
    for(int i=1;i<=d;i++){
        ans=max(ans,sz[dp[i].se]);
        for(int x:par[dp[i].se]) sz[x]-=sz[dp[i].se];
    }
    cout<<ans;
}

void run_case(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
    for(int i=1;i<=m;i++) cin>>c[i].x>>c[i].y;
    init();
    process();
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


