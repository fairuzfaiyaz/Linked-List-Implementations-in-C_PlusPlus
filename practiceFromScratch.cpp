#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

class list {
    node* head;
    node* tail;
public:
    list() {
        head = tail = nullptr;
    }

    void push_front(int val) {
        node* newNode = new node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        node* newNode = new node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == nullptr)
        {
            cout << "Empty Linked List!";
            return;
        }
        else {
            node* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }

    }

    void pop_back() {
        if (head == nullptr)
        {
            cout << "Empty linked list!";
        }
        else {
            node* temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }

    }

    void display() {
        if (head == nullptr)
        {
            cout << "Empty Linked list!\n";
        }
        else {
            node* temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "NULL";

        }
        cout << '\n';
    }

};

int main() {
    list l;

    cout << "Adding is front: \n";
    l.push_front(5);
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.display();

    cout << "adding is last: \n";

    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    l.push_back(9);
    l.display();

    cout << "pop front: \n";
    l.pop_front();
    l.display();

    cout << "pop back\n";
    l.pop_back();
    l.pop_back();
    l.display();


    return 0;
}