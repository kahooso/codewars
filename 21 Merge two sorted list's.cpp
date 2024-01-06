#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    /* same as
            ListNode() {
            this->val = 0;
            this->next = nullptr;
        }

        ListNode(int x) {
            this->val = x;
            this->next = nullptr;
        }

        ListNode(int x, ListNode* next) {
            this->val = x;
            this->next = next;
        }
    */
    void show() {
        std::cout << "new list!" << std::endl;
        ListNode* temp = this;
        while (temp != nullptr) {
            std::cout << "val = " << temp->val << std::endl;
            temp = temp->next;
        }
    }
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) { return list2; }
        if (list2 == nullptr) { return list1; }
        ListNode* temp_list = list1;
        int size_counter = 0;
        while (temp_list->next != nullptr) {
            temp_list = temp_list->next;
        }
        temp_list->next = list2;
        bubbleSort(list1);
        return list1;
    }

    void swap(ListNode* a, ListNode* b) {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    void bubbleSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return; }
        ListNode* ptr;
        bool swapped;
        do {
            swapped = false;
            ptr = head;
            while (ptr->next != nullptr) {
                if (ptr->val > ptr->next->val) {
                    swap(ptr, ptr->next);
                    swapped = true;
                }
                ptr = ptr->next;
            }
        } while (swapped);
    }
};

int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(5);
    a->next->next->next = new ListNode(6);


    ListNode* b = new ListNode(90);
    b->next = new ListNode(54);
    b->next->next = new ListNode(52);
    b->next->next->next = new ListNode(-6);

    a->show();
    b->show();

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(a, b);
    merged->show();
}