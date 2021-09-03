/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 September 2021 03:03:40 PM IST
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

int32_t main() {
	int N, ans = 1e18;
	cin >> N;
	vector<int> A(N);
	F0R (i,N) cin >> A[i];
	F0R (mask,1<<N) {
		int one = 0, two = 0;
		F0R (j,N) {
			if (mask >> j & 1) one += A[j];
			else two += A[j];
		}
		cmin(ans, abs(one - two));
	}
	cout << ans << '\n';
}
