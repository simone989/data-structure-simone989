/*
In this end, it will be implemented a binary search tree, with these methods: Inserting, search, delete, successor, predecessor and printing. 
All the files will be developed using the paradigm of the template.
Developed by Simone Di Mauro.
*/

#include <iostream>
using namespace std;

template <class T>
struct Node{
	T value;
	Node<T>* left;
	Node<T>* right;
	Node<T>* dad;
	int level;
};


template <class T>
class Tree{
	public:
		Tree<T>(){root=NULL;}
		Tree<T>* insert(T val);
		Node<T>* search(T val);
		Tree<T>* delet(T val);
		Node<T>* min(Node<T>* ptr);
		Node<T>* max(Node<T>* ptr);
		Node<T>* successor(Node<T>* ptr);
		Node<T>* predecessor(Node<T>* ptr);
		void inorder(Node<T>* ptr);
		void print();
	private:
		Node<T>* root;

};


template <class T>
Tree<T>* Tree<T>::insert(T val){
	Node<T>* newNode= new Node<T>;
	newNode->value=val;
	newNode->left=NULL;
	newNode->right=NULL;
	newNode->dad=NULL;
	newNode->level=0;
	if(root==NULL){
		root=newNode;
		return this;
	}
	Node<T>*ptr=root;
	Node<T>* ptr1=NULL;
	while(ptr!=NULL){
		ptr1=ptr;
		if(ptr->value > val) ptr=ptr->left;
			else ptr=ptr->right;
	}

	newNode->dad=ptr1;
	if(ptr1->value > val) ptr1->left=newNode;
		else ptr1->right=newNode;

	return this;
}


template <class T>
void Tree<T>::inorder(Node<T>* ptr){
	if(ptr!=NULL){
		inorder(ptr->left); 
		cout<<ptr->value<<" ";
		inorder(ptr->right);
	}
}

template <class T>
Node<T>* Tree<T>::search(T val){
	Node<T>* ptr= root;
	if(root==NULL) return NULL;
	while(ptr!=NULL){
		if(ptr->value==val) return ptr;
		if(ptr->value > val) ptr=ptr->left;
			else ptr=ptr->right;
	}
	return NULL;
}

template <class T>
Node<T>* Tree<T>::min(Node<T>* ptr){
	if(ptr==NULL) return NULL;
	if(ptr->left==NULL) return ptr;
	while(ptr->left!=NULL)ptr=ptr->left;
	return ptr;
}

template <class T>
Node<T>* Tree<T>::max(Node<T>* ptr){
	if(ptr==NULL) return NULL;
	if(ptr->right==NULL) return ptr;
	while(ptr->right!=NULL)ptr=ptr->right;
	return ptr;
}

template <class T>
Node<T>* Tree<T>::successor(Node<T>* ptr){
	if(ptr==NULL) return NULL;
	if(ptr->right!=NULL) return max(ptr->right);
	else{
		Node<T> *ptr1=ptr->dad;
		while((ptr1!=NULL) && (ptr1->value < ptr->value)) ptr1=ptr1->dad;
		if(ptr1==NULL) return NULL;
		else{
			return ptr1;
		}
	}

}


template <class T>
Node<T>* Tree<T>::predecessor(Node<T>* ptr){
	if(ptr==NULL) return NULL;
	if(ptr->right!=NULL) return min(ptr->right);
	else{
		Node<T> *ptr1=ptr->dad;
		while((ptr1!=NULL) && (ptr1->value > ptr->value)) ptr1=ptr1->dad;
		if(ptr1==NULL) return NULL;
		else{
			return ptr1;
		}
	}
}


template <class T>
void Tree<T>::print(){
	Node<T> *ptr=root;
	inorder(ptr);
	cout<<endl;
}

int main(){
	Tree<int> *x= new Tree<int>;
	x->insert(5)->insert(3)->insert(9)->print();
	cout<<x->predecessor(x->search(5))->value<<" ";	

	return 0;
}