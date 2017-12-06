#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1000000007;
int cost[N], inStack[N], dfn[N], lowest_link[N];
stack<int> stk;
vector<int> adj[N];
int id;
vector<vector<int> > comps;
void tarjan(int source) {
	inStack[source] = 1;
	dfn[source] = lowest_link[source] = id++;
	stk.push(source);
	for (int i = 0; i < (int) adj[source].size(); i++) {
		int ch = adj[source][i];
		if (inStack[adj[source][i]] == 1) {
			lowest_link[source] = min(lowest_link[source], lowest_link[ch]);
		} else if (!inStack[adj[source][i]]) {
			tarjan(adj[source][i]);
			lowest_link[source] = min(lowest_link[source], lowest_link[ch]);

		}
	}
	if (dfn[source] == lowest_link[source]) {
		comps.push_back(vector<int>());
		int x = -1;
		while (x != source) {
			x = stk.top();
			stk.pop();
			comps.back().push_back(cost[x]);
			inStack[x] = 2;
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		if (!inStack[i])
			tarjan(i);
	}
	long long ans = 1;
	long long mn = 0;
	for (int i = 0; i < (int) comps.size(); i++) {
		sort(comps[i].begin(), comps[i].end());
		int cnt = 0;
		mn += comps[i][0];
		for (int j = 0; j < (int) comps[i].size(); j++) {
			if (comps[i][j] == comps[i][0])
				cnt++;
		}
		ans = ans * cnt;
		ans %= MOD;
	}
	cout << mn << " " << ans << endl;
}

