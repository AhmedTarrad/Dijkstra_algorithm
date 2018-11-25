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
#include "priority_queue.h"


void TestGraph()
{
	/*TODO: This test case is non autonomous, the success or failure decision is known by expert eye
	 * Instead, test case should print pass or fail based on the ground truth for each scenario tested */
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

	cout << "node 1 value " << my_graph.GetNodeValue(1) << endl;

	my_graph.SetNodeValue(1,5.5);
	cout << "node 1 value " << my_graph.GetNodeValue(1) << endl;

	cout << "Graph Size " << my_graph.GraphSize() << endl;

	cout << "Is Edge Exist, should be no " << my_graph.IsEdgeExist(1,2) << endl;

	cout << "Number of Graph Edges " << my_graph.NumberOfGraphEdges()<< endl;

	cout << UNDEFINED << endl;
}

void TestPriorityQueue()
{
	/*TODO: This test case is non autonomous, the success or failure decision is known by expert eye
	 * Instead, test case should print pass or fail based on the ground truth for each scenario tested */
	Priority_Queue my_queue;

	cout << "**************** Priority Queue Class Test ******************" << endl;

	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize() <<endl;

	my_queue.InsertElement(1,4);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.InsertElement(2,3);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.InsertElement(3,9);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.InsertElement(4,6);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.InsertElement(5,2);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.ChangeNodePriority(1,10);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.ChangeNodePriority(5,3);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.ChangeNodePriority(1,10);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.ChangeNodePriority(1,12);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	my_queue.ChangeNodePriority(1,8);
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

	cout << "Top element of the Q = " << my_queue.GetTopElementOfTheQueue() << endl;

	my_queue.RemoveTopElementOfQueue();
	my_queue.QueuePrint();
	cout << "queue size = " << my_queue.QueueSize()<<endl;

}

int main()
{

	TestGraph();
	TestPriorityQueue();

	return 0;
}
