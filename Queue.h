//Generic Implementation of Queue
#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	struct Node<T> *next;
};

template <class T>
class Queue
{
	public :
		struct Node<T> *Head;
	
	Queue()
	{
		Head=NULL;
	}
	
	void Enqueue(T value)
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
	
	void Dequeue()
	{
		struct Node<T> *temp=Head;
		struct Node<T> *temp2=NULL;
		if(Head==NULL)
		{
			return;
		}
		
		if(Head->next==NULL)
		{
			delete(Head);
			Head=NULL;
		}
		else
		{
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			delete(temp->next);
			temp->next=NULL;
		}
	}
	
	int Count()
	{
		int cnt=0;
		struct Node<T> *temp=Head;
		while(temp!=NULL)
		{
			cnt++;
			temp=temp->next;
		}
		return cnt;
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
};
