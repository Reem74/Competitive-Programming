#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
long long f[N];
int main() {
	int t;
	cin >> t;
	for (int i = 1; i < N; i++) {
		f[i] = f[i - 1] + i;
	}
	while (t--) {
		int n = 1e6;
		cin >> n;
		long long ans = 0;
		for (int i = 2; i + 1 < n; i++) {
			long long  w = max(0, (n - i + 1 - i));
			ans += w * (i - 1) + f[n - (w + i + 1)];
		}
		cout << ans << endl;
	}
}

