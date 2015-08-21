/*In this file cpp you will implement a stack double linked, with the following methods: push, pop, searching and printing.
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
class Stack{
	public:
		Stack<T>(){head=NULL;}
		Stack<T>* push(T val);
		Node<T>* pop();
		Node<T>* search(T val);
		void print();
	private:
		Node<T>* head;
};

template <class T>
Stack<T>* Stack<T>::push(T val){
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
void Stack<T>::print(){
	Node<T>* ptr= head;
	if(head==NULL) return;
	while(ptr!=NULL){
		cout<<ptr->value<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

template <class T>
Node<T>* Stack<T>::pop(){
	Node<T>* ptr=head;
	Node<T>* ptr1=head;
	if(head==NULL) return NULL;
	if(head->next==NULL){
		head=NULL;
		
		return ptr1;
	}
	head->next->previous=NULL;
	head=head->next;
	
	return ptr1;
}


template <class T>
Node<T>* Stack<T>::search(T val){
	Node<T>* ptr= head;
	if(head==NULL) return NULL;
	while(ptr!=NULL){
		if(ptr->value==val) return ptr;
	ptr=ptr->next;
	}
	return NULL;



}

int main(){
	Stack<int> *x=new Stack<int>;
	x->push(5)->push(3)->push(4)->print();
	cout<<x->search(3)->value<<" ";
	return 0;	
}


