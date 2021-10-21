/**
 *    Author: Nachiket Kanore
 *    Created: Monday 04 October 2021 05:11:34 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <unordered_map>
#include <cstring>
#include <chrono>

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
	int N, X; cin >> N >> X;
	vector<int> A, B;
	F0R (i,N) {
		int x; cin >> x;
		if (i < N/2) A.push_back(x);
		else B.push_back(x);
	}
	vector<int> one;
	F0R (mask,1<<sz(A)) {
		int sum = 0;
		F0R (i,sz(A)) if (mask >> i & 1) sum += A[i];
		one.push_back(sum);
	}
	sort(ALL(one));
	int ans = 0;
	F0R (mask,1<<sz(B)) {
		int sum = 0;
		F0R (i,sz(B)) if (mask >> i & 1) sum += B[i];
		int f = X - sum;
		int cnt = upper_bound(ALL(one), f) - lower_bound(ALL(one), f);
		ans += cnt;
	}
	cout << ans << '\n';
}
