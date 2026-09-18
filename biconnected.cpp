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

stack<int>st;
int t;
int num[Maxn],low[Maxn];
vector<int>g[Maxn];
int ans=1;

void dfs(int u,int p=-1){
    st.push(u);
    num[u]=low[u]=++t;
    for(int v:g[u]){
        if (v==p) continue;
        if (num[v]) low[u]=min(low[u],num[v]);
        else{
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>=num[u]){
                int cnt=0;
                while(!st.empty()){
                    cnt++;
                    int u=st.top();
                    st.pop();
                    if (u==v) break;
                }
                ans=max(ans,cnt+1);
            }
        }
    }
}

void run_case(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if (!num[i]) dfs(i,0);
    cout<<ans;
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
