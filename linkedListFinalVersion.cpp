//Andrew Lee and Andrew Lim
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node //declaring node
{
    int data;
    struct node *next;
}*start;


class singleLinkedList //declaring class
{
    public:
        node* createNode(int);
        void insertNodeBeginning();
        void insertNodePosition();
        void insertNodeLast();
        void deleteNode();
        void sort();
        void search();
        void update();
        void reverse();
        void display();
        singleLinkedList()
        {
            start = NULL;
        }
};


int main() // main that contains the menu
{
    int choice;
    int nodes;
    int element;
    int position;
    int i;
    singleLinkedList sl;
    start = NULL;
    while (1)
    {
        cout<<endl<<"================================="<<endl;
        cout<<endl<<"Welcome to Linked List Land"<<endl;
        cout<<endl<<"================================="<<endl;
        cout<<"1.Insert a node at the beginning"<<endl;
        cout<<"2.Insert a node at the end"<<endl;
        cout<<"3.Insert a node at a certain position"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Delete a Particular Node"<<endl;
        cout<<"6.Update a Node Value"<<endl;
        cout<<"7.Search Element"<<endl;
        cout<<"8.Show My Linked List"<<endl;
        cout<<"9.Reverse My Linked List "<<endl;
        cout<<"10.Exit "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        //
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            sl.insertNodeBeginning();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            sl.insertNodeLast();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            sl.insertNodePosition();
            cout<<endl;
            break;
        case 4:
            cout<<"Sort Link List: "<<endl;
            sl.sort();
            cout<<endl;
            break;
        case 5:
            cout<<"Delete a particular node: "<<endl;
            sl.deleteNode();
            break;
        case 6:
            cout<<"Update Node Value:"<<endl;
            sl.update();
            cout<<endl;
            break;
        case 7:
            cout<<"Search element in Link List: "<<endl;
            sl.search();
            cout<<endl;
            break;
        case 8:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 9:
            cout<<"Reverse elements of Link List"<<endl;
            sl.reverse();
            cout<<endl;
            break;
        case 10:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}

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
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
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
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
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
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *tmp, *s, *ptr;
    tmp = createNode(value);
    cout<<"Enter the position at which the node will be inserted: ";
    cin>>pos;
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
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
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
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the node position to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
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
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
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
