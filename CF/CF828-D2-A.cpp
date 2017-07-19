#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0, flag =0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			if (a)
				a--;
			else if (b) {
				b--;
				flag++;
			}
			else if(flag) {
				flag--;
			}
			else
				ans++;

		} else if (x == 2) {
			if (b)
				b --;
			else
				ans+= 2;
		}

	}
	cout << ans << endl;
}
