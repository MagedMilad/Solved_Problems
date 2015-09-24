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

int top = 0;
map<pair<string, string>, int> m;
vvi adj;
string family[100001], first[100001], father[100001];

struct trajan {
	vector<vector<int> > sccs, graph;
	vector<int> comp_idx, ind, low_link, dp;
	stack<int> stk;
	vector<bool> inst, is_src;
	int idx = 0, mx = 0;

	void work(int u) {
		low_link[u] = ind[u] = ++idx;
		stk.push(u);
		inst[u] = true;
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			if (ind[v] == -1) {
				work(v);
				low_link[u] = min(low_link[u], low_link[v]);
			} else if (inst[v]) {
				low_link[u] = min(low_link[u], low_link[v]);
			}
		}
		if (low_link[u] == ind[u]) {
			vector<int> comp;
			int cur = -1;
			while (cur != u) {
				cur = stk.top();
				stk.pop();
				inst[cur] = false;
				comp.push_back(cur);
				comp_idx[cur] = sz(sccs);
			}
			sccs.push_back(comp);
		}
	}

	void init() {
		sccs.clear();
		comp_idx.resize(top);
		ind.clear();
		ind.resize(top, -1);
		idx = 0;
		low_link.resize(top);
		inst.resize(top);
		for (int i = 0; i < top; i++) {
			if (ind[i] == -1)
				work(i);
		}
	}

	void build_new_dag() {
		is_src.assign(top, true);
		graph.resize(sz(sccs));
		for (int i = 0; i < top; i++) {
			for (int j = 0; j < sz(adj[i]); j++) {
				int u = comp_idx[i];
				int v = comp_idx[adj[i][j]];
				if (u != v) {
					graph[u].push_back(v);
					is_src[v] = false;
				}
			}
		}
	}

	int solve(int u) {
		if (dp[u] != -1) {
			return dp[u];
		}
		int mx = 0;
		for (int i = 0; i < sz(graph[u]); i++)
			mx = max(mx, solve(graph[u][i]));
		return dp[u] = mx + sz(sccs[u]);
	}

	int longest_path() {
		dp.assign(top, -1);
		for (int i = 0; i < sz(sccs); i++) {
			if (is_src[i]) {
				solve(i);
				mx = max(mx, dp[i]);
			}
		}
		return mx;
	}

};

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string son, of;
		cin >> family[i] >> first[i] >> son >> of >> father[i];
		if (m.count(make_pair(family[i], first[i])) == 0) {
			m[make_pair(family[i], first[i])] = top++;
		}
	}
	adj.resize(top + 1);
	for (int i = 0; i < n; i++) {
		if (m.count(make_pair(family[i], father[i])))
			adj[m[make_pair(family[i], father[i])]].push_back(
					m[make_pair(family[i], first[i])]);
	}
	trajan t;
	t.init();
	t.build_new_dag();
	printf("%d\n", t.longest_path());
	return 0;
}

