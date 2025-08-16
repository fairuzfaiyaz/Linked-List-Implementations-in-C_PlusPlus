# 🔗 Linked List Implementations in C++

This repository contains two different implementations of linked lists in C++:

1. **Singly Linked List**  
   - Supports insertion (front, middle, back)  
   - Supports deletion (front, middle, back)  
   - Interactive **menu-driven program**  

2. **Doubly Linked List**  
   - Supports insertion (front, middle, back)  
   - Supports deletion (front, middle, back)  
   - Implements **Sorting (Selection, Bubble, Insertion Sort)**  
   - Implements **Binary Search** on a sorted list  

---

## 📌 Features

### ✅ Singly Linked List
- `push_front(int val)` → Insert at front  
- `push_middle(int val, int position)` → Insert at given position  
- `push_back(int val)` → Insert at back  
- `pop_front()` → Delete from front  
- `pop_middle(int position)` → Delete from given position  
- `pop_back()` → Delete from back  
- `displayList()` → Show updated linked list with element count  

👉 Comes with an **interactive option panel**:
- Add number to front
- Add number to middle
- Add number to last
- Delete number from front
- Delete number from middle
- Delete number from last
- Display Linked List
- Exit


---

### ✅ Doubly Linked List
- `push_front(int val)` → Insert at front  
- `push_middle(int pos, int val)` → Insert at given position  
- `push_back(int val)` → Insert at back  
- `pop_front()` → Delete from front  
- `pop_middle(int pos)` → Delete from given position  
- `pop_back()` → Delete from back  
- `selectionSort()` → Sort list using selection sort  
- `bubbleSort()` → Sort list using bubble sort  
- `insertionSort()` → Sort list using insertion sort  
- `binarySearch(int val)` → Perform binary search on sorted list  
- `display()` → Print the list in both directions  

---

## 🚀 How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/LinkedList-CPP.git
   cd LinkedList-CPP
   g++ singly.cpp -o singly
   g++ doubly.cpp -o doubly
   ./singly   # For singly linked list (menu-driven)
   ./doubly   # For doubly linked list
   


