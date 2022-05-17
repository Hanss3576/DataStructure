#include <iostream>

class weight{
    int kg;
    int g;
public:
    void set_weight(int n1, int n2);
    int get_weight();
};

void weight::set_weight(int n1, int n2){
    kg = n1;
    g = n2;
};

int weight:: get_weight(){
    return (kg*1000 + g);
}

weight add_weight(weight w1, weight w2){
    weight temp;
    int n;
    n = w1.get_weight() + w2.get_weight();
    temp.set_weight(n/1000, n%1000);
    return temp;
};

bool less_than(weight w1, weight w2){
    if(w2.get_weight() < w2.get_weight())
        return true;
    else
        return false;
};

int main( )

{

weight  w1, w2, w3;  // weight라는 class object 3개 생성

    w1.set_weight(3, 400);  // w1을 3kg 400 g으로

    w2.set_weight(2, 700);  // w2을 2kg 700 g으로

    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 6kg 100g

    std::cout << w3.get_weight() << "grams\n";

    if ( less_than(w1, w2) ) // w1이 w2보다 작은 값인가 판단
        std::cout << "yes.\n";
    else
        std::cout << "no.\n";   // 작지 않으므로 ‘no’ 출력

}
