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

int d;
vector<pair<int, int> > a;
ll dp[105][205];

void init() {
	a.clear();
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 205; j++)
			dp[i][j] = LONG_LONG_MAX;
}

int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	string str;
	getline(cin, str);
	while (t--) {
		init();
		cin >> d;
		getline(cin, str);
		a.push_back(make_pair(0, 0));
		while (getline(cin, str) && sz(str)) {
			ss s(str);
			int dist, cost;
			s >> dist >> cost;
			a.push_back(make_pair(dist, cost));
		}
		a.push_back(make_pair(d, oo));
		dp[0][100] = 0;
		for (int i = 1; i < sz(a); i++) {
			int dist = a[i].first - a[i - 1].first;
			for (int j = dist; j <= 200; j++)
				dp[i][j - dist] = min(dp[i][j - dist], dp[i - 1][j]);
			for (int j = 1; j <= 200; j++)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i].second);
		}
		ll res = oo;
		for (int i = 100; i <= 200; i++)
			res = min(res, dp[sz(a)-1][i]);
		if (res == oo)
			printf("Impossible\n");
		else
			printf("%lld\n", res);
		if(t)
			printf("\n");
	}
	return 0;

}

