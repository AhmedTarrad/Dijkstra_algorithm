/*
 * priority_queue.h
 *
 *  Created on: Nov 24, 2018
 *      Author: Ahmed
 */

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <limits>

using namespace std;

/* TODO: Adjust this macro */
#define UNDEFINED numeric_limits<int>::max()

class Queue_Element
{
public:
	Queue_Element(int id, float priority_value, Queue_Element* ptr):
		node_id(id), priority(priority_value), p_next_element(ptr){}
	int node_id;
	float priority;
	Queue_Element* p_next_element;

};

class Priority_Queue
{
public:
	Priority_Queue():head(0),cursor(0),prev_cursor(0),queue_size(0){}
	~Priority_Queue();
	void ChangeNodePriority(int node_id, float priority);
	void RemoveTopElementOfQueue();
	bool IsElementExist(int node_id);
	void InsertElement(int node_id, float priority);
	bool RemoveElement(int node_id);
	int QueueSize();
	int GetTopElementOfTheQueue();
	void QueuePrint();


private:
	Queue_Element* head;
	Queue_Element* cursor;
	Queue_Element* prev_cursor;
	int queue_size;


};

#endif /* PRIORITY_QUEUE_H_ */
