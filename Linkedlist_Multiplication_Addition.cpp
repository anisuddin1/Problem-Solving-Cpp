#include <iostream>
using namespace std;

class Node { 
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;

        void clearNode(Node* node) {
            while (node) {
                Node* temp = node;
                node = node->next;
                delete temp;
            }
        }

        Node* reverse (Node* temp) {
            if (temp == nullptr || temp->next == nullptr) {
                return temp;
            }
            Node* newHead = reverse(temp->next);
            temp->next->next = temp;
            temp->next = nullptr;
            return newHead;
        }

        Node* addTwoLists (Node *first, Node *second) {
            if (first == nullptr || second == nullptr) return nullptr;
            Node *addHead = nullptr, *result = nullptr;
            first = reverse(first);
            second = reverse(second);
            int carry = 0;
            int temp = 0;
            int data1 = 0;
            int data2 = 0;
            while (first || second || carry) {
                if (first) {
                    data1 = first->data;
                    first = first->next;
                }
                else {
                    data1 = 0;
                }
                if (second) {
                    data2 = second->data;
                    second = second->next;
                }
                else {
                    data2 = 0;
                }
                temp = (data1 + data2) + carry;
                if (temp > 9) {
                    carry = temp / 10;
                    temp = temp % 10;
                }
                else {
                    carry = 0;
                }
                if (addHead) {
                    addHead->next = new Node(temp);
                    addHead = addHead->next;
                }
                else {
                    addHead = new Node(temp);                
                    result = addHead;
                }
            }
            return reverse(result);
        }

        Node* multiplyTwoLists(Node *first, Node *second) {
            Node* result = nullptr, *output = nullptr;
            Node* newNode = nullptr;
            first = reverse(first);
            Node* firstHead = first;
            second = reverse(second);
            int carry = 0;
            int mul = 1;
            int temp = 0;
            Node* zeroPaddig = nullptr, *zeroPaddigHead = nullptr;
            while (second) {                
                while (first) {
                    temp = (first->data * second->data) + carry;
                    if (temp > 9) {
                        carry = temp/ 10;
                        temp = temp % 10;
                    }
                    else {
                        carry = 0;
                    }        
                    if (newNode) {
                        newNode->next = new Node(temp);
                        newNode = newNode->next;
                    }
                    else {
                        newNode = new Node(temp);                
                        result = newNode;
                    }
                    first = first->next;
                }
                if (carry) {
                    newNode->next = new Node(carry);
                    newNode = newNode->next;            
                }        
                if (output) {
                    if (zeroPaddig) {
                        zeroPaddig->next = new Node(0);
                        zeroPaddig = zeroPaddig->next;
                    }
                    else {                
                        zeroPaddigHead = zeroPaddig = new Node(0);
                    }
                    zeroPaddig->next = result;
                    Node* num1 = output;
                    Node* num2 = reverse(zeroPaddigHead);
                    output = addTwoLists(num1, num2);
                    clearNode(result);
                    zeroPaddig->next = nullptr;
                    clearNode(num1);
                }
                else {
                    output = reverse(result);
                }
                newNode = nullptr;
                carry = 0;
                first = firstHead;
                second = second->next;
            }
            clearNode(zeroPaddigHead);
            return output;
        }

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = head;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == tail) {
                head = tail = newNode;
            } 
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void printList(Node* head) {
            while (head) {
                cout << head->data;
                head = head->next;
            }
            cout << endl;
        }
        
        void add() {
            string num1, num2;
            cout << "Enter First Number: ";
            cin >> num1;
            cout << "Enter Second Number: ";
            cin >> num2;
            Node *firstHead = nullptr, *secondHead = nullptr;
            Node *first = nullptr, *second = nullptr;
            for (auto i: num1) {
                int val = i - '0';
                if (val < 10) {
                    Node* temp = new Node(val);
                    if (first) {
                        first->next = temp;
                        first = temp;
                    }
                    else {
                        firstHead = first = temp;
                    }
                }
                else {
                    cout << "Invalid Number";
                    return;
                }
            }

            for (auto i: num2) {
                int val = i - '0';
                if (val < 10) {
                    Node* temp = new Node(val);
                    if (second) {
                        second->next = temp;
                        second = temp;
                    }
                    else {
                        secondHead = second = temp;
                    }
                }
                else {
                    cout << "Invalid Number";
                    return;
                }
            }            
            cout << "Addition Result: ";
            printList(addTwoLists(firstHead, secondHead));
            cout << endl;
            clearNode(firstHead);
            clearNode(secondHead);
        }
        
        void multiply() {
            string num1, num2;
            cout << "Enter First Number: ";
            cin >> num1;
            cout << "Enter Second Number: ";
            cin >> num2;
            Node *firstHead = nullptr, *secondHead = nullptr;
            Node *first = nullptr, *second = nullptr;
            for (auto i: num1) {
                int val = i - '0';
                if (val < 10) {
                    Node* temp = new Node(val);
                    if (first) {
                        first->next = temp;
                        first = temp;
                    }
                    else {
                        firstHead = first = temp;
                    }
                }
                else {
                    cout << "Invalid Number";
                    return;
                }
            }

            for (auto i: num2) {
                int val = i - '0';
                if (val < 10) {
                    Node* temp = new Node(val);
                    if (second) {
                        second->next = temp;
                        second = temp;
                    }
                    else {
                        secondHead = second = temp;
                    }
                }
                else {
                    cout << "Invalid Number";
                    return;
                }
            }            
            cout << "Multiplication Result: ";
            printList(multiplyTwoLists(firstHead, secondHead));
            cout << endl;
            clearNode(firstHead);
            clearNode(secondHead);
        }
};

int main() {
    LinkedList* calculation;
    int choice;

    while (true) {
        cout << "Choose an operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Multiplication" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                calculation->add();
                break;
            case 2:
                calculation->multiply();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
