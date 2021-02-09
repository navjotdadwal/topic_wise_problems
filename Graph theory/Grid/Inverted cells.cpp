// https://www.hackerearth.com/problem/algorithm/inverted-cells-83eae42d/submissions/?source=list_view

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
 
const int N = 1010;
char M[N][N];
int ways[N][N],rways[N][N],good[N][N],cnt[N];

int32_t main()
{
    FAST
    int tt=1;
    //cin >> tt;
    while(tt--)
    {         
      int n,m;
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
          cin>>M[i][j];
      }
      ways[1][1]=1;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          if(M[i][j]=='.')
            ways[i][j]=ways[i-1][j] | ways[i][j-1];  
        } 
      }
      rways[n][m]=1;
      for(int i=n;i>=1;i--)
      {
        for(int j=m;j>=1;j--)
        {
          if(M[i][j]=='.')
            rways[i][j]=rways[i+1][j] | rways[i][j+1];
        }  
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          good[i][j]=(ways[i][j] & rways[i][j]) , cnt[i+j]+=good[i][j];
        }
      } 
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          if(M[i][j]=='#')
          {
            if(ways[n][m])
              cout<<"1 ";
            else { 
              if((rways[i+1][j] | rways[i][j+1]) & (ways[i-1][j] | ways[i][j-1]))
                cout<<"1 ";
              else 
                cout<<"0 ";
            }
          }
          else 
          {
            if(!ways[n][m])
              cout<<"0 ";
            else 
            {
              if(good[i][j] && cnt[i+j]==1)
                cout<<"0 ";
              else 
                cout<<"1 ";
            }
          }            
        }
        cout<<"\n";
      }         
    }
    return 0;
}
