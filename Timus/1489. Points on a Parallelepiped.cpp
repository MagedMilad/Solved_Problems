//============================================================================
// Name        : Practice.cpp
// author      :
// Version     :
// Copyright   :
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > grix;
typedef complex<double> point;
typedef complex<long long> pointINT;

int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = (ll) 1e9 + 1;
const double eps = 1e-20;
const ll mod = 1000000007;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
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
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int a, b, c;

struct point3d {
	double x, y, z;
	point3d(double x, double y, double z) :
			x(x), y(y), z(z) {
	}
	point3d() :
			x(0), y(0), z(0) {
	}
	double distance(const point3d other) {
		return (sqrt(
				pow(x - other.x, 2.0) + pow(y - other.y, 2.0)
						+ pow(z - other.z, 2.0)));
	}
};

struct point2d {
	double x, y;
	point2d(double x, double y) :
			x(x), y(y) {
	}
	point2d() :
			x(0), y(0) {
	}
	void get() {
		scanf("%lf %lf", &x, &y);
	}
};

point3d solve(point2d p) {
	if (p.x >= c && p.x <= c + a) {
		if (p.y >= 0 && p.y <= b )
			return point3d(p.x, b + b + c - p.y, c);
		if (p.y >= b && p.y <= b + c )
			return point3d(p.x, b + c, c + b - p.y);
		if (p.y >= b + c && p.y <= b + b + c )
			return point3d(p.x, p.y, 0);
		if (p.y >= 2 * b + c && p.y <= 2 * (b + c) )
			return point3d(p.x, 2 * b + c, p.y - 2 * b - c);
	} else if (p.x >= 0 && p.x <= c )
		return point3d(c, p.y, c - p.x);
	else if (p.x >= a + c && p.x <= a + c + c)
		return point3d(c + a, p.y, p.x - c - a);
	return point3d(p.x, p.y, 0);
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> a >> b >> c;
	point2d p1, p2;
	p1.get();
	p2.get();
	point3d _p1 = solve(p1);
	point3d _p2 = solve(p2);
	printf("%.16lf\n", _p1.distance(_p2) + eps);
	return 0;
}

