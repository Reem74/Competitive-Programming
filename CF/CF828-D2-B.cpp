#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 2;
string s[N];
int main() {
	int n, m;
	cin >> n >> m;
	int x = N * N, x1 = 0, y = N * N, y1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'B') {
				x = min(i, x), x1 = max(x1, i);
				y = min(j, y), y1 = max(y1, j);
			}
		}
	}
	if (x == N * N && !x1) {
		x = x1 = 0;
		y = y1 = 0;
	}
	int sq = max(x1 - x, y1 - y);
	bool flag = 0;
	if (x1 - x != sq) {
		sq -= (x1 - x);
		if (x > 0) {
			int k = x;
			x = max(0, x - sq);
			sq -= (k - x);
		}
		if (x1 + sq < n && sq) {
			x1 += sq;
			sq = 0;
		}
		if (sq)
			flag = 1;
	} else if (y1 - y != sq) {
		sq -= (y1 - y);
		//cout <<y1 - y<< endl;
		if (y > 0) {
			int k = y;
			y = max(0, y - sq);
			sq -= (k - y);
		}
		if (y1 + sq < m && sq) {
			y1 += sq;
			sq = 0;
		}
		if (sq)
			flag = 1;
	}
	int ans = 0;
	///out << x + 1 << " " << x1 + 1 << ' ' << y + 1 << " " << y1 + 1 << endl;
	for (int i = x; i <= x1; i++) {
		for (int j = y; j <= y1; j++) {
			if (s[i][j] == 'W')
				ans++;
		}
	}
	if (flag)
		ans = -1;
	cout << ans << endl;

}
