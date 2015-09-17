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

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int k[n + 1];
	vvi adj(n + 1);
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d %d", &k[i + 1], &m);
		for (int j = 0; j < m; j++) {
			int v;
			scanf("%d", &v);
			adj[i + 1].push_back(v);
		}
	}

	stack<int> stk;
	pair<int, int> sol[n + 1];
	for (int i = 1; i <= n; i++) {
		sol[i] = ii(-1, -1);

	}
	stk.push(1);
	sol[1] = ii(0, k[1]);
	while (!stk.empty()) {
		int u = stk.top();
		stk.pop();
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			int t1 = sol[v].first;
			int t2 = sol[v].second;
			if (sol[v].first == -1) {
				sol[v].first = sol[u].second;
			} else if (sol[v].first != sol[u].second) {
				sol[v].first = -2;
			}
			if (k[v] == 0) {
				if (sol[v].second == -1) {
					sol[v].second = sol[u].second;
				} else if (sol[v].first == -2) {
					sol[v].second = -2;
				} else if (sol[v].first != sol[u].second) {
					sol[v].second = -2;
				}
			} else {
				sol[v].second = k[v];
			}
			if (t1 != sol[v].first || t2 != sol[v].second)
				stk.push(v);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (sol[i].first == 0)
			printf("sober ");
		else if (sol[i].first == -2)
			printf("unknown ");
		else
			printf("%d ", sol[i].first);
		if (sol[i].second == 0)
			printf("sober\n");
		else if (sol[i].second == -2)
			printf("unknown\n");
		else
			printf("%d\n", sol[i].second);
	}
	return 0;
}

