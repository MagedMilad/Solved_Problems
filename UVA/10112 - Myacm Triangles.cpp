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
typedef complex<int> pointINT;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

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
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>eps)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)

/////////////////////////////////////////////////////////////////////////
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

bool intersectSeg(const point &a, const point &b, const point &p,
		const point &q, point & ret) {
	double d1 = cross(p - a, b - a);
	double d2 = cross(q - a, b - a);
	ret = (d1 * q - d2 * p) / (d1 - d2);
	if (PointOnSegment(a, b, p) || PointOnSegment(a, b, q)
			|| PointOnSegment(p, q, a) || PointOnSegment(p, q, b))
		return true;
	return fabs(d1 - d2) > eps && PointOnSegment(a, b, ret)
			&& PointOnSegment(p, q, ret);
}

bool intersectLine(const point &a, const point &b, const point &p,
		const point &q, point & ret) {
	double d1 = cross(p - a, b - a);
	double d2 = cross(q - a, b - a);
	ret = (d1 * q - d2 * p) / (d1 - d2);
	if (PointOnSegment(a, b, p) || PointOnSegment(a, b, q)
			|| PointOnSegment(p, q, a) || PointOnSegment(p, q, b))
		return true;
	return fabs(d1 - d2) > eps;
}

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

double getAngle(double a, double b, double c) {
	return acos((a * a + b * b - c * c) / 2 * a * b);
}

void perBisection(point &a, point &b, point &c, point &d) {
	point mid = (a + 0.5 * (b - a));
	double x = vec(a,b).real();
	double y = vec(a,b).imag();
	point p1(-1 * y, x);
	point p2(y, -1 * x);
	p1 = p1 + mid;
	p2 = p2 + mid;
	c = p1;
	d = p2;
}

int turn(point O, point A, point B) {
	double res = (A.real() - O.real()) * (B.imag() - O.imag())
			- (A.imag() - O.imag()) * (B.real() - O.real());
	if (res < 0)
		return -1;
	if (res > 0)
		return 1;
	return 0;
}

int dotProd(pointINT a, pointINT b) {
	return a.real() * b.real() + a.imag() * b.imag();
}

int crossProd(point a, point b) {
	return a.real() * b.imag() - a.imag() * b.real();
}

bool cmpPoint(point a, point b) {
	if (a.real() == b.real())
		return a.imag() < b.imag();
	return a.real() < b.real();
}

point pivot(0, 0);

bool cmpAngle(point a, point b) {
	if (collinear(pivot, a, b))
		return distsqr(pivot,a) < distsqr(pivot, b);
//	return ccw(pivot, a, b);
	double d1x = a.real() - pivot.real();
	double d1y = a.imag() - pivot.imag();
	double d2x = b.real() - pivot.real();
	double d2y = b.imag() - pivot.imag();
	return (atan2(d1y, d1x) - atan2(d2y, d2x) < 0);
}

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

vector<point> CH(vector<point> P) {
	sort(P.begin(), P.end(), cmpPoint);

	int n = P.size(), k = 0;
	point H[2 * n];

	for (int i = 0; i < n; i++) {
		while (k >= 2 && !ccw(H[k - 2], H[k - 1], P[i]))
			k--;
		H[k++] = P[i];
	}

	for (int i = n - 2, t = k; i >= 0; i--) {
		while (k > t && !ccw(H[k - 2], H[k - 1], P[i]))
			k--;
		H[k++] = P[i];
	}

	return vector<point>(H, H + k - 1);
}

double get_angle(point a, point b, point c) {
	double ux = b.real() - a.real();
	double uy = b.imag() - a.imag();
	double vx = c.real() - a.real();
	double vy = c.imag() - a.imag();
	return acos(
			(ux * vx + uy * vy)
					/ sqrt((ux * ux + uy * uy) * (vx * vx + vy * vy)));
}

double cross_p(point p, point q, point r) {
	return (r.real() - q.real()) * (p.imag() - q.imag())
			- (r.imag() - q.imag()) * (p.real() - q.real());
}

bool inPolygon(point P, vector<point> poly) {
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

double area(vector<point> poly) {
	if (!sz(poly))
		return 0.0;
	double res = 0, x1, y1, x2, y2;
	poly.push_back(poly[0]);
	for (int i = 0; i < sz(poly) - 1; i++) {
		x1 = poly[i].real();
		x2 = poly[i + 1].real();
		y1 = poly[i].imag();
		y2 = poly[i + 1].imag();
		res += (x1 * y2 - x2 * y1);
	}
	return fabs(res / 2.0);
}

bool pointOnPoly(point p1, vector<point> p ) {
//	p.push_back(p[0]);
	for (int i = 0; i < sz(p) - 1; i++) {
		if(PointOnSegment(p[i],p[i+1],p1))
			return false;
	}
	return true;
}



int main() {
	freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n && n) {
		vector<point> p(n);
		for (int i = 0; i < n; i++) {
			char temp;
			cin >> temp;
			cin >> p[i].real() >> p[i].imag();
		}
		vector<int> res;
		double mx = -1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					vector<point> poly;
					poly.clear();
					poly.push_back(p[i]);
					poly.push_back(p[j]);
					poly.push_back(p[k]);
					poly.push_back(p[i]);
					bool ok = true;
					for (int x = 0; x < n; x++) {
						if (x != i && x != j && x != k) {
							if (inPolygon(p[x], poly) || !pointOnPoly(p[x],poly)) {
								ok = false;
								break;
							}
						}

					}

					if (ok) {
						double a = 0.5
								* ((p[k].imag() - p[i].imag())
										* (p[j].real() - p[i].real())
										- (p[j].imag() - p[i].imag())
												* (p[k].real() - p[i].real()));
						if (abs(a) > mx) {
							mx = abs(a);
							res.clear();
							res.push_back(i);
							res.push_back(j);
							res.push_back(k);
						}
					}
				}
			}
		}
//		cout<<sz(res)<<endl;
		for (int i = 0; i < sz(res); i++)
			printf("%c", 'A' + res[i]);
		printf("\n");
	}
	return 0;
}

