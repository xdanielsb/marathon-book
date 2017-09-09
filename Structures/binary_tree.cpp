#include <iostream>

using namespace std;

struct node {
    int val = 0;
    node * l = nullptr;
    node * r = nullptr;
};

inline node* build(node *head, int value){
    node *son = new node;
    son->val = value;
    if (head == nullptr) return son;
    node * aux = head, * nxt = head;
    while(nxt != nullptr){
        aux = nxt;
        if (value > nxt->val) nxt = nxt->r;
        else nxt = nxt->l;
    }
    if(value > aux-> val) aux->r = son;
    else aux->l = son;
    return head;
}

inline void show(node* head){
    if (head==nullptr) return;
    show(head->l);
    cout << head->val << endl;
    show(head->r);
}
int main(){
    node *head = new node;
    head->val = 5;

    head = build(head, 45);
    head = build(head, 20);

    show(head);
    return 0;
}
