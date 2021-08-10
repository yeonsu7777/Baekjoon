//2021.08.09
//백준 10866번: 덱(Deque)
#include <iostream>
using namespace std;

struct single_node
{
	int data;
	single_node* next;
	single_node* prev;
};

class deque
{
public:
	using node = single_node;
	using node_ptr = node*;

private:
	node_ptr head = NULL;
	node_ptr tail = NULL;

public:
	void push_front(int val)
	{
		//정수 X를 덱의 앞에 넣는다.

		auto new_node = new node{ val, NULL, NULL };
		if (head != NULL) //첫 노드가 아니라면
		{
			head->prev = new_node;
			new_node->next = head;
		}
		else
			tail = new_node;
		head = new_node;
	}
	void push_back(int val)
	{
		//정수 X를 덱의 뒤에 넣는다.

		auto new_node = new node{ val, NULL, NULL };
		if (tail != NULL)
		{
			tail->next = new_node;
			new_node->prev = tail;
		}
		else
			head = new_node;
		tail = new_node;
	}
	void pop_front()
	{
		//덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.
		//만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

		auto first = head;
		if (head)
		{

		}
	}
	void pop_back()
	{
		
	}
	void size()
	{

	}
	void empty()
	{

	}
	int front()
	{

	}
	void back()
	{

	}

	deque() = default;
};

int main()
{
	deque myDeque;

	myDeque.push_back(1);
	myDeque.push_back(2);
	myDeque.push_back(3);
	myDeque.push_back(4);
	myDeque.push_back(5);
	myDeque.push_back(6);
}