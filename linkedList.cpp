#include <iostream>
#include "linkedList.h"
using namespace std;
/*
 * Creates a new node to add to the empty list
 * Precondition: none
 * Postcondition: new node will be created
 */
node *singleLinkedList::createNode(int value)
{
    struct node *tmp, *s;
    tmp = new(struct node);
    if (tmp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        tmp->data = value;
        tmp->next = NULL;
        return tmp;
    }
}

/*
 * User can insert a node at the beginning of the list
 * Precondition: There can be an already existing list or no list at all
 * Postcondition: a new node will be inserted into the beginning of the list
 */
void singleLinkedList::insertNodeBeginning()
{
    string stringValue;
    cout<<"Enter the value to be inserted: "<<endl;
    getline(cin, stringValue);
    if(stringValue.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]\{}|;':,./<>?") == string::npos)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    int value = atoi(stringValue.c_str());
    struct node *tmp, *p;
    tmp = createNode(value);
    if (start == NULL)
    {
        start = tmp;
        start->next = NULL;
    }
    else
    {
        p = start;
        start = tmp;
        start->next = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
}

/*
 * User can insert a node at the end of the list
 * Precondition: There can be an already existing list or no list at all
 * Postcondition: a new node will be inserted to the end of the list
 */
void singleLinkedList::insertNodeLast()
{
    string stringValue;
    cout<<"Enter the value to be inserted: "<<endl;
    getline(cin, stringValue);
    if(stringValue.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]\{}|;':,./<>?") == string::npos)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    int value = atoi(stringValue.c_str());
    struct node *tmp, *s;
    tmp = createNode(value);
    s = start;
    while (s->next != NULL)
    {
        s = s->next;
    }
    tmp->next = NULL;
    s->next = tmp;
    cout<<"Element Inserted at last"<<endl;
}

/*
 * User can insert a node in a desired position.
 * Precondition: the value that is entered for the position must be in range
 * Postcondition: node will be added to nth position in linked list
 */
void singleLinkedList::insertNodePosition()
{
    int value, pos, counter = 0;
    string stringPos;
    string stringValue;
    cout<<"Enter the value to be inserted: "<<endl;
    getline(cin, stringValue);
    if(stringValue.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]\{}|;':,./<>?") == string::npos)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    value = atoi(stringValue.c_str());
    struct node *tmp, *s, *ptr;
    tmp = createNode(value);
    cout<<"Enter the position at which the node will be inserted: "<<endl;
    getline(cin, stringPos);
    if(stringPos.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]\{}|;':,./<>?") == string::npos)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    pos = atoi(stringPos.c_str());
    int i;
    s = start;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = tmp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = tmp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = tmp;
        tmp->next = s;
    }
    else
    {
        cout<<"Position out of range"<<endl;
    }
}

/*
 * User can organize their list from lowest to highest in value
 * Precondition: there must be a linked list
 * Postcondition: linked list will go from lowest value to highest value
 */
void singleLinkedList::sort()
{
    struct node *ptr, *s;
    int value;
    if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->data > s->data)
            {
                value = ptr->data;
                ptr->data = s->data;
                s->data = value;
            }
        }
        ptr = ptr->next;
    }
}

/*
 * Delete element at a given position
 * Precondition: there needs to be a linked list in the first place
 * Postcondition: element at the prompted position will be deleted
 */
void singleLinkedList::deleteNode()
{
    int pos, i, counter = 0;
    string stringPos;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    getline(cin, stringPos);
    if(stringPos.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]\{}|;':,./<>?") == string::npos)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    pos = atoi(stringPos.c_str());
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element Deleted"<<endl;
    }
}

/*
 * User can change the value of a node at a certain position
 * Precondition: a list must exist and the position of the node must be in range of list
 * Postcondition: value of node in nth position will change to new value
 */
void singleLinkedList::update()
{
    int value, pos, i;
    string stringPos;
    string stringValue;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the node position to be updated: "<<endl;
    getline(cin, stringPos);
    if(stringPos.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]\{}|;':,./<>?") == string::npos)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    pos = atoi(stringPos.c_str());
    cout<<"Enter the new value: "<<endl;
    getline(cin, stringValue);
    if(stringValue.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]\{}|;':,./<>?") == string::npos)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    value = atoi(stringValue.c_str());
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->data = value;
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"There are less than "<<pos<<" elements";
                return;
            }
            s = s->next;
        }
        s->data = value;
    }
    cout<<"Node Updated"<<endl;
}

/*
 * Searches for a certain element/value in the list
 * Precondition: a list must exist
 * Postcondition: User will be told whether or not the value is in the list and if it is, what position it's in
 */
void singleLinkedList::search()
{
    int value, pos = 0;
    bool flag = false;
    string stringValue;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: "<<endl;
    getline(cin, stringValue);
    if(stringValue.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]\{}|;':,./<>?") == string::npos)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    value = atoi(stringValue.c_str());
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->data == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;
}

/*
 * Reverses the linked list
 * Precondition: list must exist
 * Postcondition: linked list that the user created will be reversed
 */
void singleLinkedList::reverse()
{
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (start->next == NULL)
    {
        return;
    }
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
    }
    start = ptr2;
}

/*
 * Display Elements of a link list
 * Precondition: list must exist
 * Postcondition: currently built list will be displayed
 */
void singleLinkedList::display()
{
    struct node *tmp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    tmp = start;
    cout<<"Elements of list are: "<<endl;
    while (tmp != NULL)
    {
        cout<<tmp->data<<"->";
        tmp = tmp->next;
    }
    cout<<"NULL"<<endl;
}
