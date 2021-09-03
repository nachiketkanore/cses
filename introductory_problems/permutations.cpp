/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 September 2021 01:50:53 PM IST
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

void brute(int N) {
	vector<int> A(N);
	F0R (i,N) A[i] = i + 1;
	do {
		bool ok = true;
		F0R (i,N-1) ok &= abs(A[i] - A[i + 1]) != 1;
		if (ok) {
			for (int x: A) cout << x << ' ';
			exit(0);
		}
	} while (next_permutation(ALL(A)));
	cout << "NO SOLUTION\n";
	exit(0);
}

bool check(const vector<int>& A) {
	const int N = A.size();
	bool ok = true;
	for (int i = 1; i < N; i++) 
		ok &= abs(A[i] - A[i-1]) != 1;
	return ok;
}

int32_t main() {
	int N;
	cin >> N;
	if (N <= 10) brute(N);
	vector<int> even, odd;
	FOR (i,1,N) if (i & 1) odd.push_back(i); else even.push_back(i);
	vector<int> ans;
	for (int x: even) ans.push_back(x);
	for (int x: odd) ans.push_back(x);
	assert(check(ans));
	for (int x: ans) cout << x << ' ';
	cout << '\n';
}
