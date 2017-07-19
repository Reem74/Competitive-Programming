
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
map<int, vector<pair<int, int> > > comp, compr;
map<int, int> suml[N], sumr[N];
long long BS(bool flag, int sz, int cost) {
	long long ans = 1e10;
	int st = 0, ed = (int) comp[sz].size() - 1;
	while (st <= ed) {
		int mid = (st + ed) / 2, tmp, c;
		if (flag) {
			tmp = sumr[sz][mid];
			c = compr[sz][mid].first * -1;
		} else {
			tmp = suml[sz][mid];
			c = comp[sz][mid].first;
		}
		if (c > cost) {
			ans = tmp;
			if (!flag)
				ed = mid - 1;
			else
				st = mid + 1;

		} else {
			if (flag)
				ed = mid - 1;
			else
				st = mid + 1;
		}
	}
	return ans;
}
int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		comp[r - l + 1].push_back(make_pair(l, c));
		compr[r - l + 1].push_back(make_pair(r, c));
	}
	for (int i = 1; i < x; i++) {
		sort(comp[i].begin(), comp[i].end()), sort(compr[i].begin(),
				compr[i].end());
		if (compr[i].size())
			sumr[i][0] = compr[i][0].second;
		for (int j = 1; j < (int) comp[i].size(); j++) {
			sumr[i][j] = min(sumr[i][j - 1], compr[i][j].second);
		}
		suml[i][(int) comp[i].size()] = 1e9;
		for (int j = (int) comp[i].size() - 1; j >= 0; j--) {
			suml[i][j] = min(suml[i][j + 1], comp[i][j].second);
		}
	}
	long long c = 1e10;
	for (int i = 1; i < x && x - i >= i; i++) {
		for (int j = 0; j < (int) comp[i].size(); j++) {
			long long cost = BS(0, x - i, compr[i][j].first);
			c = min(c, (long long) compr[i][j].second + cost);
			cost = BS(1, x - i, comp[i][j].first * -1);
			c = min(c, (long long) comp[i][j].second + cost);
		}
	}
	if (c == 1e10)
		c = -1;
	printf("%lld\n", c);
}
