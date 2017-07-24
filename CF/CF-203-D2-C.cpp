/*
 * IDEA:
 *every client want a photos with low quality and specific number for
  high quality so i get the value of the memory that both qualities 
  takes for each client then i sort them in an array and wake the first 
 * i can take with total sum equals d
 */


#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
pair<int, int> total[N];
int main() {
	int n, d;
	cin >> n >> d;
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		total[i].first = x * a + y * b;
		total[i].second = i + 1;
	}
	sort(total, total + n);
	long long sum = 0;
	set<int> s;
	for (int i = 0; i < n; i++) {
		sum += total[i].first;
		//cout << sum << endl;
		if (sum > d)
			break;
		s.insert(total[i].second);
	}
	cout << (int) s.size() << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *(it) << " ";
	}
}

