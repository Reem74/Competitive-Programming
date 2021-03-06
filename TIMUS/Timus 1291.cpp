
/*
 * Idea :
 * lets first call each wheel-geer : a node ,
 * and the wheel-geer that is connected to the
 *  kinetic-generator : the source.
 *  we have the speed of the source and from this speed we can get 
 *  the speed of the nodes that are connected to the source
 *  and this speed =  speed of the source * (source number of gocks / 
 *   the node am standing on number of gocks )
 *   now we have the speed of all the nodes that are connected to the source
 *   from here i can imagine that each node connected to the source
 *   is a source too and the previous equation applies on 
 *   so i can get the speed of the nodes that are connected to those nodes
 *   and so on 
 *   and to reach to this solution
 
 */ 

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
vector<int> adj[N];
int g[N], visit[N];
pair<int, int> ans[N];
void bfs(int source, int v) {
	queue<int> q;
	q.push(source);
	int level = 0;
	visit[source] = 1;
	int val = g[source] * v;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int fr = q.front(), gd = __gcd(val, g[fr]), num = 0, denum = 1;
			q.pop();
			if (gd) {
				num = val / gd, denum = g[fr] /  gd;
			}
			if (level % 2) {
				num *= -1;
			}
			ans[fr].first = num, ans[fr].second = denum;
			for (int i = 0; i < (int) adj[fr].size(); i++) {
				int ch = adj[fr][i];
				if (!visit[ch]) {
					q.push(ch);
					visit[ch] = 1;
				}
			}
		}
		level++;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> g[i];
		while (true) {
			int v;
			cin >> v;
			if (!v)
				break;
			adj[i].push_back(v);
		}
	}
	int source, v;
	cin >> source >> v;
	bfs(source, v);
	for (int i = 1; i <= n; i++) {
		if(!ans[i].second)
			ans[i].second = 1;
		cout << ans[i].first << '/' << ans[i].second << endl;
	}
}

