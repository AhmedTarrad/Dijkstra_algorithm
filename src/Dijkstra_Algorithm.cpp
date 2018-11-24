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



void TestGraph()
{
	bool is_connected;

		int num_nodes = 5;
		float density = 0.5;

		cout << "**************** Graph Class Test ******************" << endl;

		Graph my_graph(num_nodes,density);
		my_graph.GraphPrint();

		is_connected = my_graph.IsGraphConnected();

		cout << endl << "Is Connected = " << is_connected << endl;

		cout <<"Edge Distance " << my_graph.GetEdgeDistance(1,2) << endl;
		my_graph.DeleteEdge(1,2);
		my_graph.SetEdgeDistance(1,2,1.5);
		cout <<"Edge Distance " << my_graph.GetEdgeDistance(1,2) << endl;
		my_graph.DeleteEdge(1,2);

		bool* node_neighbors;

		node_neighbors = my_graph.GetNeighbors(4);

		cout << "4";
		for(int i = 0; i < num_nodes; ++i)
		{
			if(node_neighbors[i] == true)
			{
				cout << " -> " << i ;
			}
		}
		cout << endl;

		my_graph.SetNodeValue(1,5.5);
		cout << "node 1 value " << my_graph.GetNodeValue(1) << endl;

		cout << "Graph Size " << my_graph.GraphSize() << endl;

		cout << "Is Edge Exist, should be no " << my_graph.IsEdgeExist(1,2) << endl;

		cout << "Number of Graph Edges " << my_graph.NumberOfGraphEdges()<< endl;
}


int main()
{
	TestGraph();


	return 0;
}
