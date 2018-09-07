#include<bits/stdc++.h>
using namespace std;
//-----------------------class Student--------------------------------------------------------
class Student{
	private:
		int rollNo;
		float cgpa;
		Student* next;
	public:
		Student(){
			rollNo=cgpa=-1;
		}			//Empty Constructor
		Student(int rollNo,float cgpa){			//Constructor with parameter
			this->rollNo=rollNo;
			this->cgpa=cgpa;
			next=NULL;		
		}
		void setData(int rollNo,float cgpa);
		int getRollNo();
		void setNextNode(Student*);
		friend ostream& operator<<(ostream&,const Student);
		Student* getNextNode();
};
ostream& operator<<(ostream& out,Student node){
	out<<"Roll No : "<<node.rollNo;
	out<<", CGPA : "<<node.cgpa;
	return out;
}
void Student::setData(int rollNo,float cgpa){			//data setter function
	this->rollNo=rollNo;
	this->cgpa=cgpa;
}
int Student::getRollNo(){				//data getter function
	return rollNo;
}
void Student::setNextNode(Student *add){		//next-pointer setter function
	next=add;
}
Student* Student::getNextNode(){			//next-pointer getter function
	return next;
}
//--------------------------------------------------------------
//-----------class MyNode-----------------------------------------------
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
		friend ostream& operator<<(ostream&,const MyNode);
		MyNode* getNextNode();
};
ostream& operator<<(ostream& out,MyNode node){
	out<<"Data : "<<node.data;
	return out;
}
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
	return Node();
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
		out<<"{";
		while(p!=NULL){
			out<<"["<<*p<<"]";			
			//out<<p->getData();			//revisit this line
			if(p->getNextNode()!=NULL)
				out<<",\n";
			p=p->getNextNode();
		}
		out<<"}";
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
	cout<<ll<<endl;
	cout<<"Size:"<<ll.size()<<endl;
	int i=0;while(i<ll.size()){
		MyNode newNode=ll.removeFirst();
		cout<<ll<<endl;cout<<newNode;
		cout<<"Size:"<<ll.size()<<endl;		
	}

	LinkedList<Student> sll;

	Student *s1=new Student();Student *s2=new Student(2,3.8);
	s1->setData(4,3.6);
	sll.addFirst(s1);sll.addFirst(s2);
	cout<<sll<<endl;
	cout<<"Size:"<<sll.size()<<endl;
	i=0;while(i<sll.size()){
		Student newNode=sll.removeFirst();
		cout<<sll<<endl;cout<<newNode;
		cout<<"Size:"<<sll.size()<<endl;		
	}
	Student newNode=sll.removeFirst();
		cout<<sll<<endl;cout<<newNode;
		cout<<"Size:"<<sll.size()<<endl;
	return 0;
}
