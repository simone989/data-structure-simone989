/*In this file cpp you will implement a circular list, with the following methods: insertion in the head, the tail, the next node passed as a parameter, inserting ordered, 
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
		Node<T>* GetHead(){return head;}
	private:
		Node<T>* head;
};


template <class T>
List<T>* List<T>::insertion_head(T val){
	Node<T>* newNode= new Node<T>;
	newNode->value=val;
	newNode->next=NULL;
	newNode->previous=NULL;
	if(head==NULL){
		head=newNode;
		head->previous=head;
		head->next=head;
		return this;
	}
	if((head->next==head)&&(head->previous==head)){
		newNode->next=head;
		newNode->previous=head->previous;
		head->previous=newNode;
		head->next=newNode;
		head=newNode;
		return this;
	}
	Node<T>* ptr1= head;
	while(ptr1->next!=head) ptr1=ptr1->next;
	newNode->next=head;
	newNode->previous=head->previous;
	ptr1->next=newNode;
	head->previous=newNode;
	head=newNode;
	return this;	
}

template <class T>
List<T>* List<T>::insertion_tail(T val){
	Node<T>* newNode=new Node<T>;
	newNode->value=val;
	newNode->previous=NULL;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		head->previous=head;
		head->next=head;
		return this;
	}
	newNode->next=head;
	newNode->previous=head->previous;
	head->previous->next=newNode;
	head->previous=newNode;
	return this;
}

template <class T>
List<T>* List<T>::insertion_order(T val){
	Node<T>* ptr=head;
	Node<T>* newNode= new Node<T>;
	newNode->value=val;
	newNode->previous=NULL;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		head->previous=head;
		head->next=head;
		return this;
	}
	if((head->next==head)&&(head->previous==head)){
		if(head->value > val){
		newNode->next=head;
		newNode->previous=head->previous;
		head->previous=newNode;
		head->next=newNode;
		head=newNode;
		return this;
		}else{
			newNode->previous=head;
			newNode->next=head;
			head->next=newNode;
			head->previous=newNode;
			return this;
		}
	}
	if(head->value > val){
		insertion_head(val);
		return this;
	}
	ptr=ptr->next;
	while(ptr!=head){
		if(ptr->value > val){
		insertion(ptr->previous,val);
		return this;
	}
	ptr=ptr->next;
	}
	insertion_tail(val);
	return this;

}

template <class T>
Node<T>* List<T>::search(T val){
	if(head==NULL) return NULL;
	if(head->value==val) return head;
	Node<T>* ptr= head->next;
	while(ptr!=head){
		if(ptr->value==val) return ptr;
	ptr=ptr->next;
	}
	return NULL;
}

template <class T>
List<T>* List<T>::insertion(Node<T>* ptr,T val){
	if(ptr==NULL) return this;
	if(head==NULL) return this;
	Node<T>* newNode= new Node<T>;
	newNode->value=val;
	newNode->previous=ptr;
	newNode->next=ptr->next;
	ptr->next->previous=newNode;
	ptr->next=newNode;
	return this;	
}

template <class T>
List<T>* List<T>::removing(T val){
	Node<T>* ptr= search(val);
	if(ptr==NULL) return this;
	if(head==NULL) return this;
	if(ptr==head){
		ptr->next->previous=head->previous;
		head->previous->next=ptr->next;
		head=ptr->next;
		delete ptr;
		return this;

	}
	ptr->previous->next=ptr->next;
	ptr->next->previous=ptr->previous;
	delete ptr;
	return this;
}


template <class T>
void List<T>::print(){
	Node<T>* ptr=head;
	if(head==NULL) return;
	cout<<ptr->value<<" ";
	ptr=ptr->next;
	while(ptr!=head){
		cout<<ptr->value<<" ";
	ptr=ptr->next;
	}
	cout<<endl;



}



int main(){
	List<int> *x= new List<int>;
	x->insertion_order(3)->insertion_order(5)->insertion_order(9)->insertion_order(45)->print();
	x->removing(3)->print();
	//cout<<x->search(3)->value<<" ";

	return 0;
}
