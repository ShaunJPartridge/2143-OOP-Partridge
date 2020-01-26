///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Shaun Partridge
// Email:            spartridgeb15@gmail.com
// Label:            A02
// Title:            Linked List Class
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//       This program implements a linked list class that will imitate the use of an array.
//       It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" and "-" signs allowing a user to "add"
//       or "push" items onto the end of the list, as well as "pop" items off the end of the
//       list.
//
// Usage:
//       This program will create three linked lists. Two of which will be
//       combined to create the third or final list.
//
// Files: 
//      main.cpp    : driver of program
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


using namespace std;



int A[100]; // Declaring an array that holds up to 100 integers.


/**
 * Node
 *
 * Description:
 *      This struct will contain an integer along with a pointer that will connect
 *      each node in the Linked List together.
 *      This struct will also include a constructor and default constructor.
 *
 * Public Methods:
 *                          Node()
 *                          Node(int)
 *
 * Private Methods:
 *      None
 *
 * Usage:
 *
 *      Node()              // Default constructor that initializes a Node 
 *      Node(int)           // Overloaded constructor that initializes a Node
 *                          //    with an integer.
 *
 */
struct Node

{

    int x; // Represents a node's data

    Node* next; // Represents node pointer "next"

    /**
     * Constructor : Node
     *
     * Description:
     *      Initializes the variables x to -1 and next to NULL.
     *
     * Params:
     *      None
     *
     * Returns:
     *      None
     */
    Node()  

    {

        x = -1;         // x starts at -1

        next = NULL;    // The address 0000 or NULL is stored in next

    }

    /**
     * Overloaded Constructor : Node
     *
     * Description:
     *      Initializes a Node with an integer
     *
     * Params:
     *      int     :  Can be any integer number
     *
     * Returns:
     *      None
     */
    Node(int n)

    {

        x = n; // x gets the value of n.

        next = NULL;

    }

};


/**
 * List
 *
 * Description:
 *      Description of your class and what it does
 *
 * Public Methods:          
 *                          List()
 *      void                Push(int val)
 *      void                Insert(int val)
 *      void                PrintTail()
 *      string              Print()
 *      int                 Pop()
 *      List                operator+(const List& Rhs)
 *      int                 operator[](int index)
 *      friend              ostream& operator<<(ostream& os, List L)
 *
 * Private Methods:
 *      None
 *
 * Usage:
 *
 *      List L;              // Create instance of List
 *      L.Push(7);           // Pushes a 7 onto the rear of the list
 *      L.Push(8);           // Pushes a 8 onto the rear of the list
 *      L.Print();           // Prints out the list L, which is 7->8->
 *      L.PrintTail();       // Prints out the "Tail" of the list, which is 8
 *      List L3 = L1 + L2;   // Combines lists L1 and L2 to create list, L3
 *      cout << L3[5] << endl; // Gets the sixth element of the linked list
 *
 */
class List

{

private:

    Node* Head; // Pointer for the "Head" of the list.

    Node* Tail; // Pointer for the Tail of the list.

    int Size; // The size of the array. 



public:

    /**
     * Constructor  :  List 
     *
     * Description:
     *      Initializes the data members of the List class.
     *
     * Params:
     *      none
     *
     * Returns:
     *      none
     */
    List()

    {

        Head = Tail = NULL; // Head and Tail pointers' addresses are initialized
                                    // to NULL.
        Size = 0;                   // Array's Size is initialized to 0.

    }


    /**
     * Public : Push
     *
     * Description:
     *      Rear loads integers onto a linked list.

     * Params:
     *      int     :  an integer value
     *
     * Returns:
     *      void
     */
    void Push(int val)

    {

        // allocate new memory and init node

        Node* Temp = new Node(val);



        if (!Head && !Tail)         // If the linked list empty then,

        {

            Head = Tail = Temp;     // Temp is the first node of the linked list.

        }

        else                        // Else the linked list is not empty.

        {

            Tail->next = Temp;      // Tail->next gets the address of the new
                                    // node, Temp.
            Tail = Temp;            // The new Tail is now Temp.

        }

        Size++;                     // Increment Size

    }


    /**
     * Public : Insert
     *
     * Description:
     *     Front loads integers onto a linked list.
     *
     * Params:
     *      int     :  an integer value
     *
     * Returns:
     *      void
     */
    void Insert(int val)

    {

        // allocate new memory and init node

        Node* Temp = new Node(val);



        // figure out where it goes in the list



        Temp->next = Head;  // Temp->next gets the address of the old Head.

        Head = Temp;        // Temp is now the new Head of the list.

        if (!Tail)          // If the list is empty or Tail == NULL,

        {

            Tail = Head;    // then Tail is the Head of the list.
        }

        Size++;             // Increment Size

    }


    /**
     * Public : PrintTail
     *
     * Description:
     *      Prints out the Tail of the linked list.
     *
     * Params:
     *      none
     *
     * Returns:
     *      void
     */
    void PrintTail()

    {

        cout << Tail->x << endl;    // Prints out the value of the Tail node.

    }


    /**
     * Public : Print
     *
     * Description:
     *      Loops through a linked list, while simultaneously being turned into
     *      into a string. This string will represent the linked list and be 
     *      returned to be printed.
     *
     * Params:
     *      none
     *
     * Returns:
     *      string     :  a string that represents a linked list
     */
    string Print()

    {

        Node* Temp = Head;      // Initialize Temp to Head.

        string list;            // Declaring list variable that will have
                                // the linked list stored in it.

        while (Temp != NULL)    // Loops until it reaches the end of the list
                                // or NULL.
        {
                                               // list will be a linked list
            list += to_string(Temp->x) + "->"; // in the form of a string.
                                               
            Temp = Temp->next;                 // Go to the next node.

        }



        return list;             // Returns the linked list, which in this case
                                 // is a string.
    }



    // not implemented 

    int Pop()

    {

        Size--;

        return 0; //

    }


    /**
     * Public : operator+
     *
     * Description:
     *      Uses a linked list that is stored in memory already
     *      and combine it with another linked list to create
     *      a final linked list.
     *
     * Params:
     *      const List&     :  a linked list that is already in memory
     *
     * Returns:
     *      List     :  a final linked list of the two combined linked lists.
     */
    List operator+(const List& Rhs)

    {

        // Create a new list that will contain both when done

        List NewList;



        // Get a reference to beginning of local list

        Node* Temp = Head;



        // Loop through local list and Push values onto new list

        while (Temp != NULL)        // Loops until it hits the end of the list.

        {

            NewList.Push(Temp->x);  // Pushes a new value onto the list.

            Temp = Temp->next;      // Walks down the list until the loop 
                                    // terminates.
        }



        // Get a reference to head of Rhs

        Temp = Rhs.Head;



        // Same as above, loop and push

        while (Temp != NULL)        // Loops until it hits the end of the list.

        {

            NewList.Push(Temp->x);  // Pushes more new values onto the list.

            Temp = Temp->next;      // Walks down the list until the loop 
                                    // terminates.
        }



        // Return new concatenated version of lists

        return NewList;

    }

    /**
     * Public : operator[]
     *
     * Description:
     *      This function implements the [] operator and
     *      returns an integer value as if it were an array.
     *
     * Params:
     *      int     :  a integer that represents an index value of an array.
     *
     * Returns:
     *      int     :  a integer that is now in an array.
     */
    int operator[](int index)

    {

        Node* Temp = Head;     // Temp pointer initialized to Head of linked list.



        if (index >= Size)     // If the index value is greater than or equal to Size,

        {

            cout << "Index out of bounds, exiting";

            exit(0);           // then exit the code.

        }

        else
            // Else, the index value is less than Size and executes the following code: 
        {



            for (int i = 0; i < index; i++)

            {

                Temp = Temp->next; // Links each node together in the linked list.

            }

            return Temp->x;        // Returns the node's data.

        }

    }


    /**
     * Public : operator<<
     *
     * Description:
     *      "Friend" of the class to gain access to its data members
     *       and overloads the "<<" operator to print out the linked list.
     *
     * Params:
     *      ostream&   :  referenced ostream file
     *      List       :  an instance of a linked list
     *
     * Returns:
     *      ostream&   : the printed linked list from Print().
     */
    friend ostream& operator<<(ostream& os, List L)

    {

        os << L.Print(); // Calling Print() to override the operator and print
                            // out a linked list.
        return os;          // Returns a printed linked list.

    }

};



int main(int argc, char** argv)

{
            // Create instances of List for two lists.
    List L1;

    List L2;



    for (int i = 0; i < 25; i++) // Numbers 0-24 will be pushed onto list L1.

    {

       L1.Push(i);                 // Adds integers to the rear of L1.

    }



    for (int i = 50; i < 100; i++) // Numbers 50-99 will be pushed onto list L2.

    {

        L2.Push(i);                 // Adds integers to the rear of L2.

    }



    //cout << L1 << endl;

    L1.PrintTail();                 // Prints out the tail of L1.

    L2.PrintTail();                 // Prints out the tail of L2.


                                // Create another instance of List for L3.
    List L3 = L1 + L2;              // Combines lists L1 and L2 to make list L3.

    cout << L3 << endl;             // Prints out the final combined list.



    cout << L3[5] << endl;          // Prints out the sixth element of the list
                                    // which is 5.
    return 0;

}
