
/*
 * Idea :
 * by making a use of the distance equation we can get the x and y
 * of the missing point.
 * here we have a rectangle so there is 2 lines equal each other 
 * on the distance
 * also the other 2 lines equal each other on the distance
 * by getting the distance of the missing line and by knowing
 * one end-point i get the other.
 * as this is a rectangle the distance will always equal 
 * d =( x1 - x2) or d = (y1 - y2)
 * so if the i get the distance of the parallel line to the missing line 
 * and making the numerator equals the numerator of the parallel line 
 * i can get the x and again doing this for the denominator 
 */


#include <bits/stdc++.h>
using namespace std;
int main() {
	double x[4], y[4];
	while (cin >> x[0]) {
		cin >> y[0];
		for (int i = 1; i < 4; i++) {
			cin >> x[i] >> y[i];
		}
		double x2, x1;
		if (x[1] == x[2] && y[1] == y[2]) {
			x1 =  x[3] - x[1] + x[0] ;
			x2 =  y[3] - y[1] + y[0] ;

		} else if (x[1] == x[3] && y[1] == y[3]) {
			x1 =  x[2] - x[1] + x[0] ;
			x2 =  y[2] - y[1] + y[0] ;


		} else if (x[0] == x[2] && y[0] == y[2]) {
			x1 =  x[3] - x[0] + x[1] ;
			x2 =  y[3] - y[0] + y[1] ;

		} else {
			x1 =  x[2] - x[0] + x[1] ;   
			x2 =  y[2] - y[0] + y[1] ;

		}
		cout << fixed << setprecision(3) << x1 << ' ' << x2 << endl;
	}
}

