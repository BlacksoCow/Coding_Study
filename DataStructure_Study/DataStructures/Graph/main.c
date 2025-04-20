#include <stdio.h>
#include "ALGraph.h"
int main(int argc, char** argv)
{
	Graph graph;
	GraphInit(&graph, 6);
	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);
	ShowGraphInfo(&graph);
	GDestroy(&graph);
	return 0;
}