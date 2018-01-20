/* 
 * by try every possible way to reach to the target node with checking that am following the
 * given string too with simple bfs and then printing the path
 * 
 */
#include <bits/stdc++.h>

using namespace std;
const int N = 10 + 2;
string s[N];
map<pair<int, int>, pair<int, int> > visit;
string intial = "IEHOVA#";
int n, m;
pair<int, int> bfs(int i, int j) {
	visit.clear();
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	visit[make_pair(i, j)] = make_pair(-1, -1);
	int level = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			pair<int, int> fr = q.front();
			q.pop();
			i = fr.first, j = fr.second;
			if (s[i][j] == '#') {
				return make_pair(i, j);
			}
			if (i && intial[level] == s[i - 1][j]
					&& visit.find(make_pair(i - 1, j)) == visit.end()) {
				//forth
				visit[make_pair(i - 1, j)] = make_pair(i, j);
				q.push(make_pair(i - 1, j));
			}
			if (j && intial[level] == s[i][j - 1]
					&& visit.find(make_pair(i, j - 1)) == visit.end()) {
				//left
				visit[make_pair(i, j - 1)] = make_pair(i, j);
				q.push(make_pair(i, j - 1));
			}
			if (j < m && intial[level] == s[i][j + 1]
					&& visit.find(make_pair(i, j + 1)) == visit.end()) {
				//right
				visit[make_pair(i, j + 1)] = make_pair(i, j);
				q.push(make_pair(i, j + 1));
			}
		}
		level++;
	}
	return make_pair(0, 0);
}
vector<string> buildPath(int i, int j) {
	vector<string> ans;
	while (true) {
		if (visit[make_pair(i, j)].first == -1) {
			break;
		}
		pair<int, int> val = visit[make_pair(i, j)];
		if (val.first > i)
			ans.push_back("forth");
		else if (val.second > j)
			ans.push_back("left");
		else
			ans.push_back("right");
		i = val.first, j = val.second;
	}
	return ans;
}
void printPath(int i, int j) {
	vector<string> ans = buildPath(i, j);
	for (int i = (int) ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
		if (i)
			cout << " ";
	}
	cout << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int beginI, beginJ;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '@')
					beginI = i, beginJ = j;
			}
		}
		pair<int, int> end = bfs(beginI, beginJ);
		printPath(end.first, end.second);
	}
}


