//Generic Stack Implemention

#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	struct Node *next;
	
};


template <class T>
class Stack
{
	public:
			struct Node<T> * Head;
			Stack()
			{
				Head=NULL;
			}
			
	void Display()
	{
		struct Node<T> *temp=Head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
		cout<<"\n";
		
	}	
	
	int Count()
	{
		int cnt=0;
		struct Node<T> * temp=Head;
		while(temp!=NULL)
		{
			cnt++;
			temp=temp->next;
		}
		return cnt;
	}
			
	void Push(T value)
	{
		struct Node<T> *newn=new Node<T>;
		newn->data=value;
		newn->next=NULL;
		
		if(Head==NULL)
		{
			Head=newn;
		}
		
		else
		{
			newn->next=Head;
			Head=newn;
		}	
	}
	
	void Pop()
	{
		struct Node<T> *temp=Head;
		
		if(Head!=NULL)
		{
			Head=Head->next;
			
			delete(temp);
		}
		
	}
};

