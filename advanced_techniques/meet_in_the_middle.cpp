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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int32_t main() {
	int N, X; cin >> N >> X;
	vector<int> A, B;
	F0R (i,N) {
		int x; cin >> x;
		if (i < N/2) A.push_back(x);
		else B.push_back(x);
	}
	unordered_map<int, int, custom_hash> one;
	F0R (mask,1<<sz(A)) {
		int sum = 0;
		F0R (i,sz(A)) if (mask >> i & 1) sum += A[i];
		one[sum]++;
	}
	int ans = 0;
	F0R (mask,1<<sz(B)) {
		int sum = 0;
		F0R (i,sz(B)) if (mask >> i & 1) sum += B[i];
		if (X - sum >= 0 && one.count(X - sum))
			ans += one[X - sum];
	}
	cout << ans << '\n';
}
