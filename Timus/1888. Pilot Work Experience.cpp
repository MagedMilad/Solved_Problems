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
const double eps = 1e-6;
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

int n, p;
vvi adj;
int ret[51], start[51], comp[51], col[51];
bool ok = true;
int mx = -1, top = 0;

void color(int u, int val) {
	col[u] = val;
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			if (col[v] == -1) {
				col[v] = val;
				q.push(v);
			}
		}
	}
}

int bfs(int u, int val) {
	queue<int> q;
	q.push(u);
	ret[u] = val;
	mx = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
//		vis[u] = 1;
		mx = max(mx, ret[u]);
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			if (ret[v] == 0) {
				q.push(v);
				ret[v] = ret[u] + 1;
			} else if (abs(ret[u] - ret[v]) != 1) {
				ok = false;
				break;
			}
		}
	}
	return (mx - val);
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &p);
	adj.resize(p + 1);
	for (int i = 0; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	clr(col, -1);
	for (int i = 1; i <= p; i++)
		if (col[i] == -1)
			color(i, top++);
	clr(start, -1);
	clr(comp, -1);
	for (int i = 1; i <= p; i++) {
		clr(ret, 0);
		int res = bfs(i, 1);
		if (res > comp[col[i]]) {
			comp[col[i]] = res;
			start[col[i]] = i;
		}
		if (!ok)
			break;
	}
	clr(ret,0);
	if (ok) {
		if (top == 1) {
			printf("%d\n", comp[0]);
			bfs(start[0], 1);
			for (int i = 1; i <= p; i++)
				printf("%d ", ret[i]);
		} else {
			printf("49\n");
			bfs(start[0], 1);
			for (int i = 1; i < top; i++)
				bfs(start[i], 50 - comp[i]);
			for (int i = 1; i <= p; i++)
				printf("%d ", ret[i]);
		}
	} else
		printf("-1\n");
	return 0;
}

