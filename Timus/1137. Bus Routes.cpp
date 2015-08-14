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
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)
#define LSOne(S) (S & (-S))
////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

vvii adj(10001);
int in[10001], out[10001];
list<int> cyc;

void EulerTour(list<int>::iterator it, int u) {
	for (int i = 0; i < sz(adj[u]); i++) {
		if (adj[u][i].second) {
			adj[u][i].second = 0;
			for (int j = 0; j < sz(adj[adj[u][i].first]); j++) {
				if (adj[adj[u][i].first][j].first == adj[u][i].first
						&& adj[adj[u][i].first][j].second) {
					adj[adj[u][i].first][j].second = 0;
					break;
				}
			}
			EulerTour(cyc.insert(it, u), adj[u][i].first);
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		int u, v;
		cin >> u;
		for (int j = 1; j <= m; j++) {
			cin >> v;
			adj[u].push_back(ii(v, 1));
			out[u]++;
			in[v]++;
			u = v;
		}
	}
	bool ok = true;
	int start = -1;
	for (int i = 0; i < 10001; i++) {
		if (in[i])
			start = i;
		if (in[i] != out[i]) {
			ok = false;
			break;
		}
	}
	if (!ok) {
		printf("0\n");
		return 0;
	}
	cyc.clear();
	EulerTour(cyc.begin(), start);
	printf("%d", (int) cyc.size());
	reverse(all(cyc));
	for (list<int>::iterator it = cyc.begin(); it != cyc.end(); it++) {
		printf(" %d", *it);
	}
	printf(" %d\n",*cyc.begin());
	return 0;
}

