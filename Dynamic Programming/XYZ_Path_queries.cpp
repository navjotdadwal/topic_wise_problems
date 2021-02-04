//  https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/path-queries-ba308c8e/submissions/

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define ll int
#define bits_count __builtin_popcountll
#define endl '\n'
#define double long double
#define ld double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
#define pr pair<int,int>

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const int LOG_A = 31;
const int LEV = 19;

vector<int> graph[MAXN];
int a[MAXN][LOG_A];
int dp[MAXN][LOG_A];
int parent[MAXN][LEV];
int level[MAXN];
int fact[MAXN],invfact[MAXN];

void dfs(int u,int p){
    level[u] = level[p] + 1;
    parent[u][0] = p;

    // FOR DP (SET BITS SUMMATION FROM ROOT TO THAT NODE)
    FOR(i,0,LOG_A-1) dp[u][i] += dp[p][i];
    FOR(i,0,LOG_A-1) dp[u][i] += a[u][i];

    // FOR LCA CALCULATIOn
    FOR(lev,1,LEV-1){
        parent[u][lev] = parent[parent[u][lev-1]][lev-1];
    }

    for(int v:graph[u]){
        if(v == p) continue;
        dfs(v,u);
    }
}

// STANDARD LCA CALCULATION
int lca_(int a,int b){
    if(level[a] < level[b]) swap(a,b);
    
    int diff = level[a] - level[b];

    FOR(i,0,LEV-1) if(diff&(1<<i)) a = parent[a][i];

    if(a == b) return a;

    RFOR(i,0,LEV-1){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

// POWER MODULO
int power(int x,int y){
    int res = 1;
    while(y){
        if(y&1) res = (res*x)%MOD;
        x = (x*x)%MOD;
        y >>= 1;
    }
    return res;
}

// nCr
int nCr(int n,int r){
    if(r > n) return 0;
    int ret = (fact[n]*invfact[r])%MOD;
    return (ret*invfact[n-r])%MOD;
}

// FORMULA CALCULATION FOR EACH QUERY
int return_statement(int type,int n,int m){
    if(type == 1) {
        int ret = nCr(n,1);
        return ret;
    }else if(type == 2){
        int ret = (nCr(n,2) + (nCr(n,1)*nCr(m,1)))%MOD;
        return ret;
    }else if(type == 3){
        int ret1 = (nCr(n,3) + (nCr(n,2)*nCr(m,1)))%MOD;
        int ret2 = (nCr(n,1)*nCr(m,2))%MOD;
        return (ret1+ret2)%MOD;
    }else {
        int ret1 = (nCr(n,4) + (nCr(n,3)*nCr(m,1)))%MOD;
        int ret2 = ((nCr(n,2)*nCr(m,2)) + (nCr(n,1)*nCr(m,3)))%MOD;
        return (ret1+ret2)%MOD;
    }
}

void solve(){

    fact[0] = 1;
    FOR(i,1,MAXN-1) fact[i] = (fact[i-1]*i)%MOD;
    FOR(i,0,MAXN-1) invfact[i] = power(fact[i],MOD-2);

    int n,q; cin>>n;

    FOR(i,1,n){
        int x; cin>>x;

        FOR(bit,0,LOG_A-1){
            if(x&(1LL<<bit)) a[i][bit] = 1;
            else a[i][bit] = 0;
        }
    }

    FOR(i,1,n-1){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,0);

    cin>>q;
    
    while(q--){
        int type,x,y; cin>>type>>x>>y;

        int lca = lca_(x,y);

        int ans = 0;
        
        // GOING BITWISE FOR CALCULATION OF ANSWER
        FOR(bit,0,LOG_A-1){
            int val = (1LL<<bit);
            int no_of_ones = (dp[y][bit] - dp[lca][bit]) + (dp[x][bit] - dp[lca][bit]) + a[lca][bit];
            int no_of_zeros = level[x] + level[y] - 2*level[lca] + 1 - no_of_ones;
            ans = (ans + (val * return_statement(type,no_of_ones,no_of_zeros))%MOD)%MOD;
        }
        
        cout<<ans<<endl;
    }
}   
    
signed main(){
    
    FastRead;     
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int t = 1;
    FOR(i,1,t){
        solve();
    }
}