
/*
 * Idea :
 * the greatest common divior of factorial a and factorial b is factorial the minimum number between a and b
 */



#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	long long ans = min(a, b);
	int tmp = ans;
	for(int i = 1;i < tmp ;i++) {
		ans *= (1ll * i);
		////cout << i << endl;
	}
	cout << ans << endl;
}
