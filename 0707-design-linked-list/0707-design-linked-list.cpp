class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    ListNode* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        ListNode* temp = head;
        int count = 0;

        while (temp != nullptr) {
            if (count == index)
                return temp->val;

            temp = temp->next;
            count++;
        }

        return -1;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        ListNode* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* temp = head;
        int count = 0;

        while (temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }

        // index greater than length
        if (temp == nullptr)
            return;

        ListNode* newNode = new ListNode(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {

        if (head == nullptr)
            return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* temp = head;
        int count = 0;

        while (temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp->next == nullptr)
            return;

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};