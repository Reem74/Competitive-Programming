/*
 * i replace each digit with the closest prime 
 * it can reach to and replace the numbers from this prime to the original 
 * number with the those numbers prime factors
 * 
 */


#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string sh;
	int numbers[9][10] = { { 2, 0 }, { 3, 0 }, { 2, 2, 3, 0 }, { 5, 0 }, { 3, 5,
			0 }, { 7, 0 }, { 7, 2, 2, 2, 0 }, { 2, 3, 3, 7, 0 } };

	for (int i = 0; i < n; i++) {
		if (s[i] == '0' || s[i] == '1')
			continue;
		int num = (s[i] - '0') - 2;
		for (int j = 0; j < 10 && numbers[num][j] != 0; j++) {
			if (numbers[num][j] != 0)
				sh += numbers[num][j] + '0';
		}
	}
	sort(sh.begin(), sh.end());
	reverse(sh.begin(), sh.end());
	cout << sh;

}

