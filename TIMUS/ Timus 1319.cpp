#include <bits/stdc++.h>

using namespace std;
int a[105][105];
int main() {
	int n;
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			for (int k = j, y = 0; k < n && i + y < n;k++, y++) {
				if(a[i + y][k])
					break;
				a[i + y][k] = ++x;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
			if (j + 1 < n)
				cout << " ";
		}
		cout << endl;
	}
}
