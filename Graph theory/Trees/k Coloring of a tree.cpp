// https://www.hackerearth.com/problem/algorithm/sddsfs-2/submissions/


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
 
const int N = 3e5 + 5;
const int MOD = 1e9+7;
vector<int> adj[N];
int fact[N], invfact[N];
int pow(int a, int b, int m)
{
   int ans=1;
   while(b)
   {
     if(b&1)
      ans=(ans*a)%m;
      b/=2;
      a=(a*a)%m;
   }
   return ans;
}
int modinv(int k)
{
   return pow(k, MOD-2, MOD);
}
void precompute()
{
   fact[0]=fact[1]=1;
   for(int i=2;i<N;i++)
   {
     fact[i]=fact[i-1]*i;
     fact[i]%=MOD;
   }
   invfact[N-1]=modinv(fact[N-1]);
   for(int i=N-2;i>=0;i--)
   {
      invfact[i]=invfact[i+1]*(i+1);
      invfact[i]%=MOD;
   }
}
int nCr(int x, int y)
{
   if(y>x)
     return 0;
   int num=fact[x];
   num*=invfact[y];
   num%=MOD;
   num*=invfact[x-y];
   num%=MOD;
   return num;
}
int n,k;
int dfs(int v,int p,int l)
{
  int child=adj[v].size(),q=l;
  if(l>=2) q=2;
  int ans=nCr(k-q,child)*fact[child];
  ans%=MOD;
  for(int to: adj[v])
  {
    if(to==p)
      continue;
    ans*=dfs(to,v,l+1);
    ans%=MOD;
  }
  return ans;
}
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      cin>>n>>k;
      precompute();
      for(int i=0;i<n-1;i++)
      {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
      }
      int ans=(dfs(1,0,1)*k)%MOD;
      cout<<ans;
    }
    return 0;
}
