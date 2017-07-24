
/*
 IDEA: i used dfs algorithm to know when i reach to a leaf so
 if i reached to a leaf
 i take it's parent because if i took the leaf no other node will have
 a benefit of taking it and i have to take from each pair that
 are connected to each other one of the nodes so i take the parent
 because it may bring a better answer or the exact same answer of taking
 the leaf after that i take all the nodes which have at least one
  child isn't have been taken on the set
 */

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

