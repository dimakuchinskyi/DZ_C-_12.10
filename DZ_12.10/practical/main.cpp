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
    LinkedList() : head(nullptr), tail(nullptr) 
    {
        head = nullptr;
        tail = nullptr;
    }

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

    void InsertAtPosition(T value, int pos) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0) {
            AddToHead(value);
            return;
        }
        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (!temp) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void DeleteAtPosition(int pos) {
        if (pos < 0 || !head) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0) {
            DeleteFromHead();
            return;
        }

        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (!temp || !temp->next) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;

        if (nodeToDelete == tail) {
            tail = temp;
        }

        delete nodeToDelete;
    }

    void DeleteFromHead() {
        if (!head) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
    }

    int FindElement(T value) {
        Node* temp = head;
        int pos = 0;
        while (temp) {
            if (temp->data == value) {
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1; 
    }

    int ReplaceElement(T oldValue, T newValue) {
        Node* temp = head;
        int count = 0;
        while (temp) {
            if (temp->data == oldValue) {
                temp->data = newValue;
                count++;
            }
            temp = temp->next;
        }
        return count > 0 ? count : -1;
    }

    void Reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        tail = head;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
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
            DeleteFromHead();
        }
    }

    ~LinkedList() {
        DeleteAll();
    }
};

int main() {
    LinkedList<int> list;

    list.AddToHead(10);
    list.AddToTail(20);
    list.AddToHead(5);
    list.Show();

    list.InsertAtPosition(15, 2);
    list.Show();

    list.DeleteAtPosition(1);
    list.Show();

    cout << "Position: " << list.FindElement(15) << endl; 

    int replacedCount = list.ReplaceElement(20, 25);
    cout << "Count of replaces: " << replacedCount << endl;
    list.Show();

    list.Reverse();
    list.Show();

    return 0;
}
