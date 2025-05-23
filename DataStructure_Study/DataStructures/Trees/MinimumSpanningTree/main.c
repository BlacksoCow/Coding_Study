#include <stdio.h>
#include "ALGraph.h"
int main(int argc, char** argv)
{
	Graph graph;
	GraphInit(&graph, 6); // Vertex: A, B, C, D, E, F
	AddEdge(&graph, A, B, 9);
	AddEdge(&graph, B, C, 2);
	AddEdge(&graph, A, C, 12);
	AddEdge(&graph, A, D, 8);
	AddEdge(&graph, D, C, 6);
	AddEdge(&graph, A, F, 11);
	AddEdge(&graph, F, D, 4);
	AddEdge(&graph, D, E, 3);
	AddEdge(&graph, E, C, 7);
	AddEdge(&graph, F, E, 13);
	CreateMST(&graph);
	ShowGraphInfo(&graph);
	ShowEdgeInfo(&graph);
	GDestroy(&graph);
	return 0;
}