//  https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/practice-problems/algorithm/two-papers-ii-02086be4/discussion/too-weak-test-cases-afc7f492/

Biconnected components

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
 
const int N = 300010; 
vector<int> adj[N];
int vis[N];
void dfs(int v)
{
  vis[v]=1;
  for(int to: adj[v])
  {
    if(!vis[to])
      dfs(to);   
  }  
}
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      int n,m;
      cin>>n>>m;
      int ones=0;
      for(int i=0;i<m;i++)
      {
        int a,b,w;
        cin>>a>>b>>w; 
        if(w==0)
          adj[a].pb(b),adj[b].pb(a);
        else 
          ones++;        
      }
      int comp=0;
      for(int i=1;i<=n;i++)
      {
        if(!vis[i])
        {
          dfs(i);
          comp++;
        }
      }
      bool flag=false;
      if(comp%2==0)
        flag=true;
      else 
      {
        if(ones>comp-1)
          flag=true;  
      }
      if(flag)
        cout<<"YES\n";
      else 
        cout<<"NO\n";
    }
    return 0;
}
