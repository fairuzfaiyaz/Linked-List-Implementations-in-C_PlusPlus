#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class doublyList {
    Node* head;
    Node* tail;
public:
    doublyList() {
        head = tail = nullptr; 
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;  // ← Fix here: head=tail=newNode
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_middle(int pos, int val) {
        if (pos <= 1) {
            push_front(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            push_back(val);
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "Linked List is empty!";
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "\nLinked list is empty!";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
    }

    void pop_middle(int pos) {
        if (head == nullptr) {
            cout << "List is empty!";
            return;
        }

        if (pos <= 1) {
            pop_front();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp == tail) {
            pop_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    Node* middleLinkedList(Node* start, Node* end) {
        if (start == nullptr) {
            return nullptr;
        }
        if (start == end) {
            return start;
        }

        Node* slow = start;
        Node* fast = start;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool binarySearch(int val) {
        Node* start = head;
        Node* end = nullptr;

        while (true) {
            Node* mid = middleLinkedList(start, end);
            if (mid == nullptr) {
                return false;
            }

            if (mid->data == val) {
                return true;
            }
            else if (start == end || mid == end || mid == nullptr) {
                break;
            }
            else if (mid->data > val) {
                end = mid->prev;  // Move end to left of mid
            }
            else {
                start = mid->next;  // Move start to right of mid
            }
        }
        return false;
    }

    void selectionSort() {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp != nullptr) {
            Node* minNode = temp;
            Node* r = temp->next;

            while (r != nullptr) {
                if (r->data < minNode->data) {
                    minNode = r;
                }
                r = r->next;
            }

            if (minNode != temp) {
                swap(temp->data, minNode->data);
            }
            temp = temp->next;
        }
    }
    void bubbleSort() {
        if (head == nullptr) return;

        bool swapped;
        Node* end = nullptr;

        do {
            swapped = false;
            Node* temp = head;

            while (temp->next != end) {
                if (temp->data > temp->next->data) {
                    swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }

            end = temp;
        } while (swapped);
    }
    void insertionSort() {
        if (head == nullptr || head->next == nullptr) return;

        Node* current = head->next;

        while (current != nullptr) {
            int key = current->data;
            Node* prev = current->prev;

            while (prev != nullptr && prev->data > key) {
                prev->next->data = prev->data;
                prev = prev->prev;
            }

            if (prev == nullptr) {
                head->data = key;
            }
            else {
                prev->next->data = key;
            }

            current = current->next;
        }
    }

    void display() {
        cout << "Doubly Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    doublyList l;
    l.push_front(6);
    l.push_front(5);
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    cout << "PUSH FRONT:\n";
    l.display();

    cout << "\nPUSH BACK:\n";
    l.push_back(7);
    l.push_back(8);
    l.push_back(9);
    l.display();

    cout << "\nPUSH MIDDLE at position 4 (insert 99):\n";
    l.push_middle(4, 99);
    l.display();

    cout << "\nPOP MIDDLE at position 4:\n";
    l.pop_middle(4);
    l.display();

    cout << "\nPOP FRONT:\n";
    l.pop_front();
    l.pop_front();
    l.display();

    cout << "\nPOP BACK:\n";
    l.pop_back();
    l.display();

    cout << "\nBinary Search for 5:\n";
    if (l.binarySearch(5))
        cout << "Found!\n";
    else
        cout << "Not Found!\n";


    return 0;
}
