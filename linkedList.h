#include <iostream>
using namespace std;

struct node //declaring node
{
    int data;
    struct node *next;
};

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
    private:
        node *start;
};