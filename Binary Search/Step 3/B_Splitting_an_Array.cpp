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
int n,k;
vector<int> a(1e5+5);
bool valid(int x){
    int curr=0;
    int divide=0;
    int mx=-1;
    for(int i=0;i<n;i++){
        mx=max(mx,a[i]);
        curr+=a[i];
        if(curr==x){
            curr=0;
            if(i!=n-1)
                divide++;
        }
        else if(curr>x){
            curr=a[i];
            divide++;
        }
    }
    if(mx>x){
        return false;
    }
    return (divide<=(k-1));
}
void solve()
{
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int lo=0,hi=sum;
    int answer=sum;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(valid(mid)){
            answer=min(answer,mid);
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    if(valid(lo)){
        answer=min(answer,lo);
    }
    cout<<answer<<endl;    
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