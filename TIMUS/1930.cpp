/*
 * Idea : i used dijkstra algorithm to know the minimum distance , 
 * but there were cycles between the nodes
 * so i had to make the distance array on dijkstra 2-d 
 * one refer to the up direction and the other to the down and i minimize on both.
 * 
 */




#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 4, inf = 1e8;
vector<pair<int, int> > adj[N];
int dist[N][3];
set<pair<pair<int, int>, int> > s;
void rep(int j, int node, int cost, int flag) {
	for (int i = 0; i < (int) adj[node].size(); i++) {
		int Cnode = adj[node][i].second;
		int Ccost = adj[node][i].first;
		bool Cflag = 0;
		if (flag != Ccost && flag)
			Cflag = 1;
		if (Cflag + dist[node][j] < dist[Cnode][Ccost]) {
			dist[Cnode][Ccost] = Cflag + dist[node][j];
			s.insert(make_pair(make_pair(dist[Cnode][Ccost], Cnode), Ccost));
		}
	}
}
int dijkstra(int I, int him) {
	for (int i = 1; i < N; i++) {
		dist[i][1] = dist[i][2] = inf;
	}
	dist[I][1] = dist[I][2] = 0;
	s.insert(make_pair(make_pair(0, I), 0));
	while (!s.empty()) {
		int node = s.begin()->first.second;
		int cost = s.begin()->first.first;
		int flag = s.begin()->second;
		s.erase(s.begin());
		if (dist[node][1] == cost) {
			rep(1, node, cost, flag);
		}
		if (dist[node][2] == cost) {
			rep(2, node, cost, flag);
		}
	}
	return min(dist[him][1], dist[him][2]);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(make_pair(1, v));
		adj[v].push_back(make_pair(2, u));
	}
	int I, him;
	cin >> I >> him;
	cout << dijkstra(I, him);
}

