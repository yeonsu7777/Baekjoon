//2021.08.09
//���� 10866��: ��(Deque)
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
		//���� X�� ���� �տ� �ִ´�.

		auto new_node = new node{ val, NULL, NULL };
		if (head != NULL) //ù ��尡 �ƴ϶��
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
		//���� X�� ���� �ڿ� �ִ´�.

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
		//���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�.
		//����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

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