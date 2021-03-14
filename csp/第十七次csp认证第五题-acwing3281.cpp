#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
using LL = long long;

const int N = 5e4 + 10, M = 2*N;

int h[N], e[M], ne[M], w[M], idx;

int n,m,K;
bool st[N];
int vs[N];
LL f[N][110];
LL ans = 1e18;

void add(int a,int b,int c){
    e[idx]=b, w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u, int fa){
    f[u][0] = 0;
    if(st[u]) f[u][1] = 0;
    vs[u]=1;
    for(int i=h[u]; ~i; i=ne[i]){
        int v = e[i];
        if(v == fa) continue;
        dfs(v, u);
        vs[u] += vs[v];
        for(int j=min(vs[u],K);j>=0;j--){
            for(int k=0;k<=min(j,vs[v]);k++){
                f[u][j]=min(f[u][j],f[u][j-k]+f[v][k]+(LL)w[i]*k*(K-k));
            }
        }
    }
    ans=min(ans,f[u][K]);
    return;
}

int main(){
    cin>>n>>m>>K;
    memset(h, -1, sizeof h);
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        st[x] = true;
    }
    for(int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }
    
    memset(f, 0x3f, sizeof f);
    dfs(1,-1);
    cout<<ans<<endl;
    return 0;
}
