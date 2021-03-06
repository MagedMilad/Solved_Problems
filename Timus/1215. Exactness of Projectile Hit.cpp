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
//#define distsqr(a,b) (((a)*(conj(a))).real())
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

double PointLineDistance(const point &a, const point &b, const point &p,
		point &res) {
	double scale = dot(vec(a,b),vec(a,p)) / lengthSqr(vec(a,b));
	res.real() = a.real() + scale * (b.real() - a.real());
	res.imag() = a.imag() + scale * (b.imag() - a.imag());
	return dist(p, res);
}

double pointSegmentDistance(const point &a, const point &b, const point &p,
		point &res) {
	double det = dot(vec(a,b),vec(a,p)) / lengthSqr(vec(a,b));
	if (det < 0) {
		res = a;
		return dist(a, p);
	}
	if (det > 1) {
		res = b;
		return dist(b, p);
	}
	return PointLineDistance(a, b, p, res);
}


bool inPolygon(point P, vector<point> poly) {
	if (!sz(poly))
		return false;

	bool in = 0;
	int n = poly.size();

	for (int i = 0, j = n - 1; i < n; j = i++) {
		if ((poly[i].imag() <= P.imag() + eps && P.imag() < poly[j].imag())
				|| (poly[j].imag() <= P.imag() + eps
						&& P.imag() < poly[i].imag())) {
			if (P.real() - eps
					< (poly[j].real() - poly[i].real())
							* (P.imag() - poly[i].imag())
							/ (poly[j].imag() - poly[i].imag())
							+ poly[i].real())
				in ^= 1;
		}
	}
	return in;
}

int main() {
//	freopen("in.txt", "r", stdin);
	point c;
	cin>>c.real()>>c.imag();
	int n;
	cin>>n;
	vector<point>p;
	for(int i=0;i<n;i++){
		double x , y;
		cin>>x>>y;
		p.push_back(point(x,y));
	}
	p.push_back(p[0]);
	if(inPolygon(c,p)){
		printf("0.000\n");
		return 0;
	}
	double mi = oo;
	point res;
	for(int i=0;i<n;i++){
		mi = min(mi , pointSegmentDistance(p[i],p[i+1],c,res));
	}
	printf("%.3lf\n",2*mi);
	return 0;
}




















