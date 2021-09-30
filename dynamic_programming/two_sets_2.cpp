/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 30 September 2021 02:50:46 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 2e5 + 2, inf = 1e18;
const int mod = 1e9 + 7;
 
int n, tot;
vector<vector<int>> dp;
 
int power(int a, int b, int p = mod){
    int ret = 1;
    a %= p;
    while(b > 0){
        if(b % 2 == 1)
            ret = ret * a % p;
        b /= 2;
        a = a * a % p;
    }
    return ret;
}
 
int go(int id, int curr_sum) {
    int other_sum = tot - curr_sum;
    if(other_sum == curr_sum)
        return 1;
    if(id > n)
        return 0;
    int &ans = dp[id][curr_sum];
    if(~ans)
        return ans;
 
    int c1 = go(id + 1, curr_sum + id);
    int c2 = go(id + 1, curr_sum);
 
    return ans = (c1 + c2) % mod;
}
 
int32_t main(){
    cin >> n;
    tot = n * (n + 1) / 2;
    dp = vector<vector<int>> (n + 1, vector<int>(tot + 1, -1));
 
    int ans = go(1, 0);
    ans = ans * power(2, mod - 2, mod) % mod;
    cout << ans;
}
