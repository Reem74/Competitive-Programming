#include <bits/stdc++.h>

using namespace std;
const int N = 4e4 + 5, INF = 1e9;
int a, b, c, memo[N][3];
bool flag1;
int dp(int i, bool flag) {
	if (i > a || i < 0)
		return INF;
	if (i == c) {
		flag1 = 1;
		return 0;
	}
	int &ret = memo[i][flag];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	ret = min(dp(a, flag) + 1, dp(i + b, 0) + (flag ^ 1) + 1);
	ret = min(ret, dp(i - b, 1) + 1 + flag);
	if (i <= b)
		ret = min(ret, dp(a - (b - i), 1) + flag + 3);

	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(memo, -1, sizeof memo);
		flag1 = 0;
		cin >> a >> b >> c;
		if (a < b) {
			swap(a, b);
		}
		if (c == a || c == b) {
			cout << 1;
		} else {
			int ans = dp(0, 0);
			if (!flag1)
				cout << -1;
			else
				cout << ans;
		}
		cout << endl;
	}
}

