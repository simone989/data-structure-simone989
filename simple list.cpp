/* This file, in C ++ implements a simple list with the various functions: insertion in the head, tail,order, and at a later point to a node passed as a parameter,
the cancellation, the search for a certain value and print. The entire program will be developed using templates.
Developed by Simone Di mauro.
*/ 

#include <iostream>
using namespace std;


template <class T>
struct Node{
	T value;
	Node<T>* next;
};


template <class T>
class SimpleList{
	public:
		SimpleList<T>(){head=NULL;}
		SimpleList<T>* insertionHead(T val);
		SimpleList<T>* insertionTail(T val);
		SimpleList<T>* insertionOrder(T val);
		SimpleList<T>* insertion(Node<T>* ptr,T val);
		Node<T>* search(T val);
		SimpleList<T>* cancellation(T val);
		void print();
		Node<T>* GetHead(){return head;}
	private:
		Node<T> * head;
};


template <class T>
SimpleList<T>* SimpleList<T>::insertionHead(T val){
	Node<T>* newNode=new Node<T>;
	newNode->value=val;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		return this;
	}else{
		newNode->next=head;
		head=newNode;
		return this;
	}
}

template <class T>
SimpleList<T>* SimpleList<T>::insertionTail(T val){ //You can not make the inclusion cascade with this method when you are on the first entry in the list.
	Node<T>* ptr=head;
	Node<T>* newNode=new Node<T>;
	newNode->value=val;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		return this;
	}else{
		while(ptr->next!=NULL) ptr=ptr->next;
		ptr->next=newNode;
		return this;
	}
}


template <class T>
Node<T>* SimpleList<T>::search(T val){
	Node<T>*ptr=head;
	if(ptr==NULL) return NULL;
	else{
		while(ptr!=NULL){
			if(ptr->value==val) return ptr;
		ptr=ptr->next;
		}

	}
	return NULL;
}

template <class T>
SimpleList<T>* SimpleList<T>::insertion(Node<T>* ptr, T val){
	if(ptr==NULL){
 
	return this;

	}
	else{
		Node<T>* newNode=new Node<T>;
		newNode->value=val;
		newNode->next=NULL;
		if(ptr->next==NULL){
			ptr->next=newNode;
			return this;
		}else{
			newNode->next=ptr->next;
			ptr->next=newNode;
			return this;
		}


	}

}

template <class T>
SimpleList<T>* SimpleList<T>::insertionOrder(T val){
	Node<T> *newNode=new Node<T>;
	newNode->value=val;
	newNode->next=NULL;
	Node<T> *ptr=head;
	if(ptr==NULL){
		head=newNode;
		return this;
	}
	if(head->value > val){
		newNode->next=head;
		head=newNode;
		return this;
	}
	Node<T> *prec=NULL;
	while(ptr->next!=NULL){
		prec=ptr;
		if(ptr->value > val){
			prec->next=newNode;
			newNode->next=ptr;
			return this;
		}
		ptr=ptr->next;
	}
	ptr->next=newNode;
}

template <class T>
void SimpleList<T>::print(){
	Node<T>* ptr=head;
	if(ptr==NULL) cout<<"List is emply";
	else{
		while(ptr!=NULL){
			cout<<ptr->value<<" ";
			ptr=ptr->next;
		}
	}
}

template <class T>
SimpleList<T>* SimpleList<T>::cancellation(T val){
	Node<T>*ptr=head;
	if(ptr==NULL) return this;
	if(head->value==val){
		if(ptr->next==NULL){
			head=NULL;
			delete ptr;
			return this;
		}
			head=ptr->next;
			delete ptr;
			return this;
		
	}else{
		Node<T>* prec=NULL;
		while(ptr->next!=NULL){
			
			if(ptr->next->value==val){
				prec=ptr->next;
				ptr->next=ptr->next->next;
				delete prec;
				return this;
			}
		ptr=ptr->next;
		}
	}
	

	


}

int main(){
	SimpleList<int> *x=new SimpleList<int>;

	return 0;
}
