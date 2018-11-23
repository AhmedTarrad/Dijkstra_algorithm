/*
 * graph_class.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Ahmed
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

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


Graph::Graph(int num_nodes, float density, float min_distance, float max_distance):graph_size(num_nodes)
{
	srand(time(0));

	/* Create a 2D array to store the generated graph,
	 * It's a dynamic memory allocated with the size of the graph
	 * For non edge --> distance will be zero
	 * For an existing edge --> distance (value stored in the 2D array) is randomly selected from the range */
	graph_ptr = new float*[num_nodes];
	for(int i = 0; i < num_nodes; ++i)
	{
		graph_ptr[i] = new float[num_nodes];
	}

	/* Init the graph edges randomly */
	for(int i = 0; i < num_nodes; ++i)
	{
		for(int j = i; j < num_nodes; ++j)
		{
			if(i == j)
			{
				graph_ptr[i][j] = 0.0f;
			}
			else
			{
				/* TODO: Improve this checker to handle the return 1 probability by using the machine epsilon */
				graph_ptr[i][j] = graph_ptr[j][i] = ( static_cast <int> (random_probability() < density) )
														* random_distance(min_distance, max_distance);
			}
		}
	}

}

void Graph::GraphPrint()
{
	cout<<"my random graph size is " << graph_size <<endl;

	for(int i = 0; i < graph_size; ++i)
	{
		for(int j = 0; j < graph_size; ++j)
		{
			cout << graph_ptr[i][j]<< "\t";
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
					open_set[j] = open_set[j] || (static_cast <bool> (graph_ptr[i][j]));
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
