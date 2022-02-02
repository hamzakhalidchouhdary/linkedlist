#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node
{
    int data;
    node *ptr;
    ~node()
    {
        cout << "node has been deleted" << endl;
    }
};
class linkedList
{
    node *head, *newlink, *templink;
public:
    linkedList()
    {
        head = newlink = templink = NULL;
    }
    void newNode()
    {
        newlink = (node *)(malloc(sizeof(node)));
        newlink->data = rand()%50;
        newlink->ptr = NULL;
    }
    void linkNodes()
    {
        newNode();
        if(head == NULL)
        {
            head = newlink;
        }
        else
        {
            templink = head;
            while(templink->ptr != NULL)
                templink = templink->ptr;
            templink->ptr = newlink;
        }
    }
    void treversLinkedList()
    {
        templink = head;
        cout << "linked list data : ";
        while(templink != NULL)
        {
            if(templink->data < 10)
                cout << "0" << templink->data << " ";
            else
                cout << templink->data << " ";
            templink = templink->ptr;
        }
    }
    void deleteNode(int item)
    {
     //   head = deleteNode(item,head);
        node *prev = NULL;
        templink = head;
        while(templink != NULL)
        {
            if(templink->data == item && templink == head)
            {
                head = templink->ptr;
                free(templink);
            }
            else if(templink->data == item && templink->ptr == NULL)
            {
                prev->ptr = NULL;
                free(templink);
            }
            else if(templink->data == item)
            {
                prev->ptr = templink->ptr;
                free(templink);
            }
            else{}
            prev = templink;
            templink = templink->ptr;
        }
    }
    node* deleteNode(int item, node* temp)
    {
        node *nextPtr = temp->ptr;
        if(temp->data == item && temp != NULL)
        {
            free(temp);
        }
        temp->ptr = deleteNode(item, nextPtr);
        return nextPtr;
    }
    void deleteList()
    {
        deleteList(head);
    }
    void deleteList(node *temp)
    {
//        if(temp->ptr != NULL)
//        {
//            deleteList(temp->ptr);
//        }
//        delete temp;
        node *prev;
        while(temp != NULL)
        {
            prev = temp;
            temp = temp->ptr;
            delete prev;
        }
    }


};
int main()
{
    srand(time(0));
    linkedList obj;
    for(int i=0;i<10;i++)
    {
        obj.linkNodes();
    }
    obj.treversLinkedList();
    obj.deleteList();
    cout << endl;
//    int item;
//    cin >> item;
//    obj.deleteNode(item);
    obj.treversLinkedList();
    getch();
    main();
    return 0;

}
