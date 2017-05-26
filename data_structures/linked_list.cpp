#include <iostream>

class Node
{
	public:
		int data;
		Node* next;

		Node(int input_data);
};

class List
{
	Node* head;
	public:
		void add_to_beginning(int input_data);
		void add_to_end(int input_data);
		void print();
		
		Node* find_last();

		//void insert(Node* node);
		//bool search(Node* node);
		//void delete_node(Node* node);
		
		int compare(List* list);
		bool detect_a_loop();
		
		List operator+(List& list);

		List();
};

List List::operator+(List& list)
{
	List new_list;
	int a, b;
	Node* pointer_a = this->head;
	Node* pointer_b = list.head;
	//Node* pointer_c = new_list->head;
	while ((pointer_a != NULL) || (pointer_b != NULL))
	{
		a = 0;
		b = 0;
		if (pointer_a != NULL)
		{ 
			a = pointer_a->data; 
			pointer_a = pointer_a->next;
		}
		if (pointer_b != NULL)
		{ 
			b = pointer_b->data; 
			pointer_b = pointer_b->next;
		}
		new_list.add_to_end(a + b);
	}
	return new_list;
}

Node::Node(int input_data)
{
	data = input_data;
	Node* next = NULL;
}

List::List()
{
	head = NULL;
}

Node* List::find_last()
{
	if (head == NULL) { return NULL; }
	Node* pointer = head;
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
	}
	return pointer;	
}

void List::add_to_end(int input_data)
{
	Node* new_node = new Node(input_data);
	if (head == NULL) 
	{
		head = new_node;  
	}
	else
	{
		Node* last = this->find_last();
		last->next = new_node;
	}
}

void List::add_to_beginning(int input_data)
{
	Node* new_node = new Node(input_data);
	if (head == NULL) 
	{
		head = new_node;  
	}
	else
	{
		new_node->next = head;
		head = new_node;
	}
}

void List::print()
{
	if (head == NULL)
	{
		std::cout << "the list is empty" << std::endl;
	}
	Node* pointer = head;
	while(pointer != NULL)
	{
		std::cout << pointer->data << std::endl;
		pointer = pointer->next;
	}
}

int List::compare(List* list)
{
	Node* pointer_1 = head;
	Node* pointer_2 = list->head;
	while ((pointer_1 != NULL) && (pointer_2 != NULL))
	{
		if ((pointer_1->next == NULL) != (pointer_2->next == NULL))
		{
			return 1;
		}
		else if (pointer_1->data != pointer_2->data)
		{
			return 1;
		}
		else
		{
			pointer_1 = pointer_1->next;
			pointer_2 = pointer_2->next;
		}
	}
	return 0;
}


int main()
{
	List list;
	list.add_to_end(11);
	list.add_to_end(12);
	
	List list2;
	list2.add_to_end(11);

	List list_sum;
	list_sum = list + list2;
	
	list_sum.print();

}
















