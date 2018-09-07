#include<bits/stdc++.h>
using namespace std;
//-----------------------class Node--------------------------------------------------------
class MyNode{
		int data;
		MyNode* next;
	public:
		MyNode(){}			//Empty Constructor
		MyNode(int data){			//Constructor with parameter
			this->data=data;
			next=NULL;		
		}
		void setData(int data);
		int getData();
		void setNextNode(MyNode*);
		MyNode* getNextNode();
};

void MyNode::setData(int data){			//data setter function
	this->data=data;
}
int MyNode::getData(){				//data getter function
	return data;
}
void MyNode::setNextNode(MyNode *add){		//next-pointer setter function
	next=add;
}
MyNode* MyNode::getNextNode(){			//next-pointer getter function
	return next;
}
//--------------------------------------End of Class------------------------------------------
//--------------------class LinkedList--------------------------------------------------
template<class Node>class LinkedList;
template<class Node>ostream & operator<<(ostream &,const LinkedList<Node>);
template<class Node>
class LinkedList{
		Node* head;			//pointer to head of LinkedList
		int elements;
	public:
		LinkedList(){			//default constructor
			head=NULL;		//to set head to NULL
			elements=0;
		}
		//void addFirst(int data);	//function to insert data at 1st location
		void addFirst(Node*);
		friend ostream& operator<< <Node>(ostream&,const LinkedList<Node> ll); 	//funtion to print LinkedList
		int size();
		Node removeFirst();		//function to remove data at 1st location
};
template<class Node>
void LinkedList<Node>::addFirst(Node *n){		//function to insert data at 1st location
	Node *newNode=n;
	newNode->setNextNode(head);
	head=newNode;
	elements++;
}
template<class Node>
Node LinkedList<Node>::removeFirst(){			//function to remove data at 1st location
	if(head!=NULL){
		Node * deletedNode=head;
		head=head->getNextNode();
		deletedNode->setNextNode(NULL);
		Node removedNode=*deletedNode;
		delete deletedNode;
		elements--;
		return removedNode;
	}
	return NULL;
}
template<class Node>
int LinkedList<Node>::size(){				//returns size of linkedList
	return elements;
}
/*void LinkedList::addFirst(int data){		//function to insert data at 1st location
	Node *newNode=new Node(data);
	newNode->setNextNode(head);
	head=newNode;
	elements++;
}*/
template<class Node>
ostream& operator<<(ostream & out,const LinkedList<Node> ll){		//funtion to print LinkedList
	if(ll.head==NULL){
		out<<"Empty Linked-List";
	}
	else{
		Node *p=ll.head;
		out<<"[";
		while(p!=NULL){
			out<<p->getData();			//revisit this line
			if(p->getNextNode()!=NULL)
				out<<", ";
			p=p->getNextNode();
		}
		out<<"]";
	}
}
//-------------------------------End Of Class----------------------------------------------
int main(){
	LinkedList<MyNode> ll;
	MyNode *n=new MyNode();
	//for(int i=0;i<4;i++){
		(n)->setData(45);
		ll.addFirst(n);
	MyNode *n2=new MyNode();
		n2->setData(34);
		ll.addFirst(n2);
	//}
	/*ll.addFirst(45);
	ll.addFirst(98);
	ll.addFirst(56);
	ll.addFirst(67);*/
	cout<<ll<<endl;
	cout<<"Size:"<<ll.size()<<endl;
	int i=0;while(i<ll.size()){
		MyNode newNode=ll.removeFirst();
		cout<<ll<<endl;
		cout<<"Size:"<<ll.size()<<endl;
		
	}
	return 0;
}
