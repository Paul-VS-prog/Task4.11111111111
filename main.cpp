#include <iostream>
#include <locale.h>
using namespace std;
struct list{
    int id;
    list* next;
};
void push_start(list*& head, int e){
    list *t = new list;
    t->id = e;
    t->next = head;
    head = t;
}
void print(list* head){
    list* t = head;
    while (t){
        cout << t->id << " ";
        t = t->next;
    }
}
void push_before(list*& head, int e, int f){
    if (head->id == f){
        push_start(head, e);
    }
    else {
        list* t = head;
        list* p = new list;
        p->id = e;
        while (t->next->id != f) {
            t = t->next;
        }
        p->next = t->next;
        t->next = p;
    }
}
void push_after(list*& head, int e, int f){
    list* t = head;
    list* p = new list;
    p->id = e;
    while (t->id != f) {
        t = t->next;
    }
    p->next = t->next;
    t->next = p;
}
void push_end(list*& head, int e){
    if (!head){
        push_start(head, e);
    }
    else {
        list* t = head;
        while (t->next) {
            t = t->next;
        }
        push_after(t, e, t->id);
    }
}
void pop_start(list*& head){
    int f;
    list *t = head;
    f = head->id;
    head = head->next;
    delete(t);
}
void pop_end(list*& head){
    int f;
    if(!(head->next)){
        f = head->id;
        pop_start(head);
    }
    else {
        list* t = head;
        while(t->next->next) {
            t = t->next;
        }
        f = t->next->id;
        delete(t->next);
        t->next = NULL;
    }
}
void pop_ze(list*& head, int e){
    if (head->id == e) {
        pop_start(head);
    }
    else {
        list* t = head;
        while(t->next->id != e) {
            t = t->next;
        }
        if (!(t->next->next)) {
            pop_end(head);
        }
        else {
            pop_start(t->next);
        }
    }
}
bool hdoe(list* head){
    int c = 0;
    list* t = head;
    int x1, x2;
    while (t){
        x1 = 0;
        x1 += t->id;
        t = t->next;
        list* t1 = t;
        while (t1) {
            x2 = 0;
            x2 += t1->id;
            if(x1 == x2) {
                c++;
            }
            t1 = t1->next;
        }
    }
    return (c != 0);
}
int main() {
    list *head = NULL;
    int x, a, p;
    cout << "Enter the appropriate number" << endl;
    cout << "0 - end of the program" << endl;
    cout << "1 - inserting an element at the beginning of the list" << endl;
    cout << "2 - print the list" << endl;
    cout << "3 - insert an element into the list before the given element" << endl;
    cout << "4 - insert an item after a given item into the list" << endl;
    cout << "5 - insert item at the end of the list" << endl;
    cout << "6 - remove the first element" << endl;
    cout << "7 - remove the last element" << endl;
    cout << "8 - remove the given item" << endl;
    cout << "9 - check if the list L contains at least two identical elements" << endl;
    while (1) {
        cin >> x;
        switch(x)
        {
        case 0:
            return 0;
        case 1:
            cout << "Enter element: ";
            cin >> a;
            push_start(head, a);
            break;
        case 2:
            print(head);
            cout << endl;
            break;
        case 3:
            cout << "Enter element: ";
            cin >> a;
            cout << "Enter the given element: ";
            cin >> p;
            push_before(head, a, p);
            break;
        case 4:
            cout << "Enter element: ";
            cin >> a;
            cout << "Enter the given element: ";
            cin >> p;
            push_after(head, a, p);
            break;
        case 5:
            cout << "Enter element: ";
            cin >> a;
            push_end(head, a);
            break;
        case 6:
            pop_start(head);
            break;
        case 7:
            pop_end(head);
            break;
        case 8:
            cout << "Enter element: ";
            cin >> a;
            pop_ze(head, a);
            break;
        case 9:
            if(hdoe(head)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            break;
        }
    }
    return 0;
}
