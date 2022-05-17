using namespace std;
#define SIZE 100

#include <iostream>

class element{
public:
    string name;
    double score;
    void set_data(string initName,int initScore);
};

void element::set_data(string initName, int initScore){
    name = initName;
    score = initScore;
}

class my_heap{
private:
    element heap[SIZE] ;
    int csize ; // 현재 원소의 개수
public:
    my_heap();
    bool empty();
    bool full();
    void insert_heap(element otherElement);
    element delete_heap();
    int h_size(); // csize 값을 출력하는
};

my_heap::my_heap(){ //constructor로 my_heap를 선언하면, 현재 원소의 개수를 우선 0으로 초기화
    csize = 0;
}
int my_heap::h_size(){
    return csize;
}
bool my_heap::full(){
    return csize >= SIZE;
}
bool my_heap::empty(){
    // element 배열의 첫번째, 즉 0번째 원소는 비워놓고 시작.
    //따라서 현재 원소의 개수가 0보다 작아지면 empty로 체크 할 수 있음.
    return csize <= 0;
}

void my_heap::insert_heap(element otherElement){
    //우선 insert를 했기 때문에 원소의 개수를 증가 : csize++
    csize++;
    //가장 밑의 부분에 node를 하나 추가하고, 값을 비교하면서 자신의 위치를 찾기
    int location;
    location = csize;
    
    //값이 root까지 올라올 수 있는데 이 점을 어떻게 할지?
    //값의 교환의 기준 -> parent의 key값과 나의 key값을 비교해서 올리기
    while(location != 1 && otherElement.score > heap[location/2].score){
        heap[location] = heap[location/2];
        location /= 2;
    }
    heap[location] = otherElement;
}

element my_heap::delete_heap(){
    element temp; // element의 임시 저장 공간 -> 끝 원소 자리만 삭제하고 다시 자리 찾기 하기 위한
    element t; // root값 return하는 변수
    int parent , child;
    t = heap[1] ; // heap[1] : root에 해당하는 element
    
    parent = 1;
    child =2 ;
    temp = heap[csize];
    csize--;
    while(child <= csize){ // node들 끌어올리는 과정
        
        // 만약 왼쪽 child와 오른쪽 child를 비교하여 오른쪽이 더 크다면 오른쪽 값을 끌어올려야함 그렇기에 오른쪽 child를 선택
        if(child < csize && heap[child].score < heap[child+1].score)
            child ++ ;
        
        //더이상 끌어올린 곳이 없다면, 즉 child와 끝원소의 key값을 비교했을 때 끝원소가 더 크다면
        //parent 자리에 끝원소를 집어넣으면 된다.
        if(temp.score >= heap[child].score)
            break;
        heap[parent]=heap[child]; // 끌어올리고
        //다음단계로 가서 다시 끌어올리는 과정을 거침
        parent = child;
        child *= 2;
    }
    //최종적으로는 parent자리에 temp값을 넣는다 (마지막 원소의 값을 넣는다)
    heap[parent] = temp;
    return t; // 최종적으로는 root값을 출력
}

int main(int argc, char *argv[]){
    my_heap   h1;
    element   temp; // class type element
    
    temp.set_data("Kim", 88);
    h1.insert_heap(temp);
    
    temp.set_data("Lee", 77);
    h1.insert_heap(temp);
    
    temp.set_data("Park", 98);
    h1.insert_heap(temp);
    
    temp.set_data("Choi", 74);
    h1.insert_heap(temp);
    
    temp.set_data("Ryu", 94);
    h1.insert_heap(temp);
    
    temp.set_data("Cho", 85);
    h1.insert_heap(temp);
    
    while (h1.h_size() > 0) {
        
        temp = h1.delete_heap();
        
        cout << temp.name << " : " << temp.score << "\n";
        
    }
    
    return 0;
}
