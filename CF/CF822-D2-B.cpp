

/*
 * Idea :
 *   doing a brute force and see the min change between all the substrings of m that is equal to string n with changing some letters on n
 */

#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	string s, sh;
	cin >> s >> sh;
	int mn = 1e9, index = -1;
	for (int i = 0; i + n - 1 < m; i++) {
		int ans = 0, flag = 0;
		//cout << i << endl;
		for (int j = i, beg = 0; j < m; j++, beg++) {
			if (beg >= n) {
				break;
			}
			if (s[beg] != sh[j]) {
				ans++;
			}
		}
		///cout << ans << " " << endl;
		if (ans < mn && !flag) {
			mn = ans, index = i;
		}
	}
	cout << mn << endl;
	for (int i = index, beg = 0; i < m; i++, beg++) {
		if (beg >= n)
			break;
		if (s[beg] != sh[i])
			cout << beg + 1 << ' ';
	}
	cout << endl;

}
