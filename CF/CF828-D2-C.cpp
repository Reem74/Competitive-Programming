#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
string s[N];
vector<int> v[N];
int main() {
	int n;
	cin >> n;
	string ans;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> s[i] >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			v[x].push_back(i);
		}
	}
	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < N; i++) {
		while ((int) v[i].size() && (int) ans.size() + 1 < i) {
			ans += 'a';
		}
		for (int j = 0; j < (int) v[i].size(); j++) {
			int beg = ((int) ans.size() - i + 1);
			for (int k = beg; k < (int) s[v[i][j]].size(); k++) {
				ans += s[v[i][j]][k];
			}
		}
	}
	cout << ans << endl;

}
