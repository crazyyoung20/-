#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 5e4, M = 1e5;

int par[N], Rank[N];
int n,m,root;

struct edge{
    int a,b,c;
    bool operator<(const edge& that)const{
        return c<that.c;
    }
};

edge edges[M];

void init(){
    for(int i=0;i<n;i++){
        par[i]=i;
        Rank[i]=0;
    }
}

int find(int x){
    if(x==par[x]) return x;
    return par[x]=find(par[x]);
}

void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return ;
    if(Rank[x]<Rank[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(Rank[x]==Rank[y]) Rank[x]++;
    }
}

bool same(int x,int y) {
    return find(x)==find(y);
}

int main(){

    cin>>n>>m>>root;
    init();

    for(int i=0;i<m;i++){
        cin>>edges[i].a>>edges[i].b>>edges[i].c;
    }
    sort(edges,edges+m);
    
    int ans=-0x3f;
    for(int i=0;i<m;i++){
        if(!same(edges[i].a,edges[i].b)) {
            unite(edges[i].a,edges[i].b);
            ans=max(edges[i].c,ans);
        }
    }
    cout<<ans;
    return 0;
    
}
