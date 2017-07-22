
/*
 * IDEA:
 * its known that the original string we keep getting the char of the middle 
 * then divide the array from the middle to left part and right part
 * and working on the left then right with the same way so i keep doing this
 * but instead i put at this cells the value from the input in from 0
 *  to the input  size
 * 
 */

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
