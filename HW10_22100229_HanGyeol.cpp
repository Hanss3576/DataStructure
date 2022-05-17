using namespace std;
#include <iostream>

class node{
public:
    int num;
    node *link;
};

class mystack{
    node *top;
    node *tail;
public:
    void init();
    int pop();
    bool stack_empty();
    void push(int a);
};

void mystack::init(){
    top = NULL;
    tail = NULL;
}
void mystack::push(int a){
    node *temp;
    temp = new node;
    temp->num = a;
    
    temp->link = top;
    top = temp;
    if(stack_empty())
        tail = temp;
}

int mystack::pop(){
    node temp;
    node *p;
    
    p = top;
    temp = *top;
    top = top->link;
    delete p;
    if(stack_empty()){
        tail = NULL;
    }
    return temp.num;
}

bool mystack::stack_empty(){
    return top==NULL;
}

int main()

{
    mystack  s1;
    
    int list[5] = { 32, 123, 27, 131, 242 }, i, x;
    
    s1.init();
    
    for (i = 0; i < 5; i++ )
        
        if (list[i]> 100)
            s1.push( list[i] );
    
    while ( ! s1.stack_empty( ) )
        
    {
        
        x = s1.pop( );
        
        cout << x << std::endl ;
        
    }
    
    return 0;
    
}
