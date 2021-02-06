https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/cheapest-way/submissions/

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
 
const int N = 100011; 
void dijkstra(vector<int>& dist,int src,vector<pii> adj[])
{
  set<pii> s;
  dist[src]=0;
  s.insert({0,src});
  while(!s.empty()) {
      int v=(*s.begin()).S,d=(*s.begin()).F;
      s.erase(s.begin());
      for(auto it: adj[v])
      {
        int to=it.F,curd=it.S;
        if(dist[to]>dist[v]+curd)
        {
          if(s.find({dist[to],to})!=s.end())
            s.erase(s.find({dist[to],to}));  
          dist[to]=dist[v]+curd;
          s.insert({dist[to],to});
        }
      }
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
      vector<pii> g[n+1],rg[n+1];
      for(int i=0;i<m;i++)
      {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
        rg[b].pb({a,c});  
      }        
      vector<int> dist1tox(N,inf),distntoy(N,inf);    
      dijkstra(dist1tox,1,g);
      dijkstra(distntoy,n,rg);
      int ans=inf;
      for(int i=1;i<=n;i++)
      {
        for(auto it: g[i])
          ans=min(ans,dist1tox[i]+distntoy[it.F]);           
      }
      cout<<ans;
    }
    return 0;
}
