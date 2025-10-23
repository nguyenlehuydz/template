#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define Task "test"

typedef pair<int,int>ii;

const int MOD = 1e9+7;
const int INF = 1e9+7;
const int Maxn = 1e5+7;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

struct Point{
    ll x,y;
};

ll cross(Point x,ll a,ll b,ll c){
    return a*x.x+b*x.y+c;
}

void run_case(){
    Point x,y;
    ll a,b,c;
    cin>>x.x>>x.y>>y.x>>y.y>>a>>b>>c;
    ll s1=cross(x,a,b,c);
    ll s2=cross(y,a,b,c);
    if (s1*s2>=0) cout<<"YES";
    else cout<<"NO";
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
