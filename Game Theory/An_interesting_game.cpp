// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/interesting-game-3-4d4095c9/submissions/
// Game theory

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;
const int N = 200000;
ll dp[101][N];
void solve()
{
    int n;
    cin>>n;
    assert(1 <= n && n <= 100000);
    int freq[101] = {0};
    for(int i = 1 ; i <= n ; i++)
    {
        int val;
        cin>>val;
        assert(1 <= val && val <= 100);
        freq[val]++;
    }
    vector<int>num;
    num.push_back(0);
    for(int i = 1 ; i <= 100 ; i++)
    {
        if(freq[i] > 0) num.push_back(freq[i]);
    }
    int sz = num.size();
    dp[0][0] = 1;
    for(int i = 1 ; i < sz ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i-1][j^num[i]];
            dp[i][j] %= MOD;
        }
    }
    cout<<(dp[sz - 1][0])<<endl;
}
int main(){
    solve();
}