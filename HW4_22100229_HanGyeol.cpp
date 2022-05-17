#define SIZE 100
#define EOS '$'
#include <iostream>

class op_stack{
    char s[SIZE];
    int top;
public:
    op_stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
};

op_stack::op_stack(){
    top = 0;
}
void op_stack::push(char x){
    s[top] = x;
    top++;
}
char op_stack::pop(){
    top--;
    return s[top];
}
bool op_stack::empty(){
    return (top == 0);
}
char op_stack::top_element(){
    return s[top-1];
}


bool is_operand(char ch){
    if(ch == '(' || ch ==')' || ch =='*' || ch == '/' || ch =='+' || ch =='-' || ch =='%')
        return false;
    else
        return true;
}

int get_precedence(char op){
    if(op == '$' || op == '(')
        return(0);
    else if(op == '+' || op == '-')
        return(1);
    else if(op == '*' || op == '%' || op == '/')
        return(3);
    
    return 0;
}

int main(int argc, const char * argv[]) {
    std::string input, output;
    op_stack stack1;
    
    std::cin >> input;
    stack1.push(EOS);
    
    for(int i = 0 ; i<input.size(); i++){
        if(is_operand(input[i]))
            output += input[i];
        else{
            stack1.push(input[i]);
            //스택에 들어가려고 하는데 top 원소의 우선순위가 더 높다면
            
            if(get_precedence(input[i]) < get_precedence(stack1.top_element())){
                //일단 들어갔던 원소 나오고
                while(get_precedence(input[i]) > get_precedence(stack1.top_element())){
                    output += stack1.pop();
                    
                    if(stack1.top_element() == ')'){ // 만약 닫는 괄호라면
                        stack1.pop(); //일단 닫는 괄호 pop
                        while(stack1.top_element() != '('){ // 여는 괄호 만날때까지 팝하여 output에 저장
                            output += stack1.pop();
                        }
                        stack1.pop();
                    }
                }
            }
            
            if(stack1.top_element() == ')'){ // 만약 닫는 괄호라면
                stack1.pop(); //일단 닫는 괄호 pop
                while(stack1.top_element() != '('){ // 여는 괄호 만날때까지 팝하여 output에 저장
                    output += stack1.pop();
                }
                stack1.pop();
            }
        }
    }
    
    while(stack1.top_element() != EOS){
        output += stack1.pop();
    }
    
    std::cout << output << "\n";
    return 0;
}
