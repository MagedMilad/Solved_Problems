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
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

bool cmpPoint(point a, point b) {
	if (a.real() == b.real())
		return a.imag() < b.imag();
	return a.real() < b.real();
}

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

ll n, d, a;
int parent[105];
int graph[105][105];
int current[105][105];

void init() {
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

int find(int i) {
	if (parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
}

bool union_find(int i, int j) {
	int ri = find(i);
	int rj = find(j);
	if (ri == rj)
		return false;
	parent[ri] = rj;
	return true;
}

struct edge {
	int u, v, cost;
	edge(int uu, int vv, int cc) :
			u(uu), v(vv), cost(cc) {
	}
	bool operator <(const edge other) {
		return cost < other.cost;
	}
};

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> d >> a;
	init();
	vector<edge> e;
	ll have = 0;
	for (int i = 0; i < n; i++) {
		string line;
		cin>>line;
		for (int j = 0; j < n; j++) {
			graph[i][j] = line[j]-'0';
//			current[i][j] = graph[i][j];
			if (graph[i][j])
				e.push_back(edge(i, j, 0)), have++;
			else
				e.push_back(edge(i, j, a));
		}
	}
	sort(all(e));
	ll pay = 0;
	have/=2;
	for (int i = 0; i < sz(e); i++) {
		if (union_find(e[i].u, e[i].v)) {
			if(graph[e[i].u][e[i].v])
				have--;
			current[e[i].u][e[i].v] = 1;
			current[e[i].v][e[i].u] = 1;
			pay += e[i].cost;
		}
	}
//	for (int i = 0; i < n; i++) {
//		for (int j = i+1; j < n; j++) {
//			if(graph[i][j] && !current[i][j])
//				pay+=d;
//		}
//	}
	printf("%lld\n",pay + have*d);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!current[i][j]){
				if(graph[i][j])
					printf("d");
				else
					printf("0");
			}
			else{
				if(graph[i][j])
					printf("0");
				else
					printf("a");
			}
		}
		printf("\n");
	}
	return 0;
}

