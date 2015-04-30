//Andrew Lee and Andrew Lim
//This is the final working version
#include <iostream>
#include "linkedList.h"
using namespace std;

int main() // main that contains the menu
{
    string stringChoice;
    int choice;
    int nodes;
    int element;
    int position;
    int i;
    singleLinkedList sl;
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
        getline(cin, stringChoice);
        choice = atoi(stringChoice.c_str());
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
            return 0;
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}