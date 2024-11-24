#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void AddToHead(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddToTail(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    LinkedList<T>* Clone() const {
        LinkedList<T>* newList = new LinkedList<T>();

        Node* temp = head;
        while (temp) {
            newList->AddToTail(temp->data);
            temp = temp->next;
        }

        return newList;
    }

    LinkedList<T> operator+(const LinkedList<T>& other) const {
        LinkedList<T> newList;

        Node* temp = head;
        while (temp) {
            newList.AddToTail(temp->data);
            temp = temp->next;
        }

        temp = other.head;
        while (temp) {
            newList.AddToTail(temp->data);
            temp = temp->next;
        }

        return newList;
    }

    LinkedList<T> operator*(const LinkedList<T>& other) const {
        LinkedList<T> newList;

        Node* temp1 = head;
        while (temp1) {
            Node* temp2 = other.head;
            while (temp2) {
                if (temp1->data == temp2->data) {
                    newList.AddToTail(temp1->data);  
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        return newList;
    }

    void Show() const {
        if (!head) {
            cout << "Список порожній" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void DeleteAll() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    ~LinkedList() {
        DeleteAll();
    }
};

int main() {
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.AddToHead(10);
    list1.AddToTail(20);
    list1.AddToTail(30);

    list2.AddToHead(20);
    list2.AddToTail(30);
    list2.AddToTail(40);

    LinkedList<int>* clonedList = list1.Clone();
    cout << "Clone list 1: ";
    clonedList->Show();

    LinkedList<int> combinedList = list1 + list2;
    cout << "Group list: ";
    combinedList.Show();

    LinkedList<int> commonList = list1 * list2;
    cout << "Common elements: ";
    commonList.Show();

    delete clonedList;
     
