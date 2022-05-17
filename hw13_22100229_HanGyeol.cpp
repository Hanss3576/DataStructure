using namespace std;

#include <iostream>



class bst_node{
public:
    string s_id;
    string name;
    double score;
    bst_node *left , *right;
    void set_data(string id, string set_name, double set_score);
};
void bst_node::set_data(string id, string set_name, double set_score){
    s_id = id;
    name = set_name;
    score = set_score;
}

void inorder_traverse(bst_node *p){
    if( p == NULL) return;
    
    inorder_traverse(p->left);
    cout << p->s_id << " : " << p->name << " : " << p->score << "\n";
    inorder_traverse(p->right);
};

class bst_tree{
private:
    bst_node *root;
    int csize;
public:
    bst_tree();
    void insert_node(bst_node t);
    bool empty();
    int size();
    bst_node search(string s);
    void show_inorder();
};

void bst_tree::show_inorder(){
    inorder_traverse(root);
}
bst_node bst_tree::search(string s){
    bst_node *p;
    p = root;
    if(root == NULL){
        bst_node tmp;
        tmp.set_data("00000000", "NONE", -1);
        cout << "The key " << s << " does not exist.\n";
        return tmp;
    }
    while(1){
        if(p->s_id == s)
            return (*p);
        if(p->s_id < s){
            if(p->right == NULL){
                bst_node tmp;
                tmp.set_data("00000000", "NONE", -1);
                cout << "The key " << s << " does not exist.\n";
                return tmp;
            }
            else
                p= p->right;
        }
        else{
            if(p->left == NULL){
                bst_node tmp;
                tmp.set_data("00000000", "NONE", -1);
                cout << "The key " << s << " does not exist.\n";
                return tmp;
            }
            else
                p = p->left;
        }
    }
}

bst_tree::bst_tree(){
    root = NULL;
    csize = 0;
}
bool bst_tree::empty(){
    return root == NULL;
}

void bst_tree::insert_node(bst_node t){
    bst_node *p;
    bst_node *tmp;
    
    tmp = new bst_node;
    (*tmp) = t ; // 값 복사해서 저장
    tmp->right = NULL;
    tmp->left = NULL;
    
    if(root == NULL)//empty()
    {
        root = tmp;
        return;
    }
    p = root; // p위치를 루트로 정해놓고
    while(1){
        if(p->s_id == t.s_id){
            cout << "failed" << endl;
            return;
        }
        if(p->s_id < t.s_id){
            if(p->right == NULL){
                p->right = tmp;
                csize++;
                return;
            }
            else
                p = p->right;
        }
        else{
            if(p->left == NULL){
                p->left = tmp;
                csize++;
                return;
            }
            else
                p = p->left;
        }
    }
}

int main()
{
    
    bst_node temp;
    
    bst_tree t1;
    
    temp.set_data("21900013", "Kim", 6.5);
    
    t1.insert_node(temp);
    
    temp.set_data("21900136", "Lee", 8.8);
    
    t1.insert_node(temp);
    
    temp.set_data("21900333", "Park", 9.2);
    
    t1.insert_node(temp);
    
    temp.set_data("21800442", "Choi", 7.1);
    
    t1.insert_node(temp);
    
    temp.set_data("21900375", "Ryu", 5.4);
    
    t1.insert_node(temp);
    
    temp.set_data("21700248", "Cho", 6.3);
    
    t1.insert_node(temp);
    
    
    
    cout << "\n\n Node List : inorder sequence \n";
    
    t1.show_inorder();
    
    
    
    string s_key = "21800442";
    
    temp = t1.search(s_key);
    
    
    
    cout << "\n -- " << s_key << "'s record ---" << endl;
    
    cout << " Student ID   : "<< temp.s_id << endl;
    
    cout << " Student Name : "<< temp.name << endl;
    
    cout << " Score        : " << temp.score << endl;
    
    
    
    return 0;
    
}
