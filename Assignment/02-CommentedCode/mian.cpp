///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           YI ZHANG
// Email:            zy19950301@126.com
// Label:            02-CommentedCode
// Title:            Commenting c++ code
// Course:           2143-OOP
// Semester:         Spring 2020
//
// Description:
//       The test about linked list and overloaded operators.
//
// Usage:
//       
//
// Files:  main.cpp          
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];
struct Node
{
    int x;
    Node *next;
    //default constructor
    Node()
    {
        x = -1;
        next = NULL;
    }
    //constructor with specified number
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      Class use different way to perform on list
 * 
 * Public Methods:
 *      - void push
 *      - void insert
 *      - void printTail
 *      - void print
 *      - int pop
 * Private Methods:
 *      NONE
 * 
 * Usage: 
 * 
 *      list List1
 *      list1.push(4);
 *      list1.print():
 *      
 */
class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }
/**
 * Push
 * Description:
 *     Adds an integer value to the list 
 *
 * Params:
 *     int val  : int a value to be added
 *
 * Returns:
 *     
 */
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }
/**
 * Public : Insert
 * 
 * Description:
 *      integer a value in the list
 * 
 * Params:
 *      - int val
 *      value to be added to the list
 * 
 * Returns:
 *      
 */
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
 /**
  * Public : PrintTail
  * 
  * Description:
  *      Print value at the end
  * 
  * Params:
  *      
  * 
  * Returns:
  *    
  */
    void PrintTail()
    {
        cout << Tail->x << endl;
    }
/**
 * Public: Print
 *
 * Description:
 *      Prints the contents of the list
 * 
 * Params:
 *
 *     Void
 *
 * Returns:
 *
 *     List      :  a linked list 
 */
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented 
 /**
 * Pop
 * Description:
 *     Removes a value from the list
 * Params:
 *     
 * Returns:
 *    int      : int value
 */
    int Pop()
    {
        Size--;
        return 0; //
    }
/**
 * Public : operator+
 * 
 * Description:
 *      connect two lists
 * 
 * Params:
 *      - const list &Rhs
 *      
 * 
 * Returns:
 *      - List: a new list
 * 
*/
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
 /**
  * Public : operator[]
  * 
  * Description:     
  *      int value to the list in an array.
  * 
  * Params:int index
  * Returns: int: index         
  */    
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;
    List L2;

    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
