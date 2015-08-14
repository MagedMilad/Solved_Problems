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
const ll mod = 1000000000;

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

int n, m;
vvi a(101);
vvi comp(101);
int col1[101], col2[101],c;
bool vis[101];
int memo[101][200];
vi sol, p1, p2;

int solve(int idx, int sum) {
	if (idx == c) {
		if (sum == n/2)
			return 1;
		return 0;
	}
	if (sum > n/2)
		return false;
	if (memo[idx][sum] != -1)
		return memo[idx][sum];
	int p1 = solve(idx + 1, sum + col1[idx]);
	int p2 = solve(idx + 1, sum + col2[idx]);
	return memo[idx][sum] = max(p1, p2);
}

void trace(int idx, int sum) {
	if (idx == c) {
		if (sum == n/2)
			return;
	}
	if (sum > n/2)
		return;
	int pp1 = solve(idx + 1, sum + col1[idx]);
	int pp2 = solve(idx + 1, sum + col2[idx]);
	int ret = solve(idx, sum);
	if (pp1 == ret)
		sol.push_back(1), trace(idx + 1, sum + col1[idx]);
	else
		sol.push_back(2), trace(idx + 1, sum + col2[idx]);
}

bool bfs(int s, int c, int call) {
	queue<int> q;
	q.push(s);
	int color = call;
	int col[101];
	clr(col, 0);
	col[s] = color;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		comp[c].push_back(u);
		vis[u] = 1;
		if (col[u] == 1)
			col1[c]++, p1.push_back(u);
		else
			col2[c]++, p2.push_back(u);
		for (int i = 0; i < sz(a[u]); i++) {
			int v = a[u][i];
			if (col[v] != 0 && col[u] == col[v])
				return false;
			if (!col[v]) {
				col[v] = 3 - col[u];
				q.push(v);
			}
		}
	}
	return true;
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	n *= 2;
	clr(vis, false);
	bool ok = true;
	c=0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			ok &= bfs(i, c++, 1);
		}
	if (!ok) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	clr(memo,-1);
	int ret = solve(0, 0);
	if (ret == 0) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	trace(0, 0);
	p1.clear();
	p2.clear();
	clr(vis, false);
	c = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			bfs(i, c++, sol[c]);
		}
	for (int i = 0; i < sz(p1); i++)
		printf("%d ", p1[i]);
	printf("\n");
	for (int i = 0; i < sz(p2); i++)
		printf("%d ", p2[i]);
	printf("\n");
	return 0;
}

