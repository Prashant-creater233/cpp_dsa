#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
//         int count = 0;

//         //check if nodes exixt
//         while(count < k) {
//             if(temp == NULL) {
//                 return head;
//             }
//             temp = temp->next;
//             count++;
//         }

//         //recursively call for rest of LL
//         ListNode* prevNode = reverseKGroup(temp, k);

//         //reverse current group
//         temp = head; count = 0;
//         while(count < k) {
//             ListNode* next = temp->next;
//             temp->next = prevNode;
//             prevNode = temp;
//             temp = next;

//             count++;
//         }

//         return prevNode;
//     }
// };