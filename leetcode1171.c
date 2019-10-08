// 链表测试
 #include <bits/stdc++.h>
 using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head->next == NULL) {
            if (head->val == 0) return NULL;
            return head;
        }
        ListNode *Head = new ListNode(1);
        Head->next = head;
        ListNode *p = Head;
        int sum = 0;
        map<int, ListNode *> tmap;
        while (p != NULL) {
            sum += p->val;
            if (tmap[sum] == NULL) { 
                tmap[sum] = p;
                p = p->next;
            } else {
                ListNode *cur = tmap[sum];
                ListNode *end = p->next;
                int tsum = sum;
                while (cur->next != end) {
                    ListNode *temp = cur->next;
                    cur->next = cur->next->next;
                    sum += temp->val;
                    if (tsum != sum) {
                        tmap.erase(sum);
                    }
                    delete temp;
                }
                p = cur->next;
            }
        } 
        return Head->next;  
        
    }
};

int main () {
    int a[] = {1,2,3,-3,-2};
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for (int i = 1; i < 5;++i) {
        p->next = new ListNode(a[i]);
        p = p->next;
        cout << p->val<<endl;
    }
    Solution s;
    ListNode *res = s.removeZeroSumSublists(head);
    while (res!=NULL) {
        cout << res->val<< " ";
        res =res->next;
    }
    cout<<endl;
    cout << INT_MIN <<endl;
    return 0;

}