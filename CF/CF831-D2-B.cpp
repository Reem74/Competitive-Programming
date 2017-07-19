#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 2;
int arr[N];
int main() {
	string s, sh;
	cin >> s >> sh;
	string t, ans;
	cin >> t;
	int n = t.size();
	for(int i = 0 ; i < n;i++)  {
		bool flag = 0;
		//cout << (char) (t[i] + 32) << endl;
		for(int j = 0 ;j < 26;j++) {
			//cout << (char)(t[i]  + '0') << endl;
			if(s[j] == t[i] ) {
				ans += sh[j];
				flag = 1;
				break;
			}
			else if( s[j] == t[i] + 32) {
				ans += (sh[j]  - 32);
				flag = 1 ;
				break;
			}
		}
		if(!flag)
			ans += t[i];
	}
	cout << ans ;
}
