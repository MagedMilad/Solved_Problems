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
const double eps = 1e-7;
const ll mod = 1234567;

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

double PointLineDistance(const point &a, const point &b, const point &p,
		point &res) {
	double scale = dot(vec(a,b),vec(a,p)) / lengthSqr(vec(a,b));
	res.real() = a.real() + scale * (b.real() - a.real());
	res.imag() = a.imag() + scale * (b.imag() - a.imag());
	return dist(p, res);
}

int n, c;

struct Line {
	point p1, p2;
} line[2];

struct City {
	point p;
	double cost;
} city[250];

double memo[210][210];
int prev[210][210];

double solve(int idx, int ones) {
	int twos = idx - ones;
	if (idx == n){
		if(abs(ones-twos) <= c){
			return 0;
		}
		return oo;
	}
	if (abs(memo[idx][ones] - oo) < 1e9)
		return memo[idx][ones];
	double p1 = oo, p2 = oo;
	point res;
	p1 = solve(idx + 1, ones + 1)
			+ (PointLineDistance(line[0].p1, line[0].p2, city[idx].p, res)
					* city[idx].cost);
	p2 = solve(idx + 1, ones)
			+ (PointLineDistance(line[1].p1, line[1].p2, city[idx].p, res)
					* city[idx].cost);
	if (p1 < p2) {
		prev[idx][ones] = 1;
	} else {
		prev[idx][ones] = 2;
	}
	return memo[idx][ones] = min(p1, p2);
}

int main() {
//	freopen("in.txt", "r", stdin);
	freopen("pipe.in","r",stdin);
	freopen("pipe.out","w",stdout);
	cin >> n >> c;
	cin >> line[0].p1.real() >> line[0].p1.imag() >> line[0].p2.real()
			>> line[0].p2.imag();
	cin >> line[1].p1.real() >> line[1].p1.imag() >> line[1].p2.real()
			>> line[1].p2.imag();
	for (int i = 0; i < n; i++) {
		cin >> city[i].p.real() >> city[i].p.imag() >> city[i].cost;
	}
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			memo[i][j] = -oo;
		}
	}
	solve(0, 0);
	int ones = 0;
	for (int i = 0; i < n; i++) {
		printf("%d ", prev[i][ones]);
		if (prev[i][ones] == 1)
			ones++;
	}
	printf("\n");

	return 0;
}

