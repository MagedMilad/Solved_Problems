//============================================================================
// Name        : Practice.cpp
// Author      :
// Version     :
// Copyri   :
// Description :
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;

typedef stringstream ss;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<vector<ii> > vii;
typedef vector<string> vs;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > matrix;
typedef complex<double> point;
typedef complex<long long> pointINT;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = (ll) 1e9 + 1;
const double eps = 1e-9;
const ll mod = 1000000007;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((ll)v.size())
#define clr(v, d) memset(v, d, sizeof(v))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).real(),(a).imag())
#define angle(a) atan2((a).imag() , (a).real())
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define lengthSqr(a) dot(a,a)
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateAbout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(v,m) (conj((v)/(m))*m)
#define dist(a,b) (sqrt(pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0)))
//#define distsqr(a,b) (((a)*(conj(a))).real())
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int n, k;
int a[100][100];
int memo[100][100][10][3];
bool ok = false;

int solve(int i, int j, int rem, int dir) {
	if (rem < 0)
		return -oo;
	if (i == n - 1 && j == n - 1) {
		ok = true;
		return 0;
	}
	if (memo[i][j][rem][dir] != -1)
		return memo[i][j][rem][dir];
	int res = -oo;
	if (dir == 0) {
		if (j)
			res = max(res,
					solve(i, j - 1, rem - (a[i][j - 1] < 0), 0) + a[i][j - 1]);
		if (i + 1 < n)
			res = max(res,
					solve(i + 1, j, rem - (a[i + 1][j] < 0), 2) + a[i + 1][j]);
	} else if (dir == 1) {
		if (j + 1 < n)
			res = max(res,
					solve(i, j + 1, rem - (a[i][j + 1] < 0), 1) + a[i][j + 1]);
		if (i + 1 < n)
			res = max(res,
					solve(i + 1, j, rem - (a[i + 1][j] < 0), 2) + a[i + 1][j]);
	} else {
		if (j)
			res = max(res,
					solve(i, j - 1, rem - (a[i][j - 1] < 0), 0) + a[i][j - 1]);
		if (i + 1 < n)
			res = max(res,
					solve(i + 1, j, rem - (a[i + 1][j] < 0), 2) + a[i + 1][j]);
		if (j + 1 < n)
			res = max(res,
					solve(i, j + 1, rem - (a[i][j + 1] < 0), 1) + a[i][j + 1]);
	}
	return memo[i][j][rem][dir] = res;
}

int main() {
	freopen("in.txt", "r", stdin);
	int tc = 0;
	while (cin >> n >> k) {
		ok = false;
		tc++;
		if (n == 0 && k == 0)
			break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		clr(memo, -1);
		int res = solve(0, 0, k - (a[0][0] < 0), 2) + a[0][0];
		if (ok)
			printf("Case %d: %d\n", tc, res);
		else
			printf("Case %d: impossible\n", tc);
	}
	return 0;

}

