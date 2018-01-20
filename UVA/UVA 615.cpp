/* i start from the root after checking which node is the root
 * by checking which node not any node connected to it ;
 * then from the root i make simple bfs and every time i go to node i mark that node 
 * so if other node reach to marked node this mean that this is not tree 
 * and also last i check that every node in the tree is marked if one is not then this is
 * not a tree too
 * 
 */
#include <bits/stdc++.h>

using namespace std;
map<int, vector<int> > adj;
map<int, int> visit, visitBfs;
bool bfs(int root) {
	bool flag = 0;
	queue<int> q;
	q.push(root);
	visitBfs[root] = 1;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int fr = q.front();
			q.pop();
			for (int i = 0; i < (int) adj[fr].size(); i++) {
				if (!visitBfs[adj[fr][i]] && fr != adj[fr][i]) {
					q.push(adj[fr][i]);
					visitBfs[adj[fr][i]] = fr;
				} else {
					flag = 1;
				}
			}
		}
	}
	return flag;
}
int main() {
	for (int k = 1;; k++) {
		visit.clear();
		adj.clear();
		int n = 0;
		int u, v;
		while (true) {
			scanf("%d%d", &u, &v);
			if ((u == -1 && v == -1) || (u == 0 && v == 0))
				break;
			n = max(n, max(u, v));
			if (!visit[u]) {
				visit[u] = 1;
			}
			if (!visit[v]) {
				visit[v] = 2;
			}
			adj[u].push_back(v);
			visit[u] = max(visit[u], 1);
			visit[v] = max(visit[v], 2);
		}
		if (u == -1 && v == -1)
			break;
		bool flag = 0;
		visitBfs.clear();
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 1) {
				flag = bfs(i);
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!visitBfs[i] && visit[i]) {
				flag = 1;
			}
		}
		printf("Case %d is ", k);
		if (flag) {
			puts("not a tree.");
		} else {
			puts("a tree.");
		}
	}
}

