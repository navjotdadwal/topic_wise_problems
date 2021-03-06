//  https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/palindrome-change-3e337ebf/description/

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
 
const int M = 27;
int cost[M][M];
int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      string s;
      cin>>s;
      int m,n=s.length();
      cin>>m;
      for(int i=0;i<26;i++)
      {
        for(int j=0;j<26;j++)
        {
          if(i==j)
            cost[i][j]=0;
          else 
            cost[i][j]=inf;  
        }  
      }
      for(int i=0;i<m;i++){
        char a,b;
        int x;
        cin>>a>>b>>x;
        cost[a-'a'][b-'a']=min(cost[a-'a'][b-'a'],x);
        cost[b-'a'][a-'a']=min(cost[b-'a'][a-'a'],x);          
      }
      for(int k=0;k<26;k++)
      {
        for(int i=0;i<26;i++)
        {
          for(int j=0;j<26;j++)
            cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);  
        }  
      }
      int ans=0;
      for(int i=0;i<=(n-1)/2;i++)
      {
        if(n%2!=0 && i==(n-1)/2);
        else
        {
          int res=inf;
          int f=s[i]-'a',r=s[n-i-1]-'a';
          for(int i=0;i<26;i++)
            res=min(res,cost[f][i]+cost[r][i]);
          ans+=res;
        }         
      }
      cout<<ans;
    }
    return 0;
}
