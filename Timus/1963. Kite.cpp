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

int test1(point a, point b, point t1, point t2) {
	point ab = vec(a, b);
	point at1 = vec(a, t1);
	point test = reflect(at1, ab);
	point at2 = vec(a, t2);
	if (dist(test,at2) < eps)
		return 2;
	return 0;
}

int test2(point a, point b, point t11, point t12, point t21, point t22) {
	point ab = vec(a, b);
	point at11 = vec(a, t11);
	point at12 = vec(a, t12);
	point at21 = vec(a, t21);
	point at22 = vec(a, t22);
	point t1 = reflect(at11, ab);
	point t2 = reflect(at12, ab);
	if (dist(t1,at21) < eps && dist(t2,at22) < eps)
		return 2;
	return 0;
}

int main() {
//	freopen("in.txt", "r", stdin);
	point p[8];
	for (int i = 0; i < 4; i++)
		cin >> p[i].real() >> p[i].imag();
	p[4] = point((p[0].real() + p[1].real()) / 2,
			(p[0].imag() + p[1].imag()) / 2);
	p[5] = point((p[1].real() + p[2].real()) / 2,
			(p[1].imag() + p[2].imag()) / 2);
	p[6] = point((p[2].real() + p[3].real()) / 2,
			(p[2].imag() + p[3].imag()) / 2);
	p[7] = point((p[3].real() + p[0].real()) / 2,
			(p[3].imag() + p[0].imag()) / 2);
	int cnt = 0;
	cnt += test1(p[0], p[2], p[1], p[3]);
	cnt += test1(p[1], p[3], p[0], p[2]);
	cnt += test2(p[4], p[6], p[1], p[2], p[0], p[3]);
	cnt += test2(p[5], p[7], p[0], p[1], p[3], p[2]);
	printf("%d\n", cnt);
	return 0;
}

