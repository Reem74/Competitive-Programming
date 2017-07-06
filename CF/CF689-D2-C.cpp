#include<bits/stdc++.h>

using namespace std;
const long long N = 1e6 + 6;
long long valid(long long mid) {
	long long ans = 0;
	for (int i = 2; i < N; i++) {
		ans += floor(mid / (i * 1ll * i * i));
	}
	return ans;
}
int main() {
	long long m;
	scanf("%lld", &m);
	long long start = 0, ed = 1e18, ans = -1;
	while (start <= ed) {
		long long mid = (start + ed) / 2;
		if (valid(mid) == m) {
			ans = mid;
		}
		if (valid(mid) >= m) {
			ed = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	printf("%lld\n", ans);
}
