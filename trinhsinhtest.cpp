#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define NAME "template"
#define rand rd
#define el inp<<'\n'

typedef pair<ll,int>ii;
typedef pair<int,ii>iii;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int Maxn = 2e5 + 7;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};
const int NTEST = 100;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l,ll r){
    return l + rd() * 1LL* rd() % (r-l+1);
}
void maketest(){
    ofstream inp(NAME".inp");
}
int main(){
    srand(time(0));
    for(int i=1;i<=NTEST;i++){
        maketest();
        system(NAME"_trau.exe");
        system(NAME".exe");
        if (system("fc "NAME".out "NAME".ans") !=0){
            cout << "Test " << i << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << i << ": CORRECT!\n";
    }
}