#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int s,d,w;
};
//min heap/priority Queue
void heapify(Edge e[],int i,int size){
    int left = 2*i+1,right =  2*i+2,min = i;
    if(left < size && e[left].w < e[min].w)
    min = left;
    if(right < size && e[right].w < e[min].w)
    min = right;   
    if(min!=i){
        Edge temp = e[min];
        e[min] = e[i];
        e[i] = temp;
        heapify(e,min,size);  
    }
}
void Priority_Queue(Edge e[],int size){
    for(int i = size/2 ; i>=0;i--){
        heapify(e,i,size);
    }
}
Edge del(Edge e[],int &size){
    Edge temp = e[0];
    e[0]=e[size-1];
    e[size -1] = temp;
    --size;
    Priority_Queue(e,size);
    return e[size];
}
// int main(){
//     Edge e[5] = {{1,1,13},{3,0,26},{2,1,16},{0,3,12},{2,5,10}};
//     int size = 5;
//     Priority_Queue(e,5);
//     cout<<del(e,size).w<<" "<<size;
//     return 0;
// }
