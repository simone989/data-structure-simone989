/*In this file cpp you will implement a Queue double linked, with the following methods: enqueue, dequeue, searching and printing.
Everything will be implemented using the templates.
Developed by Simone Di Mauro.
LIFO
*/

#include <iostream>

using namespace std;

template <class T>
struct Node{
	T value;
	Node<T>* previous;
	Node<T>* next;
};

template <class T>
class Queue{
	public:
		Queue<T>(){head=NULL;}
		Queue<T>* enqueue(T val);
		Node<T>* dequeue();
		Node<T>* search(T val);
		void print();
	private:
		Node<T>* head;
};

template <class T>
Queue<T>* Queue<T>::enqueue(T val){
	Node<T>* newNode= new Node<T>;
	newNode->value=val;
	newNode->previous=NULL;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		return this;
	}
	newNode->next=head;
	head->previous=newNode;
	head=newNode;
	return this;
}

template <class T>
void Queue<T>::print(){
	Node<T>* ptr= head;
	if(head==NULL) return;
	while(ptr!=NULL){
		cout<<ptr->value<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

template <class T>
Node<T>* Queue<T>::dequeue(){
	Node<T>* ptr=head;

	if(head==NULL) return NULL;
	while(ptr->next!=NULL)ptr=ptr->next;
	if(ptr==head){
		head=NULL;
		return ptr;
	}
	ptr->previous->next=NULL;
	
	return ptr;
}


template <class T>
Node<T>* Queue<T>::search(T val){
	Node<T>* ptr= head;
	if(head==NULL) return NULL;
	while(ptr!=NULL){
		if(ptr->value==val) return ptr;
	ptr=ptr->next;
	}
	return NULL;



}

int main(){
	Queue<int> *x=new Queue<int>;
	x->enqueue(5)->enqueue(3)->enqueue(4)->print();
	x->dequeue();

	x->print();
	return 0;	
}


