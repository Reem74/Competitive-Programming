
/*
 * Idea :
 *i check first if that click exist on some region and get the last region that 
 *i it's belong to and i can know that by seeing if the x of the click
 * between the top left x and the bottom right x and also for the y
 * but if it doesn't belong to come region 
 * i check the minimum distance between the click position and the icons
 * and take all the icons that equal to this minimum distance 
 * of course after checking that this icon is invisible (doesn't belong 
 * to some region)
 */



#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<pair<int, int> > I;
	vector<pair<pair<int, int>, pair<int, int> > > r;
	while (true) {
		char id;
		cin >> id;
		if (id == '#')
			break;
		int x, y;
		cin >> x >> y;
		if (id == 'I') {
			I.push_back(make_pair(x, y));
		} else if (id == 'R') {
			int x1, y1;
			cin >> x1 >> y1;
			r.push_back(make_pair(make_pair(x, y), make_pair(x1, y1)));
		} else {
			bool flag = 0;
			for (int i = (int) r.size() - 1; i >= 0; i--) {
				int tmpx = r[i].first.first, tmpx1 = r[i].second.first;
				int tmpy = r[i].first.second, tmpy1 = r[i].second.second;
				if (x >= tmpx && x <= tmpx1 && y >= tmpy && y <= tmpy1) {
					flag = 1;
					cout << (char) ('A' + i) << endl;
					break;
				}
			}
			if (!flag) {
				vector<int> ans;
				int d[100], mn = 1e9;
				for (int i = 0; i < (int) I.size(); i++) {
					int ans1 = (x - I[i].first), ans2 = (y - I[i].second);
					d[i] = (ans1 * ans1) + (ans2 * ans2);
					mn = min(mn, d[i]);
				}
				for (int i = 0; i < (int) I.size(); i++) {
					if (d[i] == mn) {
						ans.push_back(i + 1);
					}
				}
				for (int i = 0; i < (int) ans.size(); i++) {
					if (ans[i] < 10)
						cout << "  ";
					else
						cout << " ";
					cout << ans[i];
				}
				cout << endl;
			}
		}
	}
}

