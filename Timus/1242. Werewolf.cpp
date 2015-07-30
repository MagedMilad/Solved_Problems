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

int n;
vvi parent , child;
int sol;
bool vis[1005];

void dfs1(int u){
	if(vis[u])
		return;
	vis[u]=1;
	sol--;
	for(int i=0;i<sz(child[u]);i++){
		int v = child[u][i];
		if(!vis[v])
			dfs1(v);
	}
}
void dfs2(int u){
	if(vis[u])
			return;
	vis[u]=1;
	sol--;
	for(int i=0;i<sz(parent[u]);i++){
		int v = parent[u][i];
		if(!vis[v])
			dfs2(v);
	}
}

int main() {
//	freopen("in.txt","r",stdin);
	cin>>n;
	string str;
	getline(cin,str);
	parent.resize(n+1);
	child.resize(n+1);
	while(getline(cin,str)){
		if(str=="BLOOD")
			break;
		ss s(str);
		int c , p;
		s>>c>>p;
		parent[c].push_back(p);
		child[p].push_back(c);
	}
	clr(vis,false);
	sol=n;
	int u;
	while(cin>>u){
		dfs1(u);
		for(int i=0;i<sz(parent[u]);i++)
			dfs2(parent[u][i]);
	}
//	printf("%d\n",sol);
	if(sol==0){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		printf(i==n?"%d\n" : "%d ",i);
	return 0;
}











