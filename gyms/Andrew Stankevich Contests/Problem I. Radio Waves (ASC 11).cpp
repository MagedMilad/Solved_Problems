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

vvi adj(2000);
int type[2000];
bool ok = true;

void dfs(int u, int t) {
	type[u] = t;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (type[v] == -1) {
			dfs(v, 3 - t);
		} else if (type[v] == type[u]) {
			ok = false;
			return;
		}
	}
}

int main() {
	freopen("radio.in","r",stdin);
	freopen("radio.out","w",stdout);
	int n;
	scanf("%d", &n);
	int x[n], y[n];
	double d[n][n];
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		d[i][i] = 0;
		for (int j = 0; j < i; j++) {
			d[i][j] = d[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
		}
	}
	double lo = 0, hi = 1e5;
	while (abs(hi - lo) > eps) {
		double mi = (hi + lo) / 2.0;
		for (int i = 0; i < n; i++)
			adj[i].clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] < mi && i != j) {
					adj[i].push_back(j);
				}
			}
		}
		clr(type, -1);
		ok = true;
		for (int i = 0; i < n; i++) {
			if (type[i] == -1) {
				dfs(i, 1);
			}
		}
		if (!ok) {
			hi = mi;
		} else {
			lo = mi;
		}
	}
	printf("%.10lf\n", lo / 2.0);
	for (int i = 0; i < n; i++)
		adj[i].clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] < lo && i!=j) {
				adj[i].push_back(j);
			}
		}
	}
	clr(type, -1);
	for (int i = 0; i < n; i++) {
		if (type[i] == -1) {
			dfs(i, 1);
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", type[i]);
	return 0;

}

