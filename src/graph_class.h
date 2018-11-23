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

private:
	float** graph_ptr;
	int graph_size;
};

#endif /* GRAPH_CLASS_H_ */
