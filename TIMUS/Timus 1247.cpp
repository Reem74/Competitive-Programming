/*
 * IDEA:
 * keep adding the value of x until finding a subsegment sum 
 *   equals a negative value so i start the addition after
 *    this subsegment
 *
 */
#include <bits/stdc++.h>

using namespace std;
int main() {
	int s, n;
	cin >> s >> n;
	int sum = 0, mn = 0;
	bool flag = 0;
	for (int i = 1; i <= s; i++) {
		int x;
		cin >> x;
		sum += x;
		if (sum - i > n)
			flag = 1;
		if (sum - i < mn) {
			mn = sum - i;
			sum -= mn;
		}
	}
	cout << (flag ? "NO" : "YES");
}

