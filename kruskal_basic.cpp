#include<bits/stdc++.h>
#include"priority_que.cpp"
class Graph{
    int V,E;
    public:
       Edge *edge;
       Graph(int v,int e):V(v),E(e){}
       void addedges();
       inline int get_Vertices(){
        return V;
       }
       inline int get_Edges(){
        return E;
       }
};
void Graph::addedges(){
    std::cout<<"Enter the edges of graph in (source,dest,weight):"<<std::endl;
    edge = new Edge[E];
    for(int i = 0; i < E ;i++){
        std::cin>>edge[i].s>>edge[i].d>>edge[i].w;
    }
}
//priority Que:
extern Edge del(Edge e[],int& size);
extern void Priority_Queue(Edge e[],int size);
//make set:
void makeset(int x,int parent[]){
    parent[x]= -1;
}
//find:
int find(int x,int parent[]){
    if(parent[x]==-1)
    return x;
    else return(find(parent[x],parent));
}
//union:
void Union(int x,int y,int parent[]){
    parent[x] = y;
}
//kruskal:
int Mst_kruskal(Graph G){
    int parent[G.get_Vertices()],cost = 0;//index = 0;
    for(int i = 0; i<G.get_Vertices() ;i++)
    makeset(i,parent);
    Priority_Queue(G.edge,G.get_Edges());
    int Mst_edge_no = 0,size = G.get_Edges();
    //print Mst
    std::cout<<"\n";
    while(Mst_edge_no <G.get_Vertices() && size ){
        Edge temp = del(G.edge, size);
        int j = find(temp.s,parent), k = find(temp.d,parent);
        if(j!=k){
            Union(j,k,parent);
            cost+=temp.w;
            std::cout<<temp.s<<"----"<<temp.d<<" Weight("<<temp.w<<")\n";
            Mst_edge_no++;
        }
    }
    if( Mst_edge_no != G.get_Vertices() - 1){
    std:: cout<<"Given Graph is forest.\n";
    cost = 0;
    }
    else 
    std::cout<<"The edges in Mst are above:\n";
    return cost;
}
int main(){
    int V,E;
    std::cout<<"Enter the graph details (vertices,edges):\n";
    std::cin>>V>>E;
    Graph G(V,E);
    std::cout<<"Enter details:\n";
    G.addedges();
    int mst_cost = Mst_kruskal(G);
    std::cout<<"\nMst cost : "<<mst_cost;
    return 0;
}
