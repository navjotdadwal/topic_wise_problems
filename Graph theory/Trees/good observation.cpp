// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/f-corona-free-cities/description/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(p,n) for(int i=p;i<n;i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define mp make_pair
#define pb push_back
vector<ll> child(200009);
vector<vector<ll>> v(200009);
vector<ll> depth(200009);
void dfs(ll n,ll parent)
{
child[n]=0;
depth[n]=depth[parent]+1;
for(ll i=0;i<v[n].size();i++)
{
if(v[n][i]!=parent)
{child[n]++;
dfs(v[n][i],n);
child[n]+=child[v[n][i]];
}
}
}
int main()
{
FIO
ll n,k;
cin>>n>>k;
fo(0,n-1)
{
ll u,ve;
cin>>u>>ve;
v[u].pb(ve);
v[ve].pb(u);
}
depth[1]=-1;
dfs(1,1);
priority_queue<ll> pq;
fo(1,n+1)
{
pq.push(depth[i]-child[i]);
}
ll sum=0;
while(k--)
{
sum+=pq.top();
pq.pop();
}
cout<<sum<<endl;
}
