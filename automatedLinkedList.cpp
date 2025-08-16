#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    int elementCount = 0;

    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = tail = nullptr;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            cout << "\nSuccessfully inserted " << val << " at the front.\n";
            elementCount++;

            return;
        }
        else {
            newNode->next = head;
            head = newNode;
            cout << "\nSuccessfully inserted " << val << " at the front.\n";
            elementCount++;
        }

    }

    void push_middle(int val, int position) {
        Node* newNode = new Node(val);
        Node* temp = head;
        if (head == nullptr)
        {
            head = tail = newNode;
            cout << "\nSuccessfully inserted " << val << " in the " << position << "th position.\n";
            elementCount++;
            return;
        }
        else if (position == 1) {
            push_front(val);
        }
        else if (position < 1 || position > elementCount + 1) {
            cout << "Invalid Position!";
            return;
        }
        else {
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "\nSuccessfully inserted " << val << " in the " << position << "th position.\n";
            elementCount++;
        }
    }


    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            cout << "\nSuccessfully inserted " << val << " at the last.\n";
            elementCount++;
            return;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            cout << "\nSuccessfully inserted " << val << " at the last.\n";
            elementCount++;

        }
    }
    void pop_front() {
        Node* temp = head;
        if (head == nullptr)
        {
            cout << "\nLinked List is empty...\n";
        }
        else {
            head = head->next;
            cout << "\nSuccessfully deleted " << temp->data << " from the front.\n";
            temp->next = nullptr;
            delete temp;
            elementCount--;
        }
    }

    void pop_middle(int position) {
        Node* temp = head;
        if (head == nullptr)
        {
            cout << "Linked list is empty...\n";
            return;
        }
        else if (position < 1 || position > elementCount)     // for pop_middle
        {
            cout << "Invalid Position!";
            return;
        }
        else {

            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            elementCount--;

            cout << "\nSuccessfully deleted " << temp->next->data << " from the " << position << "th position.\n";
            temp->next = temp->next->next;

        }

    }

    void pop_back() {
        Node* temp = head;
        if (head == nullptr)
        {
            cout << "Linked List is empty...";
        }
        else {
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            cout << "\nSuccessfully deleted " << temp->next->data << " from the last.\n";
            temp->next = nullptr;
            delete tail;
            tail = temp;
            elementCount--;

        }
    }
    void displayList() {
        Node* temp = head;
        if (head == nullptr)
        {
            cout << "\n->Linked List is empty()\n";
            cout << "  Element count: " << elementCount << '\n';

            return;
        }
        else {
            cout << "\n->Updated Linked list: ";
            while (temp != nullptr)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL ";

            cout << "\n  Element count: " << elementCount << '\n';
        }

    }

};

void addNumberToFront(LinkedList& list) {
    int val;
    cout << "\nEnter the number: ";
    cin >> val;
    list.push_front(val);
    list.displayList();

}
void addNumberToMiddle(LinkedList& list) {
    int val, position;
    cout << "\nEnter the number: ";
    cin >> val;
    cout << "Enter the postion: ";
    cin >> position;

    list.push_middle(val, position);
    list.displayList();

}
void addNumberToLast(LinkedList& list) {
    int val;
    cout << "\nEnter the number: ";
    cin >> val;
    list.push_back(val);
    list.displayList();
}
void deleteFromFirst(LinkedList& list) {
    list.pop_front();
    list.displayList();

}
void deleteFromMiddle(LinkedList& list) {
    int position;
    cout << "Enter the postion: ";
    cin >> position;
    list.pop_middle(position);
    list.displayList();

}
void deleteFromLast(LinkedList& list) {
    list.pop_back();
    list.displayList();

}

void displayLinkedList(LinkedList& list) {
    list.displayList();

}

void showOption() {
    bool exit = false;
    cout << "Automated Linked List by Fairuz Faiyaz\n";
    LinkedList list;

    while (!exit)
    {
        int choice;
        cout << "\nOption Pane:\n1.Add number to front\n2.Add number to middle\n3.Add number to last\n4.Delete number from front\n5.Delete number from middle\n6.Delete number from last\n7.Display Linked List\n8.Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addNumberToFront(list);
            break;
        case 2:
            addNumberToMiddle(list);
            break;
        case 3:
            addNumberToLast(list);
            break;
        case 4:
            deleteFromFirst(list);
            break;
        case 5:
            deleteFromMiddle(list);
            break;
        case 6:
            deleteFromLast(list);
            break;
        case 7:
            displayLinkedList(list);
            break;
        case 8:
            exit = true;
            cout << "Extiing...XXX\n";
            break;
        default:
            cout << "\nInvalid input. Please enter your choice in 1-8\n";
            break;
        }

    }

}

int main() {
    showOption();
    return 0;
}