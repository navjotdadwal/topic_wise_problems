//  https://codeforces.com/gym/321411/problem/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#define trace1(x) cerr<<#x<<x<<endl
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
#define all(x) (x).begin(),(x).end()
#define int long long int
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define F first
#define S second
#define inf 1e18
#define vi vector<int>
#define Point complex<int>
#define X real()
#define Y imag()
#define pii pair<int,int>
#define num0Beg(x) __builtin_clz(x) // no. of zero in beginning of bit representation
#define num0end(x) __builtin_ctz(x) // no. of zero in the end
#define numOf1(x) __builtin_popcount(x) // no. of ones in bit rep.
#define parity(x) __builtin_parity(x) // parity of 1
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const int N = 1e5 + 5, K = 505; 
vector<int> adj[N],depth(N);
vector<vector<int>> dp(N,vector<int>(K));
// dp[v][j] -> No. of vertices in subtree of v at a distance of j from v.
// dp[v][0] = 1, dp[v][i]+=dp[to][i-1]
int n,k,ans;
void dfs(int v,int p)
{
  dp[v][0]=1;
  depth[v]=1;
  for(int to: adj[v])
  {
    if(to==p) continue;
    dfs(to,v);
    depth[v]=max(depth[to]+1,depth[v]);
    for(int i=1;i<k;i++)
    {
      if(depth[to]>=i)
        ans+=dp[v][k-i]*dp[to][i-1];   
    }  
    for(int i=1;i<=k;i++)
    {
      dp[v][i]+=dp[to][i-1];   
    }
  }
  ans+=dp[v][k];  
}
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      cin>>n>>k;
      for(int i=1;i<=n-1;i++)
      {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
      }        
      dfs(1,0);
      cout<<ans;
    }
    return 0;
}
