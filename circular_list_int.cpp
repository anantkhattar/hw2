#include <iostream>
using namespace std;

	// Destructor. Should delete all data allocated by the list. 
	CircularListInt::~CircularListInt()
	{
		Item* p = head;
		Item* temp = NULL;

		while(temp->next != head)
		{
			p = p->next;
			delete(temp);
		}
		delete p;
		head = NULL;
	}

	// Gets item at an index.
	// If an index is passed that is larger then the number of items in the list, it should "wrap around" back to the first element.
	// If there are no elements in the list, returns 0.
	int CircularListInt::get(size_t index) const
	{
    int length = size();
    index = index%length;
		Item* p = head;

		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}

		return p.value;
	}

	// get length of list.
	size_t CircularListInt::size(Item* head)
	{
		if (head == NULL)
		{
			return 0;
		}

		Item* p = head;
		int len = 0;

		while (p != head)
		{
			len++;
			p = p->next;
		}
		return len;

	}

	// returns true iff the list is empty.
	bool CircularListInt::empty(Item* head) const
	{
		Item* p = head;

		if (p == NULL) 
		{	
			return true;
		}
		
		return false;

	}

	// Inserts (a copy of) the given item at the end of list.
	void CircularListInt::push_back(int value)
	{
		Item n = new Item(value);

		if (this->next==NULL)
		{
			head=n;
			head->next = head;
			head->prev = NULL;

		}

		else 
		{
			Item* p = head;

			while (p->next != head)
			{
				p = p->next;	
	
			}

			n->next = head;
			n->prev = p;
			p->next = n;
			head->prev = n;

		}
	}

	// Sets the item at the given index to have the given value.
	// If an index is passed that is >= the number of items in the list, it should "wrap around" back to the first element.
	void CircularListInt::set(size_t index, int value)
	{
    int length =this->size();
    index = index%length;
		Item n = new Item(value);
		Item* p = head;
		Item* temp = NULL;

		for(int i = 0; i < index; i++)
		{
			p = p->next;

		}

		temp->next = p->next;
		p->next = n;
		n->prev = p;
		n->next = temp->next;

	}

	// Removes the item at the given index from the list.
	// List elements after the removed element are pulled forward, so their indicies decrease by one.
	// If an index is passed that is larger then the number of items in the list, it should "wrap around" back to the first element.
	void CircularListInt::remove(size_t index)
	{
		if (empty)
		{
			break;
		}

		else
		{
			Item*p = head;
			Item* temp = NULL;

			for (int i = 0; i < index; i++)
			{
				p = p->next;
			}
		}		
	}

int main()
{

}