using namespace std;
#include <iostream>

class node{
public:
    string phone;
    string birth;
    string s_id; // key
    node *left, *right;
    void set(string p, string date, string id);
};

void node::set(string p, string date, string id){
    phone = p;
    birth = date;
    s_id = id;
}

class bst_tree{
private:
    node *root;
    int currentsize;
public:
    bst_tree();
    bool empty();
    node search_by_key(string s);
    void printList();
    void insert(node t);
};

bst_tree::bst_tree(){
    root = NULL;
    currentsize = 0;
}
bool bst_tree::empty(){
    return (root == NULL);
}
void bst_tree::insert(node t){
    node *temp;
    node *p;
    
    temp = new node;
    *temp = t;
    temp->left = NULL;
    temp->right = NULL;
    
    if(empty()){
        root = temp;
        return;
    }
    p=root;
    while(1){
        if(p->s_id == t.s_id){
            cout << "학번 중복 -> failed\n" ;
            return;
        }
        else{
            if(p->s_id < t.s_id){
                if(p->right == NULL){
                    p->right = temp;
                    currentsize++;
                    cout << "\n => 추가됨!\n\n";
                    return;
                }
                else
                    p = p->right;
            }
            else if(p->s_id > t.s_id){
                if(p->left == NULL){
                    p->left = temp;
                    currentsize++;
                    cout << "\n => 추가됨!\n\n";
                    return;
                }
                else
                    p = p->left;
            }
        }
    }
}

void inorder(node *start){
    
    if(start == NULL)
        return;
    
    inorder(start->left);
    cout << " 학번 : "  <<start->s_id << " 전화 번호 : " << start->phone <<  " 생일 : " << start->birth << "\n";
    inorder(start->right);
};

void bst_tree::printList(){
    if(empty()){
        cout << "\n 데이터 없음\n\n";
        return ;
    }
    inorder(root);
}

char menuList(){
    char result;
    cout << "==============\n";
    cout << "1.새로운 원소추가\n" << "2.원소 조희\n" << "3.전체목록보기\n" << "4.종료\n";
    cout << "\n" << " 명령 선택 : ";
    cin >> result;
    
    return result;
};

node bst_tree::search_by_key(string s){
    node *p;
    p = root;
    if(root == NULL){
        node tmp;
        tmp.set("NONE", "NONE", "NONE");
        cout << " 주어진 학번  " << s << " 은 존재하지 않음\n";
        return tmp;
    }
    while(1){
        if(p->s_id == s)
            return (*p);
        if(p->s_id < s){
            if(p->right == NULL){
                node tmp;
                tmp.set("NONE", "NONE", "NONE");
                cout << " 주어진 학번  " << s << " 은 존재하지 않음\n";
                return tmp;
            }
            else
                p= p->right;
        }
        else{
            if(p->left == NULL){
                node tmp;
                tmp.set("NONE", "NONE", "NONE");
                cout << " 주어진 학번  " << s << " 은 존재하지 않음\n";
                return tmp;
            }
            else
                p = p->left;
        }
    }
}


int main(int argc, const char * argv[]) {
    bst_tree tree;
    node tmp;
    char menu;
    
    do{
        menu = menuList();
        
        if(menu != '1' && menu != '2' && menu != '3' && menu != '4'){
            cout << "\n 번호 입력 에러\n";
            cout << menu;
            continue;
        }
        
        if(menu == '1'){
            string phone_num , birth_date , id_num;
            cout << " 추가할 데이터의 전화번호와 생일을 입력해주세요" << "\n";
            cout << " 전화번호 : ";
            cin >> phone_num;
            cout << " 생일 : ";
            cin >> birth_date;
            cout << " 학번 : ";
            cin >> id_num ;
            
            tmp.set(phone_num, birth_date, id_num);
            tree.insert(tmp);
            
        }
        else if(menu == '2'){
            
            if(tree.empty()){
                cout << " \n 데이터 없음 \n\n";
                continue;
            }
            string search_id;
            cout << " 검색할 학번 : ";
            cin >> search_id;
            
            tmp = tree.search_by_key(search_id);
            
            cout << "\n 학번     : "<< tmp.s_id << endl;
            cout << " 전화번호  : "<< tmp.phone << endl;
            cout << " 생일     : " << tmp.birth << endl;
            
        }
        else if(menu == '3')
            tree.printList();
        
        else if(menu == '4'){
            printf("\n종료되었습니다!\n");
            break;
        }
        
    }while(menu != '4');
    
    return 0;
}
