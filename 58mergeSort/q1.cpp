/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node * findMid(node* head){
    node * slow = head;
    node * fast = head-> next ; 
    
    while(fast != NULL && fast ->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}

node * merge(node * &left , node * &right ){
    
    if(left == NULL )
    {
        return right ;
    }
    if(right == NULL )
    {
        return left; 
    }
    
    node * ans = new node(-1);
    node * temp = ans ; 
    
//     merge 2 sorted linked list 
    while(left != NULL && right != NULL ){
        if(left -> data < right -> data ){
            temp-> next = left;
            temp = left; 
            left = left -> next ; 
            
        }
        else
        {
            temp-> next = right ; 
            temp = right ; 
            right = right -> next;
        }
    }
    while(left != NULL )
    {
        temp-> next = left;
        temp = left; 
        left = left -> next ; 
    }
    while(right != NULL )
    {
         temp-> next = right ; 
         temp = right ; 
         right = right -> next;
    }
    
    ans = ans -> next ; 
    return ans ;
}


node* mergeSort(node *head) {
    // base case
    if(head == NULL || head-> next == NULL)
    {
        return head;
    }
    
//     recursive for linked list mid with fast and slow
    node* mid = findMid(head);
    
    node* left = head ; 
    node* right = mid -> next ; 
    mid->next = NULL ; 
    
//     sorting with recursive calls for both halfs
    left = mergeSort(left);
    right = mergeSort(right);
    
//  merge both 
    node * result = merge(left, right);
    
    return result ; 
}
