#include<iostream>
/*
没有头结点的链表，如何反转？

思路：

如果链表只有一个节点，那么直接返回该节点即可。  
如果链表有两个节点，那么先交换两个节点的位置，然后递归地对第二个节点的后半部分进行反转。  
如果链表有多个节点，那么先找到链表的中间节点，然后对前半部分进行反转，再对后半部分进行反转，
最后将前半部分和后半部分连接起来。
*/
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){};
};
//创建链表
ListNode* createList(){
    int input;
    cin>>input;
    if(input==-1)return NULL;//输入-1结束输入
    ListNode* head=new ListNode(input);
    ListNode* tail=head;
    while(cin>>input){
        if(input==-1)return head;//输入-1结束输入
        tail->next=new ListNode(input);
        tail=tail->next;
        
    }
    return head;
}
//打印输出链表
void printList(ListNode* head){
    cout<<"{"<<" ";
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"} "<<endl;
}
//反转链表
ListNode* ReverseList(ListNode* head) {
    // write code here
    if(head == nullptr || head->next == nullptr)return head;
    ListNode *pre = head, *mid = pre->next, *back = mid->next;
    while(back){
        mid->next = pre;
        pre = mid;
        mid = back;
        back = back->next;//负责往后遍历
    }
    mid->next = pre;//back是null时，需要再转置一次
    head->next = nullptr;
    return mid;

}
//递归反转链表方法
ListNode* ReverseList2(ListNode* head) {
    // write code here
    if(head == nullptr || head->next == nullptr)return head;
    // 递归调用反转剩余链表
    ListNode* newHead = ReverseList2(head->next);
    
    // 将当前节点的下一个节点的 next 指向当前节点
    head->next->next = head;
    
    // 将当前节点的 next 指向 nullptr
    head->next = nullptr;
    
    // 返回新的头节点
    return newHead;
}

int main(){
    ListNode* head=createList();
    printList(head);
    ListNode* newHead=ReverseList(head);
    printList(newHead);
    

    ListNode* newHead2 = ReverseList2(newHead);
    printList(newHead2);
    return 0;
}