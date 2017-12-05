#include <bits/stdc++.h>

using namespace std;
const int N = 4e4 + 5, INF = 1e9;
int a, b, c, memo[N][3];
int dp(int i, bool flag) {
	if (i > a || i < 0)
		return INF;
	if (i == c) {
		return 0;
	}
	int &ret = memo[i][flag];
	if (ret != -1) {
		return ret;
	}
	ret = min(dp(i + a, flag) + 1, dp(i + b, 0) + 1 + !flag);
	ret = min(ret, dp(i - b, 1) + 1 + flag);
	ret = min(ret, dp(a - (b - i), 1) + flag + 3);
	ret = min(ret, dp(b - (a - i), 0) + 3 + !flag);
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(memo, -1, sizeof memo);
		cin >> a >> b >> c;
		int ans = dp(0, 0);
		swap(a, b);
		ans = min(ans, dp(0, 0));
		if (ans >= INF)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
}


