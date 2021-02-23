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
struct Segtree{
    int size;
    vector<int> tree;
    void init(int n){
        size=1;
        while(size<n)
            size=size*2;
        tree.assign(2*size,0);
    }
    void set(int i,int val,int v,int tl,int tr){// set has a time complexity of nlogn
        if(tr-tl==1){
            tree[v]=val;
            return;
        }
        int tm=(tl+tr)/2;
        if(i<tm)
            set(i,val,2*v+1,tl,tm);
        else
            set(i,val,2*v+2,tm,tr);
        tree[v]=__gcd(tree[2*v+1],tree[2*v+2]);
    }
    void set(int i,int val){
        set(i,val,0,0,size);
    }
    void build(vector<int>& a,int v,int tl,int tr){
        if(tr-tl==1)
        {
            if(tl<a.size())
                tree[v]=a[tl];
            return;
        }
        int tm=(tl+tr)/2;
        build(a,2*v+1,tl,tm);
        build(a,2*v+2,tm,tr);
        tree[v]=__gcd(tree[2*v+1],tree[2*v+2]);
    }
    void build(vector<int>& a){
        build(a,0,0,size);
    }
    
    int query(int ql,int qr,int v,int tl,int tr){
        if(tl>=qr || tr<=ql)
            return -1;
        if(ql<=tl && tr<=qr)
            return tree[v];
        int tm=(tl+tr)/2;
        int l=query(ql,qr,2*v+1,tl,tm);
        int r=query(ql,qr,2*v+2,tm,tr);
        if(l==-1 || r==-1){
            if(l==-1){
                return r;
            }
            return l;
        }
        return __gcd(l,r);
    }
    int query(int ql,int qr){
        return query(ql,qr,0,0,size);
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    Segtree st;
    st.init(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    st.build(a);
    int answer=INF;
    int l=0;
    for(int r=0;r<n;r++){
        while(st.query(l,r+1)==1){
            answer=min(answer,r-l+1);
            l++;
        }        
    }
    if(answer==INF){
    	cout<<-1<<endl;
	} 
	else{
		cout<<answer<<endl;
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