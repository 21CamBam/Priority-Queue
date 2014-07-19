#ifndef PQLLH
#define PQLLH

#include "PQBase.h"

using namespace std;

template <typename T>
class PQ_LinkedList : public PQBase <T>
{
private:
	struct Node
	{
	public:
		T *value;
		Node *next;
		Node *previous;

		Node()
		{
			value = NULL;
			next = nullptr;
			previous = nullptr;
		}

		Node(T *new_val)
		{
			value = new_val;
			next = nullptr;
			previous = nullptr;
		}

	};


	T* GetMin()
	{
		Node *temp = m_front;
		while (temp->next)
		{
			temp = temp->next;
		}
		return temp->value;
	}

	T* Front()
	{
		return m_front;
	}

	Node *m_front;
	// Implement this class - maintain a sorted linked-list internally where 
	// the list is always sorted in descending order and therefore the 
	// max is always accessible and removable in constant time.
public:
	PQ_LinkedList()
	{
		m_front = nullptr;
	}

	~PQ_LinkedList()
	{
		delete m_front;
	}


	// Adds an item to the priority queue. Duplicates ARE allowed, so the only time 
	// addition should fail is if memory allocation fails. Given the simple nature 
	// and low memory usage of this assignment, this should never happen.
	void Add(const T& toCopyAndAdd)
	{
		T* obj = new T(toCopyAndAdd);
		Node *new_node = new Node(obj);
		Node *temp = m_front;

		if (m_front == nullptr) // New front
		{
			m_front = new Node(obj);
			return;
		}

		while (temp != nullptr) // while we aren't at the end of the PQ
		{
			if (*obj > *(temp->value)) // If object is more than current node
			{
				if (temp == m_front) // if the current node is the front of the PQ
				{
					new_node->next = m_front;
					m_front->previous = new_node;
					m_front = new_node;
					break;
				}
				else // if the current node is NOT the front of the PQ
				{
					temp->previous->next = new_node;
					new_node->previous = temp->previous;
					temp->previous = new_node;
					new_node->next = temp;
					break;
				}
			}
			else // If object is less than current node
			{
				if (temp->next == nullptr) // if the current node is the front of the PQ
				{
					temp->next = new_node;
					new_node->previous = temp;
					break;
				}
				else // if the current node is NOT the front of the PQ
				{
					temp = temp->next;
					continue;
				}
			}
		}
	}

	bool IsEmpty() const
	{
		if (m_front == nullptr) // New front
		{
			return true;
		}
		return false;
	}

	// Removes the maximum item from the priority queue. Returns false and makes 
	// no modification to 'outputItem' if the queue is empty. Otherwise the 
	// output item is set to the maximum item currently in the queue, that maximum 
	// item is removed from the queue, and true is returned.
	bool RemoveMax(T& outputItem)
	{
		Node *temp = m_front->next;
		if (m_front == nullptr)
		{
			return false;
		}
		if (m_front->next == nullptr)
		{
			outputItem = *(m_front->value);
			m_front = nullptr;

			return true;
		}
		outputItem = *(m_front->value);
		temp->previous = nullptr;
		delete m_front;
		m_front = temp;

		return true;
	}
};
#endif
