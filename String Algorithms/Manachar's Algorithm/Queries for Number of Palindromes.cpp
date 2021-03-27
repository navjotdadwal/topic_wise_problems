//  https://codeforces.com/problemset/problem/245/H

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

const int N = 1e5 + 5;
vector<int> d1(N),d2(N);
void manacher(string s)
{
  int n=s.length();
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
    }
    d1[i] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
  }
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
    }
    d2[i] = k--;
    if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
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
      string s;
      cin>>s;
      int n=s.length();
      manacher(s);
      vector<vector<int>> pre(n+10,vector<int>(n+10));
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<d1[i];j++)
          pre[i+1-j][i+1+j]++;
        for(int j=1;j<=d2[i];j++)
          pre[i-j+1][i+j]++;
      }
      for(int i=n-1;i>=1;i--)
      {
        for(int j=1;j<=n;j++)
          pre[i][j]+=pre[i+1][j];
      }
      for(int i=2;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
          pre[j][i]+=pre[j][i-1];
      }
      int m;
      cin>>m;
      while(m--)
      {
        int l,r;
        cin>>l>>r;
        cout<<pre[l][r]<<"\n";
      }
    }
    return 0;
}
