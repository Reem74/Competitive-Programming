/* i try every possible path to take so i made a dp that its state is the index and 
 * flag till me the previous string i took was reversed or not 
 * so 0 means not and 1 means that the previous string was reversed
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e15;
int cost[N];
long long memo[N][3], n;
string strings[2][N];
long long dp(int ind, int prev) {
	if (ind == n + 1)
		return 0;
	long long &ret = memo[ind][prev];
	if (ret != -1)
		return ret;
	if (strings[0][ind] >= strings[prev][ind - 1]) {
		ret = dp(ind + 1, 0);
	} else {
		ret = INF;
	}
	if (strings[1][ind] >= strings[prev][ind - 1]) {
		ret = min(ret, dp(ind + 1, 1) + cost[ind]);
	} else {
		ret = min(ret, INF);
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> strings[0][i];
		strings[1][i] = strings[0][i];
		reverse(strings[1][i].begin(), strings[1][i].end());
	}
	strings[0][0] = strings[0][1];
	strings[1][0] = strings[1][1];
	memset(memo, -1, sizeof memo);
	long long ans = min(dp(1, 0), dp(1, 1));
	if (ans >= INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
}

