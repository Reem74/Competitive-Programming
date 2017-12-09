/*
 * i try to get from the begging to the destination by trying every possible
 * road and reaching he destination by the shortest road by making bfs its order is 
 * o(number of nodes + number of edges) = o(2 *(n * m)) 
 * given n <= 100 and m <= 100,000
 * 
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
int dirX[] = { 0, 0, 1, -1 };
int dirY[] = { -1, 1, 0, 0 };
int s1, s2, d1, d2;
int visit[101][N];
int bfs() {
	queue<pair<int, int> > q;
	q.push(make_pair(s1, s2));
	visit[s1][s2] = 1;
	int level = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			pair<int, int> fr = q.front();
			q.pop();
			if (fr.first == d1 && fr.second == d2)
				return level;
			for (int i = 0; i < 4; i++) {
				int newX = fr.first + dirX[i];
				int newY = min(fr.second + dirY[i], a[newX]);
				if (newX < n && newX >= 0 && newY >= 0 && !visit[newX][newY]) {
					q.push(make_pair(newX, newY));
					visit[newX][newY] = 1;
				}
			}
		}
		level++;
	}
	return -1;
}
int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d%d%d%d", &s1, &s2, &d1, &d2);
	s1--, s2--, d1--, d2--;
	printf("%d", bfs());
}

