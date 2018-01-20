
/*  i used for each test case dp solution 
 *  dp solution: by two recursors one for the first suggestion and other for the second 
 *  for each index I try to visit the city of that index or the city of
 *  the index that am standing on for the other suggest 
 *  and if i visit the city for one index i have to move the recursor of the 
 *  other suggestion so it reach to a city that is the same as mine
 *  or i try to not 
 */
#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 + 3;
int memo[N][N], nextF[N][63], nextM[N][63];
int father[N], mother[N];
int n, m;
int solve(int i, int j) {
	if (i >= n || j >= m)
		return 0;
	int &cities = memo[i][j];
	if (cities != -1)
		return cities;
	cities = solve(i + 1, j + 1) + (father[i] == mother[j]);
	if (nextM[j][(int) father[i]])
		cities = max(cities, solve(i, nextM[j][(int) father[i]]));
	if (nextF[i][(int) mother[j]])
		cities = max(cities, solve(nextF[i][(int) mother[j]], j));
	return cities;
}
int main() {
	for (int k = 1;; k++) {
		string fa, ma;
		getline(cin, fa);
		if (fa == "#")
			break;
		getline(cin, ma);
		n = fa.size(), m = ma.size();
		memset(nextF, 0, sizeof nextF);
		for (int i = 0; i < n; i++) {
			if (fa[i] == ' ') {
				father[i] = 0;
			} else if (fa[i] >= 'a' && fa[i] <= 'z') {
				father[i] = fa[i] - 'a' + 1;
			} else if (fa[i] >= 'A' && fa[i] <= 'Z') {
				father[i] = fa[i] - 'A' + 27;
			} else {
				father[i] = fa[i] - '0' + 53;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < 63; j++) {
				nextF[i][j] = nextF[i + 1][j];
			}
			nextF[i][father[i + 1]] = i + 1;
		}

		memset(nextM, 0, sizeof nextM);
		for (int i = 0; i < m; i++) {
			if (ma[i] == ' ') {
				mother[i] = 0;
			} else if (ma[i] >= 'a' && ma[i] <= 'z') {
				mother[i] = ma[i] - 'a' + 1;
			} else if (ma[i] >= 'A' && ma[i] <= 'Z') {
				mother[i] = ma[i] - 'A' + 27;
			} else {
				mother[i] = ma[i] - '0' + 53;
			}
		}
		for (int i = m - 2; i >= 0; i--) {
			for (int j = 0; j < 63; j++) {
				nextM[i][j] = nextM[i + 1][j];
			}

			nextM[i][mother[i + 1]] = i + 1;
		}
		memset(memo, -1, sizeof memo);
		int ans = solve(0, 0);
		cout << "Case #" << k << ": you can visit at most " << ans << " cities.\n" ;
	}
}



