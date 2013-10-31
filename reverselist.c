#include<iostream>
using namespace std;
struct ListNode
{
	int value;
	ListNode *next;
};

class list
{
public:
	list():head(NULL){};
	~list();
	void InsertNode(ListNode *node);
	void Print();
	void Reverse();
	void Reverse(int n);
public:
	ListNode *head;
};


list::~list()
{
	while(head)
	{
		ListNode *node=head;
		head=head->next;
		delete node;
	}
}

void list::InsertNode(ListNode *node)
{
	if(head==NULL) head=node;
	else 
	{
		ListNode *tmp=head;
		while(tmp->next)
			tmp=tmp->next;
		tmp->next=node;
	}
}

void list::Print()
{
	if(head==NULL) return;
	ListNode *tmp=head;
	while(tmp)
	{
		cout<<tmp->value<<" ";
		tmp=tmp->next;
	}
}

void list::Reverse()
{
	if(head==NULL||head->next==NULL) return;
	ListNode *current=head,*pre=NULL;
	while(current)
	{
		ListNode *tmp=pre;
		pre=current;
		current=current->next;
		pre->next=tmp;
	}
	head=pre;
}

void list::Reverse(int n)
{
	if(head==NULL||head->next==NULL) return;
	ListNode *current=head,*pre=NULL,*tmpNode=head;
/*	int itmp=n;
	while(tmpNode)
	{
		while(tmpNode&&--n)
			tmpNode=tmpNode->next;	
		if(n>1)
		{
			n=itmp;
			
			while(current&&--n!=1)
			{
				ListNode *tmp=pre;
				pre=current;
				current=current->next;
				pre->next=tmp;
			}
			tmpNode=pre;
			n=itmp;
		}
		else
			return;
	}*/

}

int main()
{
	int value;
	list a;
	cout<<"enter node:"<<endl;
	while(cin>>value&&value!=-1)
	{
  	ListNode *node=new ListNode;
		node->value=value;
		node->next=NULL;
		a.InsertNode(node);
	}
	a.Print();
//	cout<<"reverse list:"<<endl;
//	a.Reverse();
//	a.Print();
	cout<<"reverse by number:"<<endl;
	cin>>value;
	a.Reverse(value);
	a.Print();
	string a;

	return 0;
}
