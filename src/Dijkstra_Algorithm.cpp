//============================================================================
// Name        : Dijkstra_Algorithm.cpp
// Author      : Ahmed Abd el Moniem
// Version     :
// Copyright   : For free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "graph_class.h"


int main()
{
	bool is_connected;

	int num_nodes = 5;
	float density = 0.5;

	cout << "**************** Class Iteration ******************" << endl;

	Graph my_graph(num_nodes,density);
	my_graph.GraphPrint();

	is_connected = my_graph.IsGraphConnected();
	cout << "Is Connected = " << is_connected << endl;


	return 0;
}
