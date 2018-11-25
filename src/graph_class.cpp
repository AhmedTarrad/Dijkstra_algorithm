/*
 * graph_class.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Ahmed
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

#include "graph_class.h"

using namespace std;



static float random_probability(void)
{
	float prob;

	prob =  static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	return prob;
}

static float random_distance(float min_distance, float max_distance)
{
	float distance;
	float prob;

	prob =  static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	distance = prob * (max_distance - min_distance) + min_distance;

	return distance;
}


Graph::Graph(int num_nodes, float density, float min_distance, float max_distance):graph_size(num_nodes),graph_edges_number(0)
{
	srand(time(0));

	/* Create a 2D array to store the generated graph,
	 * It's a dynamic memory allocated with the size of the graph
	 * For non edge --> distance will be zero
	 * For an existing edge --> distance (value stored in the 2D array) is randomly selected from the range */
	p_graph = new float*[num_nodes];

	for(int i = 0; i < num_nodes; ++i)
	{
		p_graph[i] = new float[num_nodes];
	}

	/* Init the graph edges randomly */
	if( ( (min_distance + numeric_limits<float>::epsilon()) > 0.0f ) &&
		( max_distance < numeric_limits<float>::max() ))
	{
		for(int i = 0; i < num_nodes; ++i)
		{
			for(int j = i; j < num_nodes; ++j)
			{
				if(i == j)
				{
					p_graph[i][j] = 0.0f;
				}
				else
				{
					/* TODO: Improve this checker to handle the return 1 probability by using the machine epsilon */
					p_graph[i][j] = p_graph[j][i] = ( static_cast <int> (random_probability() < density) )
															* random_distance(min_distance, max_distance);

					if(p_graph[i][j] > 0.0f)
					{
						graph_edges_number++;
					}
				}
			}
		}
	}
	else
	{
		/* TODO: write an assert for distance range out of the float min and max or negative distance */
	}


	p_nodes_data = new Node_Data[num_nodes];
	for(int i = 0; i < num_nodes; ++i)
	{
		p_nodes_data[i].node_value = numeric_limits<float>::infinity();
		p_nodes_data[i].parent = UNDEFINED;
	}

}

void Graph::GraphPrint()
{
	cout<<"Graph size is " << graph_size <<endl;
	cout<<"Graph edges number is " << graph_edges_number <<endl;

	for(int i = 0; i < graph_size; ++i)
	{
		for(int j = 0; j < graph_size; ++j)
		{
			cout << p_graph[i][j]<< "\t";
		}
		cout << endl;
	}
}

bool Graph::IsGraphConnected()
{
	int old_size = 0, c_size = 0;
	bool is_connected = false;

	bool* close_set = new bool[graph_size];
	bool* open_set = new bool[graph_size];

	for(int i = 0; i < graph_size; ++i)
	{
		close_set[i] = open_set[i] = false;
	}

	open_set[0] = true;

	while(c_size < graph_size)
	{
		old_size = c_size;
		for(int i = 0; i < graph_size; ++i)
		{
			if(open_set[i] && (close_set[i] == false))
			{
				close_set[i] = true;
				c_size++;

				for(int j = 0; j < graph_size; ++j)
				{
					open_set[j] = open_set[j] || (static_cast <bool> (p_graph[i][j]));
				}
			}
		}

		if(c_size == graph_size)
		{
			is_connected = true;
			break;
		}
		if(old_size == c_size)
		{
			is_connected = false;
			break;
		}

	}

	return is_connected;
}


int Graph::GraphSize()
{
	return graph_size;
}

int Graph::NumberOfGraphEdges()
{
	return graph_edges_number;
}

bool* Graph::GetNeighbors(int node_a)
{
	bool* node_neighbors = new bool[graph_size];

	for(int i = 0; i < graph_size; ++i)
	{
		node_neighbors[i] = (static_cast <bool> (p_graph[node_a][i]));
	}

	return node_neighbors;
}

bool Graph::IsEdgeExist(int edge_start_node, int edge_end_node)
{
	return (static_cast <bool> (p_graph[edge_start_node][edge_end_node]));
}

void Graph::DeleteEdge(int edge_start_node, int edge_end_node)
{
	p_graph[edge_start_node][edge_end_node] = 0.0f;
}

float Graph::GetEdgeDistance(int edge_start_node, int edge_end_node)
{
	return (p_graph[edge_start_node][edge_end_node]);
}

void Graph::SetEdgeDistance(int edge_start_node, int edge_end_node, float edge_distance)
{
	p_graph[edge_start_node][edge_end_node] = edge_distance;
}

float Graph::GetNodeValue(int node_a)
{
	return p_nodes_data[node_a].node_value;
}

void Graph::SetNodeValue(int node_a, float node_value)
{
	p_nodes_data[node_a].node_value = node_value;
}

