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

int n;
vvi adj, g;
map<string, int> loc;
int location[500], top = 1, vis[500];
vi col[2], ans;

void bfs(int u) {
	col[0].clear();
	col[1].clear();
	queue<int> q;
	q.push(u);
	vis[u] = 0;
	col[0].push_back(u);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < sz(g[u]); i++) {
			int v = g[u][i];
			if (vis[v] == -1) {
				vis[v] = !vis[u];
				q.push(v);
				col[vis[v]].push_back(v);
			}
		}
	}
	if (sz(col[0]) < sz(col[1])) {
		for (int i = 0; i < sz(col[0]); i++)
			ans.push_back(col[0][i]);
	} else {
		for (int i = 0; i < sz(col[1]); i++)
			ans.push_back(col[1][i]);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	adj.resize(n + 5);
	g.resize(n + 5);
	for (int i = 1; i <= n; i++) {
		string l;
		cin >> l;
		if (loc.find(l) == loc.end())
			loc[l] = top++;
		location[i] = loc[l];
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			int v;
			scanf("%d", &v);
//			adj[i].push_back(v);
			adj[v].push_back(i);
		}
		adj[i].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz(adj[i]); j++) {
			for (int k = j + 1; k < sz(adj[i]); k++) {
				int u = adj[i][j];
				int v = adj[i][k];
				if (location[u] != location[v]) {
					g[u].push_back(v);
					g[v].push_back(u);
				}
			}
		}
	}
	clr(vis, -1);
	for (int i = 1; i <= n; i++)
		if (vis[i] == -1)
			bfs(i);

	if (sz(ans) == 0)
		ans.push_back(1);
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++)
		printf("%d ", ans[i]);
	return 0;
}

