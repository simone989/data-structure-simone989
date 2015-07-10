binary search tree, with methods:
-insert, add the item.
-delete, delete the item.
-search, returns 1 if the value exists, 0 if not.
-postorder, is a printout in ways postorder.
-print level, printing all the values in the tree at that level.
-naturalfill, it substitutes the values in the tree with the values in another data structure without changing the correct order of values


#include <iostream>
using namespace std;

template <class T>
struct Nodo{
	T valore;
	Nodo<T> *left;
	Nodo<T> *right;
	Nodo<T> *padre;
	int livello;
};

template <class T>
class BST{
	public:
		virtual BST<T>* insert(T *x) =0;
		//virtual BST<T>* delet(T *x) =0;
		virtual int search(T *x) =0;
		//virtual void naturalFill(T *x) =0;
		virtual void postorderPrint()=0;
		virtual void printLevel(int l)=0;
};

template <class T>
class MyBST :public BST<T>{
	public:
		MyBST<T>(){radice=NULL;}
		BST<T>* insert(T *x);
		BST<T>* delet(T *x);
		Nodo<T> * trapianta(Nodo<T> *x,Nodo<T> *y);
		int search(T *x);
		Nodo<T> *cerca(T *x);
		void postorderPrint();
		void postorderPrintRico(Nodo<T> *ptr);
		void printLevel(int l);
		void printLevelRico(Nodo<T> *ptr, int l);
		Nodo<T> *successivo(Nodo<T> *ptr);
		Nodo<T> *min(Nodo<T> *ptr);
		void naturalFill(T *v);
		Nodo<T> *GetRadice(){return radice;}


	private:
		Nodo<T>* radice;
};


template <class T>
BST<T>* MyBST<T>::insert(T *x){
	Nodo<T> *nuovo=new Nodo<T>;
	nuovo->left=NULL;
	nuovo->right=NULL;
	nuovo->padre=NULL;
	nuovo->valore=*x;
	Nodo<T> *ptr=radice;
	if(ptr==NULL){
		radice=nuovo;
		nuovo->livello=0;
		return this;
	}
	Nodo<T> *prec=NULL;
	while(ptr!=NULL){
		prec=ptr;
		if(ptr->valore > nuovo->valore) ptr=ptr->left;
			else ptr=ptr->right;
	}

	nuovo->padre=prec;
	nuovo->livello=prec->livello+1;
	if(prec->valore > nuovo->valore) prec->left=nuovo;
		else prec->right=nuovo;
}

template <class T>
void MyBST<T>::postorderPrintRico(Nodo<T> *ptr){
	if(ptr!=NULL){  //FATTA AL MOMENTO INORDER PER MIA COMODITA'
		postorderPrintRico(ptr->left);
	
		cout<<ptr->valore<<" ";
		postorderPrintRico(ptr->right);
	}
}

template <class T>
void MyBST<T>::postorderPrint(){
	Nodo<T> *ptr=radice;
	postorderPrintRico(ptr);
	cout<<endl;
}

template <class T>
int MyBST<T>::search(T *x){
	Nodo<T> *ptr=radice;
	while(ptr!=NULL){
		if(ptr->valore==*x) return 1;
		if(ptr->valore > *x) ptr=ptr->left;
			else ptr=ptr->right;
	}
	cout<<"Value not found"<<endl;
	return 0;
}

template <class T>
void MyBST<T>::printLevelRico(Nodo<T> *ptr, int l){
	if(ptr!=NULL){
		printLevelRico(ptr->left,l);
		printLevelRico(ptr->right,l);
		if(ptr->livello==l)cout<<ptr->valore<<" ";	
	}
}

template <class T>
Nodo<T>* MyBST<T>::cerca(T *x){
	Nodo<T> *ptr=radice;
	while(ptr!=NULL){
		if(ptr->valore==*x) return ptr;
		if(ptr->valore > *x) ptr=ptr->left;
			else ptr=ptr->right;
	}
	return NULL;
} 

template <class T>
void MyBST<T>::printLevel(int l){
	Nodo<T> *ptr=radice;
	printLevelRico(ptr, l);
}

template <class T>
Nodo<T>* MyBST<T>::min(Nodo<T> *ptr){
	Nodo<T> *prec=NULL;
	while(ptr!=NULL){
		prec=ptr;
	ptr=ptr->left;
	}
	return prec;

}

template <class T>
Nodo<T>* MyBST<T>::successivo(Nodo<T> *ptr){
	if(ptr->right!=NULL) return min(ptr->right);
	else{
		Nodo<T> *ptr1=ptr->padre;
		while((ptr1!=NULL) && (ptr1->valore < ptr->valore)) ptr1=ptr1->padre;
		if(ptr1==NULL) return NULL;
		else{
			return ptr1;
		}
	}
}

template <class T> 
void MyBST<T>::naturalFill(T *v){
	Nodo<T>*ptr=min(radice);
	for(int i=0; i<13 ; i++){
		if(ptr!=NULL) ptr->valore=*v+i;  //metodo per entrare direttamente dentro l'array2
	ptr=successivo(ptr);
	}
}

template <class T>
Nodo<T> *MyBST<T>::trapianta(Nodo<T> *x,Nodo<T> *y){
	if(x->padre==NULL) radice=y;
	else if(x==x->padre->left) x->padre->left=y;
	else x->padre->right=y;
	if(y!=NULL) y->padre=x->padre;
}

template <class T>
BST<T>* MyBST<T>::delet(T *x){
	Nodo<T> *z=NULL;
	z=cerca(x);
	if(z==NULL){
		cout<<"Nessun elemento trovato: "<<endl;
		return this;
	}
	Nodo<T> *y=NULL;
	if(z->left==NULL) trapianta(z,z->right);
	else if(z->right==NULL) trapianta(z,z->left);
	else {
		y=min(z->right);
		if(y->padre!=z){
			trapianta(y,y->right);
			y->right=z->right;
			y->right->padre=y;
		}
	trapianta(z,y);
	y->left=z->left;
	y->left->padre=y;
	}

	
	delete z;
}
int main(){
	MyBST<int> *x=new MyBST<int>;
	int array[13]={23,4,6,8,12,21,5,9,7,3,16,2,24};
	int array2[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
	for(int i=0 ; i<13 ; i++) x->insert(&array[i]);
	x->postorderPrint();
	x->naturalFill(array2);
	x->postorderPrint();
	int u=1;
	x->delet(&u);
	x->postorderPrint();
return 0;
}
