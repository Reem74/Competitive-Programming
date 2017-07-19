

/*
   Idea :
if i have a number the best answer for it is to divide it to groups its size is small as possible 
i can do that by dividing the number of the smallest number that can divide this number and
 add the answer and apply this over and over till the number >= 1 
i do this by dividing this number on its smallest prime number that can divide this number and then add the answer to some vatiable which is 
(the sum of number from ((n / smallest prime number  ) - 1  ) to 1 ) * the prime number
 */



#include <cstring>
#include <stdio.h>

using namespace std;
const int N = 5e6 + 1, INF = 1e9 + 7;
int notprime[N], memo[N], fp[N];
void f() {
	for (int i = 1; i < N; i++) {
		fp[i] = fp[i - 1] + i;
		fp[i] %= INF;
	}
}
int solve(int k) {
	if (k == 1)
		return 0;
	int &ret = memo[k];
	if (ret != -1)
		return ret;
	if(!notprime[k])
		notprime[k] = k;
	long long ans = (k / notprime[k]) * 1ll * fp[notprime[k] - 1];
	ans %= INF;
	ret = ans;
	ret += solve(k / notprime[k]) ;
	return ret;
}
void seive() {
	for (int i = 2; i  * i < N; i++) {
		if (!notprime[i]) {
			for (int j = i * i; j < N; j += i) {
				if (!notprime[j])
					notprime[j] = i;
			}
		}
	}
}
int main() {
	memset(memo, -1, sizeof memo);
	seive();
	f();
	int l, r, t;
	scanf("%d%d%d", &t, &l, &r);
	int z = 0;
	long long ans, po = 1;
	for (int i = l, cnt = 0; i <= r; i++, cnt++) {
		ans  = solve(i);
		ans *= po;
		po *= t;
		po %= INF;
		ans %= INF;
		z += ans;
		z %= INF;
	}
	printf("%d\n", z);
}

