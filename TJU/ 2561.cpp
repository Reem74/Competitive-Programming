
/*
 * Idea :
 * i use dfs algorithm from each node 
 * , if i meet the conditions he mentioned from one or more then this is a caterpillar,
 * and on the dfs  if i reached to a node 
 * that is already visited and this node is'nt my parent then there
 * exist a cycle and the against the conditions.
 * 
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 4;
vector<int> adj[N];
int visit[N];
bool flag1 = 0;
int dfs(int source, int cnt, int before) {
	int ret = 0;
	for (int i = 0; i < (int) adj[source].size(); i++) {
		if (!visit[adj[source][i]]) {
			visit[adj[source][i]]++;
			ret = max(
					dfs(adj[source][i], cnt, source) - 1
							+ (int) adj[source].size(), ret);
		} else {
			if (before != adj[source][i] && visit[adj[source][i]] % 2)
				flag1 = 1;
		}
	}
	visit[source]++;
	return ret;
}
int main() {
	int n, cnt = 0;
	while (true) {
		cnt++;
		scanf("%d", &n);
		if (!n)
			break;
		int m;
		scanf("%d", &m);
		memset(adj, 0, sizeof adj);
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			memset(visit, 0, sizeof visit);
			flag1 = 0;
			visit[i] = 1;
			int k = dfs(i, i, 0) + 1;
			if (flag1)
				k = 0;
			if (n == 1 || !adj[i].size()) {
				if (k == n) {
					flag = 0;
					break;
				}
			} else {
				if (k + 1 == n) {
					flag = 0;
					break;
				}
			}
		}
		printf("Graph %d is ", cnt);
		if (flag)
			printf("not ");
		puts("a caterpillar.");
	}
}
