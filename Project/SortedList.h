#ifndef LISTS_H
#define LISTS_H

#include <new>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class SortedList {
	private:
		struct Node{
			T data;
                        T space;
                        string color;
			Node *prev;
			Node *next;
		};
		Node *head;
		Node *tail;
		int size;
		void memError(){
			cout << "ERROR:Cannot allocate memory.\n";
			exit(EXIT_FAILURE);
		}
		void subError(){
			cout << "ERROR: Subscript out of range.\n";
			exit(EXIT_FAILURE);
		 }
	public:
		SortedList();
		virtual ~SortedList();
		void push(T data, T space, string color);
		void pop();
		T at(int index);
		T operator[](int index);
		void display();
		bool find(T space);
};

template <class T>
SortedList<T>::SortedList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

template <class T>
SortedList<T>::~SortedList(){
	if (head) { //if head is set
		do {
			tail = head; //set head to tail
			head = head->next; //set the head to be the old head link
			delete tail; //delete tail
		} while (head);
	}
}

template <class T>
void SortedList<T>::push(T data, T space, string color){
	if(!head){
		try{
			Node *node = new Node;
			node->data = data;
                        node->space = space;
                        node->color = color;
			node->next = NULL;
			node->prev = NULL;
			head = node;
			tail = head;
			size++;
		} catch(bad_alloc){
			memError();
		}
	} else {
		Node *working = head;
		Node *node = new Node;
		node->data = data;
                node->space = space;
                node->color = color;
		node->next = NULL;
		node->prev = NULL;
		bool inserted = false;
		do{
			if(working->space > node->space) { //so put node in front
				node->prev = working->prev;
				node->next = working;
				
				if(working == head){
					head = node;
				} else {
					(working->prev)->next = node;
				}
				working->prev = node;
				inserted = true;
				break;
			} else if (working->next == NULL){ //then it is the biggest element add to rear
				node->prev = working;
				working->next = node;
				inserted = true;
				break;
			}
		} while((working = working->next));
		if(inserted) {
			size++;
		} else {
			cout << "Failed to insert element: " << space << endl;
		}
	}
}

template <class T>
void SortedList<T>::pop(){
	Node *current = head;
	do{
		if(current->next == NULL){
			break;
		}
		current = current->next;
	} while(true);
	tail = current;
	(current->prev)->next = NULL;
	delete tail;          
}

template <class T>
void SortedList<T>::display(){
	Node *current = head;
	do{
		cout << "Space " << current->space +1 << ": " << current->data << " <" << current->color << ">" << endl;
	} while((current = current->next));
	cout << endl;
}

template <class T>
bool SortedList<T>::find(T space){
	Node *current = head;
	do{
		if(current->data == space){
			return true;
		}
	} while((current = current->next));
	return false;
}

template <class T>
T SortedList<T>::at(int index){
	if(index < 0 || index < size){
		Node *temp = head;
		for(int i = 0; i < index; i++){
			temp = temp->next;
		}
		return temp->space;
	} else {
		subError();
	}
}

template <class T>
T SortedList<T>::operator [](int index) {
	return at(index);
}

#endif /* LISTS_H */