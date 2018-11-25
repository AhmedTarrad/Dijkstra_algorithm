/*
 * priority_queue.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Ahmed
 */

#include <iostream>
#include "priority_queue.h"


Priority_Queue::~Priority_Queue()
{
	while(head != 0)
	{
		cursor = head->p_next_element;
		delete head;
		head = cursor;
	}
}

bool Priority_Queue::IsElementExist(int node_id)
{
	bool is_exist = false;

	prev_cursor = 0;
	cursor = head;

	while(cursor != 0)
	{
		if(cursor->node_id == node_id)
		{
			is_exist = true;
			break;
		}
		else
		{
			prev_cursor = cursor;
			cursor = cursor->p_next_element;
		}
	}

	return is_exist;
}


void Priority_Queue::ChangeNodePriority(int node_id,float priority)
{
	bool is_node_exist = RemoveElement(node_id);

	if( is_node_exist == true)
	{
		InsertElement(node_id,priority);
	}
	else
	{
		/* Do nothing, the element you want to change doesn't exist */
		/*TODO: Add an assert here */
	}
}


void Priority_Queue::RemoveTopElementOfQueue()
{
	if(head != 0)
	{
		cursor = head->p_next_element;
		delete head;
		head = cursor;
		queue_size--;
	}
	else
	{
		/* nothing to do there is no elements in the queue */
	}
}


void Priority_Queue::InsertElement(int node_id, float priority)
{
	if( (head == 0) || (head->priority > priority) )
	{
		head = cursor = new Queue_Element(node_id,priority,head);
	}
	else
	{
		prev_cursor = head;
		cursor = head->p_next_element;

		while(cursor != 0)
		{
			if(cursor->priority < priority)
			{
				prev_cursor = cursor;
				cursor = cursor->p_next_element;
			}
			else
			{
				break;
			}
		}
		prev_cursor->p_next_element = new Queue_Element(node_id,priority,cursor);
		cursor = prev_cursor->p_next_element;

	}
	queue_size++;
}

bool Priority_Queue::RemoveElement(int node_id)
{
	bool is_node_exist = IsElementExist(node_id);

	if( is_node_exist == true)
	{
		if(cursor == head)
		{
			head = cursor->p_next_element;
		}
		else
		{
			prev_cursor->p_next_element = cursor->p_next_element;
		}
		queue_size--;
		delete cursor;

	}
	else
	{
		/* Do nothing, the element you want to change doesn't exist */
		/*TODO: Add an assert here */
	}
	return is_node_exist;
}


int Priority_Queue::QueueSize()
{
	return queue_size;
}

int Priority_Queue::GetTopElementOfTheQueue()
{
	int node_id = UNDEFINED;
	if(head != 0)
	{
		node_id = head->node_id;
	}
	return node_id;
}

void Priority_Queue::QueuePrint()
{
	cursor = head;

	cout << endl <<"[ head ]";
	while(cursor != 0)
	{
		cout << " -> [" << cursor->node_id << "," << cursor->priority << "]" ;
		cursor = cursor->p_next_element;
	}
	cout << " -> [ NULL ]" << endl;
}



