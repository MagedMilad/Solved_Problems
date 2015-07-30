//============================================================================
// Name        : Practice.cpp
// author      :
// Version     :
// Copyright   :
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

const ll oo = (ll) 1e9 + 1;
const double eps = 1e-20;
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
//#define dist(a,b) (sqrt(pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0)))
//#define distsqr(a,b) (((a)*(conj(a))).real())
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int n, m;

struct node {
	int v, dist, dir;

	node(int v, int dist, int dir) :
			v(v), dist(dist), dir(dir) {
	}
	bool operator <(const node &other) const{
		return dist > other.dist;
	}
};

struct edge {
	int v, dir;

	edge(int v, int dir) :
			v(v), dir(dir) {
	}
};

vector<vector<edge> > adj(10001);
priority_queue<node> q;
bool vis[10001][2];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(edge(v,0));
		adj[v].push_back(edge(u,1));
	}
	int s, e;
	scanf("%d %d", &s, &e);
	q.push(node(s,0,0));
	q.push(node(s,0,1));
	clr(vis,false);
	while(!q.empty()){
		node cur = q.top();
		q.pop();
		vis[cur.v][cur.dir]=1;
		int u = cur.v;
		int dir1 = cur.dir;
		int dist = cur.dist;
		if(u==e){
			printf("%d",cur.dist);
			return 0;
		}
		for(int i=0;i<sz(adj[u]);i++){
			int v = adj[u][i].v;
			int dir2 = adj[u][i].dir;
			if(dir1==dir2){
				if(!vis[v][dir2])
					q.push(node(v,dist,dir2));
			}
			else{
				if(!vis[v][dir2])
					q.push(node(v,dist+1,dir2));
			}
		}
	}

}










