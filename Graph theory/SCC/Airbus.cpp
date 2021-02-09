//  https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/components-of-graph-2b95e067/description/

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
 
const int N = 1e5+5;
vector<int> adj[N],radj[N];
vector<int> val(N),vis(N),order;
int n,m,k;
void dfs(int v,int& comp,int x)
{
  comp++;
  vis[v]=1;
  for(int to: radj[v])
  {
    if(!vis[to] && val[to]>=x)
      dfs(to,comp,x);
  }
}
void dfs1(int v)
{
  vis[v]=1;
  for(int to: adj[v])
  {
    if(!vis[to])
    {
      dfs1(to);
    }
  } 
  order.pb(v);
}
bool check(int x)
{
  for(int i=1;i<=n;i++)
    vis[i]=0;
  for(int i: order)
  {
    if(!vis[i] && val[i]>=x)
    {
      int comp=0;
      dfs(i,comp,x);
      if(comp>=k)
        return true;
    }  
  }
  return false;  
}
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      cin>>n>>m>>k;
      for(int i=1;i<=n;i++)
        cin>>val[i];
      for(int i=0;i<m;i++)
      {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        radj[v].pb(u);
      }       
      for(int i=1;i<=n;i++)
      {
        if(!vis[i])
          dfs1(i);
      }
      reverse(order.begin(),order.end());
      int lo=1,hi=1e9,ans=0;
      while(lo<=hi)
      {
        int mid=(lo+hi)/2;
        if(check(mid)) 
           ans=max(ans,mid),lo=mid+1;
        else
           hi=mid-1;
      }
      cout<<ans;
    }
    return 0;
}
