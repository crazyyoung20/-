#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int q[N];

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++) cin>>q[i];
    
    sort(q,q+n);
    
    cout<<q[n-1];
    if(n%2==1) cout<<" "<<q[n/2];
    else cout<<" "<<(q[n/2-1]+q[n/2])/2.0;
    cout<<" "<<q[0];
    
    return 0;
}
