#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class compare
{
public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return a->data > b->data;
    }
};
Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{
    priority_queue<Node<int> *, vector<Node<int> *>, compare> minHeap;

    int k = listArray.size();

    if (k == 0)
        return NULL;
    // step 1:
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    // while not empty
    while (minHeap.size() > 0)
    {
        Node<int> *top = minHeap.top();
        minHeap.pop();
        // cases

        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }

        if (head == NULL)
        {
            // answer LL is empty
            head = top;
            tail = top;
        }
        else
        {
            // insert at end
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
