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
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

map<string, int> id;
int top = 0, n;
vvi adj(405);
vi dist;

void bfs(){
	dist.assign(top+5 , oo);
	if(id.find("Isenbaev")==id.end())
		return;
	int s = id["Isenbaev"];
	queue<int> q;
	q.push(s);
	dist[s]=0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<sz(adj[u]);i++){
			int v = adj[u][i];
			if(dist[v]==oo){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}

int main() {
//	freopen("in.txt","r",stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		if (id.find(s1) == id.end())
			id[s1] = top++;
		if (id.find(s2) == id.end())
			id[s2] = top++;
		if (id.find(s3) == id.end())
			id[s3] = top++;
		int a = id[s1];
		int b = id[s2];
		int c = id[s3];
		adj[a].push_back(b);
		adj[a].push_back(c);
		adj[b].push_back(a);
		adj[b].push_back(c);
		adj[c].push_back(a);
		adj[c].push_back(b);
	}
	bfs();
	for(map<string, int>::iterator it = id.begin() ; it!=id.end() ; it++){
		cout<<it->first<<" ";
		if(dist[it->second]==oo)
			cout<<"undefined";
		else
			cout<<dist[it->second];
		cout<<endl;
	}
	return 0;
}













