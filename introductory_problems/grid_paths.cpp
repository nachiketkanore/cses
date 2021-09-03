/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 September 2021 02:51:07 PM IST
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

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
string S;
int N;
bool vis[10][10];

pair<int,int> next_position(int cx, int cy, char dir) {
	if (dir == 'L') return {cx, cy - 1};
	else if (dir == 'R') return {cx, cy + 1};
	else if (dir == 'U') return {cx - 1, cy};
	else if (dir == 'D') return {cx + 1, cy};
	assert(false);
	return {-1, -1};
}

int go(int cx, int cy, int id) {
	if (cx < 0 || cx > 7 || cy < 0 || cy > 7) return 0;
	if (vis[cx][cy]) return 0;
	if (id == N) return cx == 7 && cy == 7;
	int ans = 0;
	if (S[id] == '?') { 
		F0R (j,4) {
			vis[cx][cy] = true;
			ans += go(cx + dx[j], cy + dy[j], id + 1);
			vis[cx][cy] = false;
		}
	} else {
		auto [nx, ny] = next_position(cx, cy, S[id]);
		vis[cx][cy] = true;
		ans += go(nx, ny, id + 1);
		vis[cx][cy] = false;
	}
	return ans;
}

int32_t main() {
	cin >> S;
	N = S.size();
	cout << go(1, 1, 0);
}
