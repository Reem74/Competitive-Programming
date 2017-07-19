#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int prime[N], beg = 0;
int primes[N];
void sieve() {
	for (int i = 2; i < N; i++) {
		if (!prime[i]) {
			primes[beg++] = i;
			for (int j = 2 * i; j < N; j += i) {
				prime[j] = 1;
			}
		}
	}
}
int main() {
	sieve();
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	while (true) {
		int n, a, b;
		cin >> n >> a >> b;
		if (!n && !a && !b)
			break;
		//cout << n << endl;
		int  ans1 = 0, ans2 = 0;
		for (int i = 0; i < beg; i++) {
			for (int j = 0; j <= i ; j++) {
				if ((primes[i] * primes[j]) > n)
					break;
				if ((primes[i] * a ) <= (primes[j] * b)) {
					if ((primes[i] * primes[j]) >= (ans1 * ans2)) {
						ans1 = primes[i], ans2 = primes[j];
					}
				}
			}
		}
		if(ans2 < ans1)
			swap(ans2, ans1);
		///cout << ans1 * ans2 << endl;
		cout << ans1 << " " << ans2 << endl;

	}
}

