#include<bits/stdc++.h>
using namespace std;

class edges{
    public:
    int source;
    int dest;
    int weight;
};

//this fucntion tell how should the sort function compare the values that arr being passed to it
int compare(edges e1,edges e2){
    //here we are sorting in increasing order
    return e1.weight<e2.weight;
}

int findParent(int v , int *parent){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v],parent);
}
int kruskalMST(edges *input,int V,int E){

//Sorting the edges in the increasing order of their weights
//the third argument compare is the function which basically tell how to sort the array as we are passing a class
    sort(input,input+E,compare);

    //the output array will only have V-1 Edges
    edges *output = new edges[V-1];
    //this is the parent array for implementing the union and  find functions
    int *parent = new int[V];
    for(int i=0;i<V;i++){
        parent[i]=i;
    }

    int count=0;
    int i=0;
    //Now picking th edges one by one for sorting
    while(count!=V-1){
        //before the edge is added to ouput we need to check if there is cycle formation
        //picking the current edge
        edges currentEdge = input[i];
        int sourceParent=findParent(currentEdge.source,parent);
        int destParent=findParent(currentEdge.dest,parent);

        if(sourceParent!= destParent){
            output[count]=currentEdge;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }

    for(int i=0;i<V;i++){
        if(output[i].source<output[i].dest)
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight;
        else
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight;
    }
}

int main(){
    int V,E;
    cin>>V;
    cin>>E;
    int s , d , w;
    edges *input=new edges[E];

    for(int i=0;i<E;i++){
    cin>>s;
    cin>>d;
    cin>>w;
    input[i].source=s;
    input[i].dest=d;
    input[i].weight=w;
    }

    kruskalMST(input,V,E);
}
