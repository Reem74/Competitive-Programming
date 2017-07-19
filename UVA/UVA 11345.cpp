



/*
 * Idea :
 * i get the max x and y from the bottom left and the the min x and y from
 * the top right and get the  area of the rectangle 
 * area = (min x from left  - max x from right ) *
 * (min y from left  - max y from right ) *
 */


#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, cnt = 0;
	cin >> t;
	while(t--) {
		int m;
		cin >> m;
		cnt++;
		double  x = -1e9, x1 = 1e9, y = -1e9, y1 = 1e9;
		for(int i = 0 ; i < m;i++) {
			double tmpx, tmpy;
			cin >> tmpx >> tmpy;
			x = max(x, tmpx), y = max(y, tmpy);
			double >> tmpx >> tmpy;
			x1 = min(x1, tmpx), y1 = min(y1, tmpy);
		}
		cout << "Case "  << cnt << ": ";
		if((x1 - x) > 0 && (y1 - y) > 0)
			cout << (x1 - x) * (y1 - y) << endl;
		else
			puts("0");
	}
}

