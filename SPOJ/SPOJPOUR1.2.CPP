#include <bits/stdc++.h>
using namespace std;

int pour(int a, int b, int c, int x, int y) {
	int cnt = 0;
	while (a != c && b != c) {
		if (!a) {
			a = x;
		} else if (b == y) {
			b = 0;
		} else {
			b += a;
			a = 0;
			if (b > y) {
				a = b - y;
				b = y;
			}
		}
		cnt++;
	}
	return cnt;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int gcd = __gcd(a, b);
		if ((c % gcd) || (c > a && c > b)) {
			cout << -1 << endl;
		} else {
			int ans = min(pour(0, 0, c, a, b), pour(0, 0, c, b, a));
			cout << ans << endl;
		}
	}
}

