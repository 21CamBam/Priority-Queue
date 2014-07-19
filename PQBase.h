// The following code is the base code given to me by my professor to run my program
// Please note that it is not mine
// DO NOT MODIFY THIS FILE

#ifndef PQBASEH
#define PQBASEH

// Abstract base class for a priority queue
template <typename T>
class PQBase
{
public:
	virtual ~PQBase() { }

	// Adds an item to the priority queue. Duplicates ARE allowed, so the only time 
	// addition should fail is if memory allocation fails. Given the simple nature 
	// and low memory usage of this assignment, this should never happen.
	virtual void Add(const T& toCopyAndAdd) = 0;

	virtual bool IsEmpty() const = 0;

	// Removes the maximum item from the priority queue. Returns false and makes 
	// no modification to 'outputItem' if the queue is empty. Otherwise the 
	// output item is set to the maximum item currently in the queue, that maximum 
	// item is removed from the queue, and true is returned.
	virtual bool RemoveMax(T& outputItem) = 0;
};
#endif
