// The following code is the base code given to me by my professor to run my program
// Please note that it is not mine
// DO NOT MODIFY THIS FILE

// Author:
//    Evan Olds
// Creation Date:
//    July 13, 2014
//
// HW7 - "Heaps and Priority Queues" - Solution
// Ctp S 223 - Advanced Data Structures

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "PQ_Heap.h"
#include "PQ_LinkedList.h"

using namespace std;

// Word list from Wikipedia
// Source: http://en.wikipedia.org/wiki/Most_common_words_in_English
string g_words[100] = {
	"the", "be", "to", "of", "and", "a", "in", "that", "have", "I", "it", "for", "not", "on", "with",
	"he", "as", "you", "do", "at", "this", "but", "his", "by", "from", "they", "we", "say", "her", "she",
	"or", "an", "will", "my", "one", "all", "would", "there", "their", "what", "so", "up", "out", "if",
	"about", "who", "get", "which", "go", "me", "when", "make", "can", "like", "time", "no", "just",
	"him", "know", "take", "people", "into", "year", "your", "good", "some", "could", "them", "see",
	"other", "than", "then", "now", "look", "only", "come", "its", "over", "think", "also", "back",
	"after", "use", "two", "how", "our", "work", "first", "well", "way", "even", "new", "want",
	"because", "any", "these", "give", "day", "most", "us" };

template <typename T>
bool Verify(PQ_Heap<T>& heap, PQ_LinkedList<T>& linkedList, int& numMatched,
	const string& indent = "  ")
{
	numMatched = 0;

	// Remove all items, one-by-one, making sure removed items are equal
	bool test1OK = true;
	numMatched = 0;
	while (true)
	{
		// If the queues are empty then we must stop
		if (heap.IsEmpty())
		{
			if (!linkedList.IsEmpty())
			{
				cout << indent << "TEST FAILED: Heap is empty but linked-list is not" << endl;
				cout << indent << "Stopping test" << endl;
				return false;
			}
			break;
		}
		else if (linkedList.IsEmpty())
		{
			cout << indent << "TEST FAILED: Linked-list is empty but heap is not" << endl;
			cout << indent << "Stopping test" << endl;
			return false;
		}

		// Otherwise remove max items from both
		T max1, max2;
		if (!heap.RemoveMax(max1) || !linkedList.RemoveMax(max2))
		{
			cout << indent << "TEST FAILED: Removal of maximum item failed" << endl;
			cout << indent << "Stopping test" << endl;
			return false;
		}

		// Make sure they are equal
		if (max1 != max2)
		{
			cout << indent << "TEST FAILED: Maximum items were NOT equal" << endl;
			cout << indent << "Stopping test" << endl;
			return false;
		}
		numMatched++;
	}

	return true;
}

int main(int argc, const char* argv[])
{
	// Seed the random number generator
	srand(time(NULL));

	// Test 1: Build a binary heap and linked-list PQ with random integers
	cout << "Test 1: Binary Heap vs. Linked-List for integers" << endl;
	PQ_Heap<int> intHeap(2);
	PQ_LinkedList<int> intLL;
	for (int i = 0; i < rand() % 501 + 500; i++)
	{
		int randomNumber = rand();
		intHeap.Add(randomNumber);
		intLL.Add(randomNumber);
	}
	int test1OKCount = 0;
	if (Verify(intHeap, intLL, test1OKCount))
	{
		cout << "SUCCESS: Test 1 passed for " << test1OKCount;
		cout << " integers!" << endl;
	}
	else
	{
		cout << "TEST 1 FAILED. Moving on to test 2." << endl;
	}

	// Test 2: Build a TERNARY heap and linked-list PQ with random strings
	cout << "Test 2: Ternary Heap vs. Linked-List for strings" << endl;
	PQ_Heap<string> strHeap(3);
	PQ_LinkedList<string> strLL;
	for (int i = 0; i < rand() % 501 + 500; i++)
	{
		string randomString = g_words[rand() % 100];
		strHeap.Add(randomString);
		strLL.Add(randomString);
	}
	int test2OKCount = 0;
	if (Verify(strHeap, strLL, test2OKCount))
	{
		cout << "SUCCESS: Test 2 passed for " << test2OKCount;
		cout << " strings!" << endl;
	}
	else
	{
		cout << "TEST 2 FAILED." << endl;
	}

	int num;
	cin >> num;
	cout << "Done" << endl;

	return 0;
}
