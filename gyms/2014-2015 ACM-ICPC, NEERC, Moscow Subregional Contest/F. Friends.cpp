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

const ll oo = 1e9 + 1;
const double eps = 1e-9;
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
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)
#define LSOne(S) (S & (-S))
////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int time_dif(int sh, int sm, int eh, int em) {
	int s = (sh * 60 + sm) * 60;
	int e = (eh * 60 + em) * 60;
	return e - s;
}

bool PointOnRay(const point &a, const point & b, const point &p) {
	return fabs(cross(vec(a,b), vec(a,p))) < eps
			&& dot(vec(a,b),vec(a,p)) > -eps;
}

bool PointOnline(const point &a, const point &b, const point &p) {
	return fabs(cross(vec(a,b), vec(a,p))) < eps;
}

bool PointOnSegment(const point &a, const point & b, const point &p) {
	if (lengthSqr(vec(a,b)) < eps)
		return lengthSqr(vec(a,p)) < eps;
	return PointOnRay(a, b, p) && PointOnRay(b, a, p);
}

int main() {
//	freopen("in.txt", "r", stdin);
	point a, b, c;
	scanf("%lf %lf", &a.real(), &a.imag());
	scanf("%lf %lf", &b.real(), &b.imag());
	scanf("%lf %lf", &c.real(), &c.imag());
	double d, v;
	scanf("%lf %lf", &d, &v);
	int th, tm, fh, fm;
	scanf("%d:%d %d:%d", &th, &tm, &fh, &fm);
	double w;
	scanf("%lf", &w);
	v = v / 60 / 60;
	w = w / 60 / 60;
	d *= 60;
	double petr = 0, alex = 0, dmitry = 0;
	alex = d + (dist(a,c) / (double) v) + (dist(c,b) / (double) v);
	dmitry = time_dif(9, 0, th, tm) + (fh * 60 + fm) * 60;
	if (PointOnSegment(a, b, c)) {
		petr = d + (dist(a,c) / (double) w) + (dist(c,b) / (double) w);
	} else {
		petr = (dist(a,b) / (double) w);
	}
	if (alex < petr && alex < dmitry) {
		printf("Alex\n");
	} else if (dmitry < alex && dmitry < petr) {
		printf("Dmitry\n");
	} else {
		printf("Petr\n");
	}
	return 0;
}

