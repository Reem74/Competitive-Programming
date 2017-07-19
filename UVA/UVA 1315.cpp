#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool flag = 0;
		if(n % 2 && n != 1)
			flag = 1;
		n -= 2;
		long long  w = n / 2, ans = 0;
		for (int i = 1; i <= w; i++) {
			ans += (2 * i);
		}
		if (flag)
			ans += w + 1;
		cout << ans  << endl;
	}
}

