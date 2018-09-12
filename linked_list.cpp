#include<bits/stdc++.h>
using namespace std;

//--------------------class LinkedList--------------------------------------------------
template<class E>class LinkedList;
template<class E>ostream & operator<<(ostream &,const LinkedList<E>);

template<class E>
class LinkedList{
		public:
			LinkedList(){								//default constructor
				head=NULL;							//to set head to NULL
				elements=0;
			}
			friend ostream& operator<< <E>(ostream&,const LinkedList<E> ll); 	//funtion to print LinkedList
			int size();								//return number of elements
			void addFirst(E*);							//add element at 1st location
			E removeFirst();							//remove element at 1st location

		private:		
			class Node{					//Single unit of LL-Node
						E* element;
						Node* next;
				public:
					Node(E* element,Node* next){
						this->element=element;
						this->next=next;	
					}
					void setElement(E* element){
						this->element=element;
					}
					E* getElement(){
						return element;
					}
					Node* getNextNode(){
						return next;
					}
					void setNextNode(Node * next){
						this->next=next;
					}
			};		
			Node* head;					//pointer to head of LinkedList
			int elements;
			
};

template<class E>
void LinkedList<E>::addFirst(E *n){				//function to insert data at 1st location
	Node *newNode=new Node(n,head);
	head=newNode;
	/*E *newNode=n;
	newNode->setNextNode(head);
	head=newNode;*/
	elements++;
}

template<class E>
E LinkedList<E>::removeFirst(){					//function to remove data at 1st location
	if(head!=NULL){
		Node * deletedNode=head;
		head=head->getNextNode();
		deletedNode->setNextNode(NULL);
		E removedNode=*deletedNode->getElement();
		deletedNode->setElement(NULL);
		delete deletedNode;
		elements--;
		return removedNode;
	}
	return E();
}

template<class E>
int LinkedList<E>::size(){						//returns size of linkedList
	return elements;
}

template<class E>
ostream& operator<<(ostream & out,const LinkedList<E> ll){		//funtion to print LinkedList
	if(ll.head==NULL){
		out<<"Empty Linked-List";
	}
	else{
		typename LinkedList<E>::Node*p=ll.head;
		out<<"{";
		while(p!=NULL){
			out<<"["<<*(p->getElement())<<"]";			
			if(p->getNextNode()!=NULL)
				out<<",\n";
			p=p->getNextNode();
		}
		out<<"}";
	}
}
//-------------------------------End Of Class----------------------------------------------

