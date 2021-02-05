//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/array-and-sums-6e5e7323/submissions/
// basic understanding +  subset sum DP

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
 

int32_t main()
{
    FAST
    int tt=1;
    cin >> tt;
    while(tt--)
    {         
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      vector<pii> v;
      for(int i=0;i<n;i++)
        v.pb({a[i],i});
      sort(v.begin(),v.end());
      vector<int> ans(n+1,0);
      vector<vector<int>> dp(n+1,vector<int>(1001,0));
      map<int,int> freq;
      for(int i=0;i<n;i++)
        freq[a[i]]++;
      dp[0][0]=1;
      for(int i=0;i<v.size();i++)
      {
        if(dp[i][v[i].F] || freq[v[i].F]>1)
          ans[v[i].S]=1;
        for(int j=0;j<=1000;j++)
        {
          if(dp[i][j] && j+v[i].F<=1000)
            dp[i+1][j+v[i].F]=1,dp[i+1][j]=1;
          else if(dp[i][j])
            dp[i+1][j]=1; 
        }
      }
      for(int i=0;i<n;i++) cout<<ans[i]<<" ";
      cout<<"\n";
    }
    return 0;
}