class Solution {
  public:
    Node *reverseFourLink(Node* head, Node* prev, int k)
    {
        Node* Head = head;
        Node* previous = nullptr;
        Node* current = head;
        
        while (head && k--)
        {
            head = head->next;
            current->next = previous;
            previous = current;
            current = head;
        }
        Head->next = head;
        if (prev)
            prev->next = previous;
        return previous;
    }
  
    Node *reverseKGroup(Node *head, int k) 
    {
        Node* temp = nullptr;
        Node* prevLink = nullptr;
        
        while (head)
        {
            if (temp == nullptr)
            {
                temp = reverseFourLink(head, prevLink, k);
            }
            else
            {
                reverseFourLink(head, prevLink, k);
            }
            prevLink = head;
            head = head->next;
        }
        
        return temp;
    }
};
