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
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

const int maxnodes = 505;

int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge {
	int to, rev;
	int f, cap;
};

vector<Edge> g[maxnodes];

void addEdge(int s, int t, int cap) {
	Edge a = { t, g[t].size(), 0, cap };
	Edge b = { s, g[s].size(), cap, cap };
	g[s].push_back(a);
	g[t].push_back(b);
}

bool dinic_bfs() {
	fill(dist, dist + nodes, -1);
	dist[src] = 0;
	int qt = 0;
	q[qt++] = src;
	for (int qh = 0; qh < qt; qh++) {
		int u = q[qh];
		for (int j = 0; j < (int) g[u].size(); j++) {
			Edge &e = g[u][j];
			int v = e.to;
			if (dist[v] < 0 && e.f < e.cap) {
				dist[v] = dist[u] + 1;
				q[qt++] = v;
			}
		}
	}
	return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
	if (u == dest)
		return f;
	for (int &i = work[u]; i < (int) g[u].size(); i++) {
		Edge &e = g[u][i];
		if (e.cap <= e.f)
			continue;
		int v = e.to;
		if (dist[v] == dist[u] + 1) {
			int df = dinic_dfs(v, min(f, e.cap - e.f));
			if (df > 0) {
				e.f += df;
				g[v][e.rev].f -= df;
				return df;
			}
		}
	}
	return 0;
}

int maxFlow(int _src, int _dest) {
	src = _src;
	dest = _dest;
	int result = 0;
	while (dinic_bfs()) {
		fill(work, work + nodes, 0);
		while (int delta = dinic_dfs(src, INT_MAX))
			result += delta;
	}
	return result;
}

void init() {
	for (int i = 0; i < maxnodes; i++)
		g[i].clear();
}

int main() {
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		init();
		int n , m , v;
		cin>>n>>m>>v;
		string love[v+1],hate[v+1];
		for(int i=1;i<=v;i++){
			cin>>love[i]>>hate[i];
			bool dog = love[i][0]=='D';
			if(dog)
				addEdge(0 , i , 1);
			else
				addEdge(i , v+1 , 1);
			for(int j=1;j<i;j++){
				if(love[i]==hate[j] || hate[i]==love[j]){
					if(!dog)
						addEdge(j , i , 1);
					else
						addEdge(i ,j , 1);
				}
			}
		}
		cout<<v-maxFlow(0,v+1)<<endl;
	}
	return 0;
}















