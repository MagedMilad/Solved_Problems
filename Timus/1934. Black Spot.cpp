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
//#define distsqr(a,b) (((a)*(conj(a))).real())
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int top = 0, vis[100001], head[100001], parent[100001], dist[100001],
		n, m, s, t;
double p[100001];

struct edge {
	int v, w, next;
	double p;
} e[200002];

void addEdge(int u, int v, double p) {
	e[top].v = v;
	e[top].w = 1;
	e[top].p = p;
	e[top].next = head[u];
	head[u] = top++;
}

void init() {
	for (int i = 1; i <= n; i++) {
		head[i] = -1;
		vis[i] = false;
		dist[i] = oo;
		p[i] = 0;
		parent[i]=-1;
	}
}

void sssp() {
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	dist[s] = 0;
	p[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				parent[v] = u;
				p[v] = p[u] * e[i].p;
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			} else if (dist[v] == dist[u] + 1) {
				if (p[v] < p[u] * e[i].p) {
					parent[v] = u;
					p[v] = p[u] * e[i].p;
					if (!vis[v]) {
						vis[v] = 1;
						q.push(v);
					}
				}
			}
		}
	}
	return;
}

void print(int u){
	if(parent[u]==-1){
		printf("%d",u);
		return;
	}
	print(parent[u]);
	printf(" %d",u);
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin>>n>>m;
	init();
	cin>>s>>t;
	for(int i=0;i<m;i++){
		int u ,v , p;
		cin>>u>>v>>p;
		addEdge(u ,v ,1-(double)p/100);
		addEdge(v ,u ,1-(double)p/100);
	}
	sssp();
	printf("%d %.7lf\n",dist[t]+1 , 1-p[t]);
	print(t);
	printf("\n");
	return 0;
}



















