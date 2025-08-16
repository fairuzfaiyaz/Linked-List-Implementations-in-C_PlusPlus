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

class linkedList {
    node* head;
    node* tail;
public:
    linkedList() {
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
            newNode->next = head; //(*newNode).next=head;
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
        node* temp = head;
        if (head == nullptr)
        {
            cout << "Linked List is empty()...\n";
            return;
        }
        else {
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
    }

    void insertMiddle(int val, int position) {
        node* newNode = new node(val);
        node* temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }


    void deleteMiddle(int position) {
        node* temp = head;
        if (head == nullptr)
        {
            return;
        }
        else {
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }

    void pop_back() {
        if (head == nullptr)
        {
            cout << "Linked List is empty()...\n";
            return;
        }
        node* temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;

    }
    void displayList() {
        if (head == nullptr)
        {
            cout << "\n Linked  List is empty()";
        }
        else {

            node* temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }
    }
};


int main() {
    linkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);



    l.insertMiddle(999, 3);

    l.deleteMiddle(2);

    cout << "Linked List: ";
    l.displayList();


    return 0;
}