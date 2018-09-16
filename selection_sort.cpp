#include <iostream>
using namespace std;

// Given a list, returns a pointer to the smallest item.
// Returns nullptr if and only if head is nullptr.
Item* findMin(Item * head)
{
	Item* p = head;
	int min = p.value;

	if (p == NULL)
	{
		return NULL;
	}
	int min = head.value;

	for (int i = 0; i < size(); i++)
	{
		if (p.value <= min)
		{
			min = p.value;
		}
	}

	return min;

}

Item* LLSelectionSort(Item * head)
{
	for (int i = 0; i < size; i++)
	{
		Item* p = head;
		Item* temp = 0;

		for (int i = 0; i < size; i++)
		{
			temp = findMin(p);
			head = p->next;
			LLSelectionSort(head);
		}


	}
}