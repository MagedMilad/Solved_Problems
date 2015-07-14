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

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = (ll) 1e9 + 1;
const double eps = 1e-9;
const ll mod = 1000000007;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((ll)v.size())
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

vector<int> s;
vector<bool> vis;
vector<vector<int> > a;
vector<int> len;
vector<int>parent;
vector<int>path;
int val[35][35];
int n, t;

void tls(int u) {
	vis[u] = true;
	for (int i = 0; i < sz(a[u]); i++) {
		int v = a[u][i];
		if (!vis[v])
			tls(v);
	}
	s.push_back(u);
}

bool contain(int u, int v) {
	for (int i = 0; i < t; i++) {
		if (val[u][i] >= val[v][i])
			return false;
	}
	return true;
}

void dfs(int u){
	for(int i=0;i<sz(a[u]);i++){
		int v = a[u][i];
		if(len[v] < len[u]+1){
			len[v]=len[u]+1;
			parent[v]=u;
			dfs(v);
		}
	}
}

void getPath(int u){
	if(parent[u]==-1){
		path.push_back(u);
		return;
	}
	getPath(parent[u]);
	path.push_back(u);
}

int main() {
	freopen("in.txt", "r", stdin);

	while (cin >> n >> t) {

		a.resize(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < t; j++) {
				cin>>val[i][j];
			}
		}
		for(int i=0;i<n;i++){
			sort(val[i],val[i]+t);
			a[i].clear();
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(contain(i,j))
					a[i].push_back(j);
			}
		}
		vis.assign(n, false);
		s.clear();
		for (int i = 0; i < n; i++) {
			if (!vis[i])
				tls(i);
		}
		reverse(all(s));
		parent.assign(n,-1);
		len.assign(n, -1);
		for (int i = 0; i < sz(s); i++) {
			if (len[i] == -1) {
				dfs(i);
			}
		}
		int mx=-oo;
		int idx=-1;
		for(int i=0;i<n;i++){
			if(len[i] > mx){
				mx = len[i];
				idx = i;
			}
		}
		path.clear();
		getPath(idx);
		printf("%d\n",sz(path));
		for(int i=0;i<sz(path);i++){
			if(i)
				printf(" ");
			printf("%d",path[i]+1);
		}
		printf("\n");
	}
	return 0;

}

