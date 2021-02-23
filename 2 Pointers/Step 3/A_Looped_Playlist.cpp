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

void solve2(){
    int n,p;
    cin>>n>>p;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int cycles=p/sum;
    p=p-cycles*sum;
    int answer=n*cycles;
    // check for 0 
    // TODO
    if(p==0){
        cout<<1<<" "<<answer<<endl;
        return;
    }
    vector<int> b(2*n-1,0);
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    for(int i=n;i<2*n-1;i++){
        b[i]=a[i-n];
    }
    int l=0;
    int curr=0;
    int len=INF;
    int idx=-1;
    for(int r=0;r<2*n-1;r++){
        curr+=b[r];
        while(curr>=p){
            if(len>r-l+1){
                len=r-l+1;
                idx=l;
            }
            curr-=b[l];
            l++;
        }
    }
    cout<<idx+1<<" "<<answer+len<<endl;
}
signed main() 
{ 
    FAST;
    solve2();
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