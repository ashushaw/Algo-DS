#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int *weights , bool* visited , int n){

    int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}
void primMST(int **edges , int n){

    //n represents the no of vertices
    //parent arr gives us the array of parent of each vertex
    //visited shows whether vertex is visited or not
    //weights holds the current weight at that very instance

    int *parent = new int[n];
    bool *visited =new bool[n];
    int *weight = new int[n];

    for(int i=0;i<n;i++){
            visited[i]=false;
            weight[i]=INT_MIN;
    }

    //going through all the edges
    for(int i=0;i<n-1;i++){
            //Finding the minVertex from the set of unvisited vertices
        int minVertex=findMinVertex(weight,visited,n);
        visited[minVertex] = true;
		// Explore un visted neighbours
		for(int j = 0; j < n; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(edges[minVertex][j] < weight[j]){
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	for(int i = 1; i < n; i++){
		if(parent[i] < i){
			cout << parent[i] << i << " " << weight[i] << endl;
		}else{
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}
}

int main() {
	int n;
	int e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout << endl;
	primMST(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

