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
class queue
{
    private:
    node *front;
    node *rear;   
    public:
    queue()
    {
        front=NULL;
        rear=NULL;
    }    
    int empty()
    {
        if(front==NULL)
            return(1);
        else
            return(0);
    }   
    void enqueue(int x)
    {
        node *temp = new node(x);
        if(empty())
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }    
    int dequeue()
    {      
        int x = front->data;
        node *temp = front;
        front = front->next;            
        delete temp;
        return(x);
    }   
    int peek()
    {
        return(front->data); 
    }   
    void display()
    {
        node *temp = front;
        while(temp != NULL)
        {
            cout << "\t" <<temp -> data;
            temp = temp->next;
        }
    }
};
int main()
{
   queue q;
   int x; 
   q.enqueue(10);
   q.enqueue(20);
   q.enqueue(30);  
   cout << "Current Queue: " << endl;
   q.display(); 
   x = q.peek();
   cout << "\n Front element is " << x << endl; 
   x = q.dequeue();
   cout << "Removed " << x << endl;
   cout << "Queue after removal: " << endl;
   q.display();  
   q.dequeue(); 
   q.dequeue(); 
   q.dequeue();    
   return 0;
}

/*
PS D:\Diptighule_33> cd "d:\Diptighule_33\" ; if ($?) { g++ queue_linked_list.cpp -o queue_linked_list } ; if ($?) { .\queue_linked_list }
Current Queue: 
        10      20      30
 Front element is 10
Removed 10
Queue after removal: 
        20      30/*
*/