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

int n, m;
pair<int, int> a[30];
vector<int> special;
ll dp[30][40];

void init() {
	for (int i = 0; i < 30; i++)
		a[i] = make_pair(-1, -1);
	special.clear();
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 40; j++)
			dp[i][j] = 0;
}

int main() {
	freopen("in.txt", "r", stdin);
	while (cin >> n) {
		init();
		for (int i = 0; i < n; i++) {
			char current, zero, one, kind;
			cin >> current >> zero >> one >> kind;
			a[current - 'A'] = make_pair(zero - 'A', one - 'A');
			if (kind == 'x')
				special.push_back(current - 'A');
		}
		cin >> m;

		dp[0][0] = 1;
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (a[k].first == j) {
						dp[j][i] += dp[k][i - 1];
					}
					if (a[k].second == j) {
						dp[j][i] += dp[k][i - 1];
					}
				}
			}
		ll res = 0;
		for (int i = 0; i < sz(special); i++)
			res += dp[special[i]][m];
		printf("%lld\n", res);
	}
	return 0;

}

