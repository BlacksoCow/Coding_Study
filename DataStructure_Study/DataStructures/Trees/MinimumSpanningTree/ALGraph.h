#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#define TRUE 1
#define FALSE 0
#include "SimpleLinkedList.h" // For adjList
#include "ArrayStack.h" // For DFS
#include "Heap.h" // For sorting edge's weights
#include "ALEdge.h" // Information of edges containing weight
#include "Vertex.h" // Information of vertices

typedef struct
{
	int numV; // Number of vertices
	int numE; // Number of edges
	int* visitInfo; // Array for checking whether vertex was visited
	List* adjList; // List containing adjacent vertices
	Heap weightHeap; // Heap containing edge's weights in reverse order
} ALGraph;

typedef ALGraph Graph;

void GraphInit(Graph* pg, int nv);
void AddEdge(Graph* pg, Vertex fromV, Vertex toV, int weight);
void ShowGraphInfo(Graph* pg);
void ShowEdgeInfo(Graph* pg);
void DFSearch(Graph* pg, Vertex startV);
void CreateMST(Graph* pg);
void GDestroy(Graph* pg);

#endif