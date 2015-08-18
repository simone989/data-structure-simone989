/*In this file cpp you will implement a doubly linked list, with the following methods: insertion in the head, the tail, the next node passed as a parameter, inserting ordered, 
removing a node, searching and printing.
Everything will be implemented using the templates.
Developed by Simone Di Mauro.
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
class List{
	public:
		List<T>(){head=NULL;}
		List<T>* insertion_head(T val);
		List<T>* insertion_tail(T val);
		List<T>* insertion_order(T val);
		List<T>* insertion(Node<T>* ptr,T val);
		Node<T>* search(T val);
		List<T>* removing(T val);
		void print();
	private:
		Node<T>* head;
};

template <class T>
List<T>* List<T>::insertion_head(T val){
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
List<T>* List<T>::insertion_tail(T val){
	Node<T>* newNode= new Node<T>;
	newNode->value=val;
	newNode->previous=NULL;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		return this;
	}
	Node<T>* ptr=head;
	while(ptr->next!=NULL) ptr=ptr->next;
	ptr->next=newNode;
	newNode->previous=ptr;
	return this;
}

template <class T>
List<T>* List<T>::insertion_order(T val){
	Node<T>* newNode= new Node<T>;
	newNode->value=val;
	newNode->next=NULL;
	newNode->previous=NULL;
	if(head==NULL){
		head=newNode;
		return this;
	}
	if(head->value > val){
		newNode->next=head;
		head->previous=newNode;
		head=newNode;
		return this;
	}
	Node<T>* ptr=head;
	while(ptr->next!=NULL){
		if(ptr->next->value > val){
			newNode->next=ptr->next;
			ptr->next->previous=newNode;
			newNode->previous=ptr;
			ptr->next=newNode;
			return this;
		}
	ptr=ptr->next;
	}
	ptr->next=newNode;
	newNode->previous=ptr;
	return this;

}


template <class T>
Node<T>* List<T>::search(T val){
	Node<T>* ptr=head;
	if(ptr==NULL) return NULL;
	while(ptr!=NULL){
		if(ptr->value==val) return ptr;
	ptr=ptr->next;
	}
	return NULL;
}

template <class T>
List<T>* List<T>::insertion(Node<T>* ptr,T val){
	if(ptr==NULL) return this;
	else{
	Node<T>* newNode= new Node<T>;
	newNode->value=val;
	newNode->previous=ptr;
	newNode->next=ptr->next;
	ptr->next->previous=newNode;
	ptr->next=newNode;	
	return this;
	}
}


template <class T>
List<T>* List<T>::removing(T val){
	Node<T>* ptr= search(val);
	if(ptr==NULL) return this;
	else{
		if(ptr==head){
			head->next->previous=NULL;
			head=ptr->next;
			delete ptr;
			return this;
		}
		ptr->previous->next=ptr->next;
		ptr->next->previous=ptr->previous;
		delete ptr;
		return this;
	}


}

template <class T>
void List<T>::print(){
	Node<T>* ptr=head;
	if(ptr==NULL) return;
	while(ptr!=NULL){
		cout<<ptr->value<<" ";
	ptr=ptr->next;
	}
	cout<<endl;
}


int main(){
	List<int> *x=new List<int>;
	x->insertion_order(5)->insertion_order(3)->insertion_order(9)->insertion_order(6)->print();
//	x->insertion(x->search(3),6)->removing(5)->print();

	return 0;
}
