#include<iostream>
using namespace std;
#define MAX 5
class node
{
    public:
    int data;
    node *next;
node(int x)
{
    data=x;
    next=NULL;
}
};
class stack
{
    private:
    node *top;
    public:
    stack()
    {
        top=NULL;
    }
    int empty()
    {
        if(top==NULL)
        return(1);
        else
        return(0);
    }
    void push(int x)
    {
        node *temp=new node(x);
        temp->next=top;
        top=temp;
    }
    int pop()
    {
        int x=top->data;
        node *temp=top;
        top=top->next;
        delete temp;
        return(x);
    }
    int peek()
    {
        return(top->data); 
    }
    void display()
    {
        node *temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
   stack s;
   int x;
   s.push(10);
   s.push(20);
   s.push(30);  
   s.display();
   x=s.peek();
   cout<<"top element is "<<x<<endl;
   x=s.pop();
    cout<<"Removed "<<x<<endl;
    s.display();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}

/*
PS D:\Diptighule_33> cd "d:\Diptighule_33\" ; if ($?) { g++ stack_linked_list.cpp -o stack_linked_list } ; if ($?) { .\stack_linked_list }
30
20
10
top element is 30
Removed 30
20
10
*/
