#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#define int long long 
#define MOD 1000000007
#define MOD2 1000000014000000049L
#define PI 3.1415926535
#define INF 1e18 
#define ve vector
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define bs binary_search
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(g, i, n) for (int g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
using namespace std;
#define debug(x) do { std::cerr <<#x<<":"<< x<<"   "; } while (0)
//===================================================================================================================
// THE FIRST PRINCIPLE, IS THAT YOU MUST NOT FOOL YOURSELF, AND YOU ARE THE EASIEST PERSON TO FOOL- Richard Feynman.
// ******************************************************************************************************************
vector<set<int>> adj(50003);
vector<int> p(200005,-1);
vector<int> sz(200005,0);
int get(int a){
    if(p[a]!=a){
        p[a]=get(p[a]);
    }
    return p[a];
}
void unify(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b){
        return;
    }
    if(sz[a]<sz[b]){
        swap(a,b);
    }
    p[b]=a;
    sz[a]+=sz[b];
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        // connect these two
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<int> answer;
    vector<pair<int,pair<int,int>>> queries;
    for(int i=0;i<k;i++){
        string s;
        cin>>s;
        int x,y;
        cin>>x>>y;
        if(s=="ask"){
            queries.pb({1,{x,y}});
        }
        else{
            adj[x].erase(y);
            adj[y].erase(x);
            queries.pb({-1,{x,y}});
        }
    }
    reverse(all(queries));
    for(int i=1;i<=n;i++){
        p[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(auto j : adj[i]){
            unify(i,j);
        }
    }
    for(auto q : queries){
        int op=q.first;
        int x=q.second.first;
        int y=q.second.second;
        if(op==-1){
            unify(x,y);
        }
        else{
            x=get(x);
            y=get(y);
            if(x==y){
                answer.pb(1);
            }
            else{
                answer.pb(0);
            }
        }      
    }
    reverse(all(answer));
    for(auto x : answer){
        if(x==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
}
signed main() 
{ 
    FAST;
    solve();
    return 0; 
} 



// Paste for reading from input file
//#ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
//#endif




int power(int base, int exp) {
   int res=1;
   while(exp>0) {
      if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
   }
   return res%MOD;
}






// sometimes I believe compiler ignores all my comments