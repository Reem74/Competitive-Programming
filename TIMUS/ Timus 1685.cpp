#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
string s;
char ans[N];
int k = 0;
void solve(int start, int end) {
	if(start > end)
		return;
	int mid =  (start + end) / 2;
	ans[mid] = s[k++];
	solve(start, mid - 1);
	solve(mid + 1 , end);
}

int main() {
	getline(cin , s);
	solve(0, (int)s.size() - 1);
	cout << ans;
}
