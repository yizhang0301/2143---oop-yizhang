   /**
     *  Course: CMPS 2143 - OOP
     *
     *  Purpose: Calculate the total of 6 checks
     * 
     *  @author @author Terry Griffin ; YI ZHANG
     *  @version 1.1 09/02/18 
     */
#include <iostream>

using namespace std;

int A[100];
//creat data structure —— node
struct Node
{
    //int a value x
    int x;
    //use it as a pointer
    Node *next;
    //created a constructor for the Node type
    Node()
    {
        //make x be -1 if not change it will  no reference to next
        x = -1;
        next = NULL;
    }
    //This is a constructor to int value
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};
//class list
//to make a list of linked to hold integers

class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
    // empty the fuction and first being declared
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }
// to put value to the end of list
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);
    //check empty or not and add to temp if not empty list it to the end
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
//to put value to the top of list
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
//print the value from the last of the list
    void PrintTail()
    {
        cout << Tail->x << endl;
    }

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
    //remove the value from the list
    int Pop()
    {
        Size--;
        return 0; //
    }
// to creat a new list to connect L1 and L2
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
//L1
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }
//L2
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
