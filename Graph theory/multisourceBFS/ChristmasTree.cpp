// https://codeforces.com/problemset/problem/1283/D
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
 
const int N = 1e5 + 5;
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      int n,m;
      cin>>n>>m;
      int x[n];
      for(int i=0;i<n;i++)
         cin>>x[i];
      vector<int> dist[N];
      map<int,int> vis,dis;
      queue<int> q;
      for(int i=0;i<n;i++)
      {
        vis[x[i]]=1; 
        q.push(x[i]); 
      }       
      int y=0;
      while(!q.empty())
      {
        int curr=q.front();
        dist[dis[curr]].pb(curr);
        if(dis[curr]>0)
        y++;
        if(y>=m)
          break;
        q.pop();
        if(!vis[curr-1])
        {
          vis[curr-1]=1;
          dis[curr-1]=dis[curr]+1;
          q.push(curr-1);
        }       
        if(!vis[curr+1])
        {
          vis[curr+1]=1;
          dis[curr+1]=dis[curr]+1;
          q.push(curr+1);  
        }      
      }
      int ans=0;
      vector<int> res;
      int i=0,j=1;
      while(j<N-1)
      {
        for(int el: dist[j])
          res.pb(el);
        j++;
      }     
      for(int i=0;i<m;i++)
        ans+=dis[res[i]];
      cout<<ans<<"\n";
      for(int i=0;i<m;i++)
        cout<<res[i]<<" ";
    }
    return 0;
}
