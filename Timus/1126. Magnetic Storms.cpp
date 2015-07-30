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

const ll oo = 0x3f3f3f3f;
const double eps = 1e-6;
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

#define MAX_N 25000
#define LOG_TWO_N 15

class RMQ {
private:
	int _a[MAX_N], spt[MAX_N][LOG_TWO_N];
public:
	RMQ(int n, int a[]) {
		for (int i = 0; i < n; i++) {
			_a[i] = a[i];
			spt[i][0] = i;
		}
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; i + (1 << j) - 1 < n; i++) {
				if (_a[spt[i][j - 1]] > _a[spt[i + (1 << (j - 1))][j - 1]]) {
					spt[i][j] = spt[i][j - 1];
				} else {
					spt[i][j] = spt[i + (1 << (j - 1))][j - 1];
				}
			}
		}
	}
	int query(int i, int j) {
		int k = (int) floor(log((double) j - i + 1) / log(2.0));
		if (_a[spt[i][k]] > _a[spt[j - (1 << k) + 1][k]])
			return spt[i][k];
		return spt[j - (1 << k) + 1][k];
	}
};

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int cnt = 0;
	int a[MAX_N];
	int num;
	while (cin >> num && num != -1) {
		a[cnt] = num;
		cnt++;
	}
	RMQ sol(cnt, a);
	for (int i = 0; i + n - 1 < cnt; i++) {
		printf("%d\n", a[sol.query(i, i + n - 1)]);
	}
	return 0;
}

