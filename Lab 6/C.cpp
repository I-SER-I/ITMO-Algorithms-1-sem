#include <fstream>
using namespace std;

struct Node{
    int key;
    Node *l, *r;
};

bool TreeSearch(Node *x, int k){
    if(x == NULL)
        return false;
    if(x->key == k)
        return true;
    if(k < x->key)
        return TreeSearch(x->l, k);
    else
        return TreeSearch(x->r, k);
}

Node *TreeInsert(Node *&x, int a){
    if(x == NULL){
        x = new Node;
        x->key = a;
        x->l = x->r = NULL;
    }
    else if (x->key > a)
        TreeInsert(x->l, a);
    else if (x->key < a)
        TreeInsert(x->r, a);
    return x;
}

Node *TreeNext(Node *&root, int x){
    Node *current = root;
    Node *successor = NULL;
    while(current != NULL){
        if(current->key > x){
            successor = current;
            current = current->l;
        }
        else
            current = current->r;
    }
    return successor;
}

Node *TreePrev(Node *&root, int x){
    Node *current = root;
    Node *successor = NULL;
    while(current != NULL){
        if(current->key < x){
            successor = current;
            current = current->r;
        }
        else
            current = current->l;
    }
    return successor;
}

Node *TreeMin(Node *&x){
    if(x->l == NULL)
        return x;
    return TreeMin(x->l);
}

Node *TreeMax(Node *&x){
    if(x->r == NULL)
        return x;
    return TreeMax(x->l);
}

Node *TreeDelete(Node *&root, int a){
    if(root == NULL)
        return root;
    if(a < root->key)
        root->l = TreeDelete(root->l, a);
    else if(a > root->key)
        root->r = TreeDelete(root->r, a);
    else if(root->l != NULL && root->r != NULL){
        root->key = TreeMin(root->r)->key;
        root->r = TreeDelete(root->r, root->key);
    }
    else{
        if(root->l != NULL)
            root = root->l;
        else
            root = root->r;
    }
    return root;
}

int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
    Node *tree = NULL;
    string command;
    while (fin >> command) {
        int value;
        fin >> value;
        if(command == "insert")
            TreeInsert(tree, value);
        if(command == "exists"){
            if(TreeSearch(tree, value))
                fout << "true\n";
            else
                fout << "false\n";
        }
        if(command == "next"){
            Node *temp = TreeNext(tree, value);
            if(temp == NULL)
                fout << "none\n";
            else
                fout << temp->key << "\n";
        }
        if(command == "prev"){
            Node *temp = TreePrev(tree, value);
            if(temp == NULL)
                fout << "none\n";
            else
                fout << temp->key << "\n";
        }
        if(command == "delete")
            TreeDelete(tree, value);
    }
}
