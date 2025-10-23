#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define Task "bill"

typedef pair<int,int>ii;
typedef pair<ii,int>iii;

const int MOD = 1e9+7;
const ll INF = 1e17+7;
const int Maxn = 1e5+7;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

struct Point{
    long double x,y;
};

Point a[1507];

long double sqr(long double x){
    return x*x;
}

long double hs(Point a,Point b){
    return 1.0*(a.x*b.x+a.y*b.y)/(sqr(b.x)+sqr(b.y));
}

long double dist(Point a,Point b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

long double height(Point u,long double a,long double b,long double c){
    return 1.0*abs(a*u.x+b*u.y+c)/sqrt(sqr(a)+sqr(b));
}

long double dist(Point a,Point b,Point c){
    Point BA={a.x-b.x,a.y-b.y},BC={c.x-b.x,c.y-b.y};
    long double t=hs(BA,BC);
    if (t>=0 && t<=1){
        long double x=b.y-c.y,y=c.x-b.x,z=b.x*c.y-c.x*b.y;
        return height(a,x,y,z);
    }
    else{
        return min(dist(a,b),dist(a,c));
    }
}

void run_case(){
    int n;
    cin>>n;
    Point s;
    cin>>s.x>>s.y;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    a[n+1]=a[1];
    long double ans=INF;
    for(int i=1;i<=n;i++){
        ans=min(ans,dist(s,a[i],a[i+1]));
    }
    cout<<setprecision(4)<<fixed<<ans;
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

