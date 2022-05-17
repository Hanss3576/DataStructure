
#include <iostream>

class mystack{
    int stack[5];
    int top;
public:
    void init();
    int pop();
    bool stack_empty();
    void push(int a);
};

void mystack::init(){
    top = 0;
}
void mystack::push(int a){
    stack[top] = a;
    top++;
}
int mystack::pop(){
    top--;
    return stack[top];
}

bool mystack::stack_empty(){
    if(top == 0)
        return true;
    else
        return false;
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

            std::cout << x << std::endl ;

  }

  return 0;

}
