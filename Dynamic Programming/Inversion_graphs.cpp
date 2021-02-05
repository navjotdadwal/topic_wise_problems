//  https://www.hackerearth.com/problem/algorithm/inversion-graph-4670b723/description/?source=list_view
// LIS in nlogn
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
    //cin >> tt;
    while(tt--)
    {         
      int n;
      cin>>n;
      vector<int> a(n);
      for(int i=0;i<n;i++)
        cin>>a[i];
      reverse(a.begin(),a.end());
      set<int> s;
      for(int i=0;i<n;i++)
      {
        auto it=lower_bound(s.begin(),s.end(),a[i]);
        if(it!=s.end())
          s.erase(it);
        s.insert(a[i]);
      }
      cout<<s.size();
    }
    return 0;
}