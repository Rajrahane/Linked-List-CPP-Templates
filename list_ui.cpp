#include "linked_list.cpp"
//-----------class MyNode-----------------------------------------------
class MyNode{
		int data;
	public:
		MyNode(){				//Empty Constructor
			data=-1;
		}
		MyNode(int data){			//Constructor with parameter
			this->data=data;
			//next=NULL;		
		}
		void setData(int data);
		int getData();
		friend ostream& operator<<(ostream&,const MyNode);
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
//--------------------------------------End of Class------------------------------------------

//-----------------------class Student--------------------------------------------------------
class Student{
	private:
		int rollNo;
		float cgpa;
	public:
		Student(){
			rollNo=cgpa=-1;
		}						//Empty Constructor
		Student(int rollNo,float cgpa){			//Constructor with parameter
			this->rollNo=rollNo;
			this->cgpa=cgpa;
		}
		void setData(int rollNo,float cgpa);
		int getRollNo();
		friend ostream& operator<<(ostream&,const Student);
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
int Student::getRollNo(){					//rollNo getter function
	return rollNo;
}
//--------------------------------------------------------------

int main(){
	/*LinkedList<float> ill;float *num=new float;*num=22.34;
	ill.addFirst(num);
	cout<<ill<<endl;
	*num=33.555;
	cout<<ill<<endl;
	ill.removeFirst();
	cout<<ill<<endl;cout<<*num;*/

	LinkedList<MyNode> ll;

	MyNode *n=new MyNode();
	//for(int i=0;i<4;i++){
		(n)->setData(45);
		ll.addFirst(n);
	MyNode *n2=new MyNode();
		n2->setData(34);
		ll.addFirst(n2);
		MyNode newNoden=ll.removeFirst();
		cout<<ll<<endl;cout<<newNoden;
		cout<<"Size:"<<ll.size()<<endl;	
		n2=new MyNode();
		n2->setData(76);
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
