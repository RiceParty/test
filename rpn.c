#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;

template<typename T>
void ChangeSize(T* &a,const int oldsize,const int newsize)
{
	if(newsize<0) cout<<"New size must be > 0!"<<endl;
	else 
	{
		T* temp=new T[newsize];
		int number=min(oldsize,newsize);
		copy(a,a+number,temp);
		delete[]a;
		a=temp;
	}
}

template<typename T>
class Stack
{
public:
	Stack(int stackcapacity=30);
//	~Stack();
	bool IsEmpty() const;
	T& Top() const;
	void Push(const T& item);
	void Pop();
private:
	T* stack;
	int top;
	int capacity;
};

template<typename T>
Stack<T>::Stack(int stackcapacity):capacity(stackcapacity)
{
	if(capacity<1) cout<<"stack capacity must be > 0!"<<endl;
	else 
	{
		stack=new T[capacity];	
		top=-1;
	}
}

//template<typename T>
//Stack<T>::~Stack(){delete[] stack;}

template<typename T>
inline bool Stack<T>::IsEmpty() const{return top==-1;}

template<typename T>
inline T& Stack<T>::Top() const
{
	if(IsEmpty())cout<<"stack is empty"<<endl;
	else return stack[top];
}

template<typename T>
void Stack<T>::Push(const T& item)
{
	if(top==capacity-1)
	{
		ChangeSize(stack,capacity,2*capacity);
		capacity*=2;
	}
	stack[++top]=item;
}

template<typename T>
void Stack<T>::Pop()
{
	if(IsEmpty()) cout<<"stack is empty.cannot delete"<<endl;
	else stack[top--].~T();
}

inline bool IsOperator(char op)
{
	return (op=='+'||op=='-'||op=='*'||op=='/'||op=='('||op==')')?1:0;
}
int OpPriority(char op)
{
	switch (op)
	{
		case '+':return 2;
		case '-':return 2;
		case '*':return 3;
		case '/':return 3;
//		case '(':return 1;
//		case ')':return 1;
		default:return 0;
	}
}

template<typename T>
void trans(char* infix,Stack<T> &stck)
{
	stck.Push('#');
	for(int i=0;i<strlen(infix);i++)
	{
		if(infix[i]>='0'&&infix[i]<='9')
			cout<<infix[i];
		else if(infix[i]==')')
		{
			for(;stck.Top()!='(';stck.Pop())
				cout<<stck.Top();
			stck.Pop();
		}
		else	
		{
			if(infix[i]!='(')
				for(;OpPriority(stck.Top())>=OpPriority(infix[i]);stck.Pop())
					cout<<stck.Top();
			stck.Push(infix[i]);
		}
	}
	for(;!stck.IsEmpty();stck.Pop())
		if(stck.Top()!='#')
			cout<<stck.Top();
	cout<<endl;
//	if(isdigit(infix))
//			cout<<infix;
//	else if(IsOperator(infix))
//	{
//		if(stck.IsEmpty())
//			stck.Push(infix);
//		else
//		{
//			char temp=stck.Top();
//			if(OpPriority(temp)>=OpPriority(infix))
//			{		
//				if(stck.Top()==')')
//				{	
//					while(stck.Top()!='(')
//					{
//						cout<<stck.Top();
//						stck.Pop();
//					}
//				}
//				else		
//				{
//					while(!stck.IsEmpty())
//					{
//						cout<<stck.Top();
//						stck.Pop();
//					}
//					stck.Push(infix);
//				}
//			}
//			else 
//				stck.Push(infix);
//		}
//	}
}

int calculate(char suffix)
{
}


int main()
{
	char expression[100];
	Stack<char> stck;
	cin>>expression;
//	int i=0;
//	while(expression[i]!='\0')
//	{
//		trans(expression[i],stck);
//		i++;
//	}
//	while(!stck.IsEmpty())
//	{
//		cout<<stck.Top();
//		stck.Pop();
//	}
	trans(expression,stck);
	cout<<endl;
	return 0;
}
