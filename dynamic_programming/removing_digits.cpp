/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 September 2021 01:24:35 AM IST
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

const int INF = 1e9;

int32_t main() {
	int N;
	cin >> N;
	int dp[N + 1]; FOR (i,0,N) dp[i] = INF;
	dp[0] = 0;
	FOR (num,1,N) {
		int u = num;
		while (u > 0) {
			int d = u % 10;
			if (num - d >= 0) 
				cmin(dp[num], 1 + dp[num - d]);
			u /= 10;
		}
	}
	cout << dp[N] << '\n';
}
