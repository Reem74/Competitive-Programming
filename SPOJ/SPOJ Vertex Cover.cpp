#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
int visit[N], visit1[N], v;
int dfs(int parent, int child) {
	if (visit[child])
		return v;
	visit[child] = 1;
	for (int i = 0; i < (int) adj[child].size(); i++) {
		dfs(child, adj[child][i]);
	}
	if (!visit1[child] && !visit1[parent]) {
		visit1[parent] = 1;
		v++;
	}
	return v;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	visit1[0] = 1;
	cout << dfs(0, 1);
}

