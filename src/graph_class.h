/*
 * graph_class.h
 *
 *  Created on: Nov 24, 2018
 *      Author: Ahmed
 */

#ifndef GRAPH_CLASS_H_
#define GRAPH_CLASS_H_

using namespace std;

class Graph
{
public:
	Graph(int num_nodes, float density = 0.19, float min_distance = 1, float max_distance = 10);
	void GraphPrint();
	bool IsGraphConnected();

	int GraphSize();
	int NumberOfGraphEdges();
	bool* GetNeighbors(int node_a);

	bool IsEdgeExist(int edge_start_node, int edge_end_node);
	void DeleteEdge(int edge_start_node, int edge_end_node);
	float GetEdgeDistance(int edge_start_node, int edge_end_node);
	void SetEdgeDistance(int edge_start_node, int edge_end_node, float edge_distance);

	float GetNodeValue(int node_a);
	void SetNodeValue(int node_a, float node_value);


private:
	float** p_graph;
	float* p_nodes_value;
	int graph_size;
	int graph_edges_number;
};

#endif /* GRAPH_CLASS_H_ */
