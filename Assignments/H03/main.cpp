///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Shaun Partridge
// Email:            spartridgeb15@gmail.com
// Label:            H03
// Title:            Linked List Class
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//       This program implements a templated vector class that will allow us to use
//       any type of data we wish to use. This class consists of methods that will
//       allow the linked list to imitate the use of an array. It overloads the "[]" 
//       (square brackets) to simulate accessing seperate array elements, but really
//       it traverses the list to find the specified node using an index value. It
//       also overloads the "+" and "-" signs allowing a user to "add" or "push" items
//       onto the end of the list, as well as "pop" items off the end of the list.
//       This program also implements a templated node struct, that overloads the 
//       comparison operators, which will allow us to compare nodes directly instead 
//       of comparing their data.
//
// Usage:
//       This program will create three vectors. Two vectors will be the same size and 
//       the other will be larger. The smaller vector will then be sorted in ascending
//       order.
// Files: 
//      main.cpp    : driver of program
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


using namespace std;

// Our previous node was not templated it only
// held integers. By

/**
 * Node
 *
 * Description:
 *      This struct is templated, meaning that it will contain whatever data 
 *      type we want it to hold along with a pointer that will connect
 *      each node in the Linked List together. This struct will also include 
 *      a constructor, default constructor and methods for overloading the 
 *      assignment and comparison operators.
 *
 * Public Methods:
 *                          Node()
 *                          Node(T d)
 *      ostream&            friend operator<<(ostream& os, const Node& obj)
 *      void                operator=(const Node& obj)
 *      bool                operator<(const Node& rhs)
 *      bool                operator>(const Node& rhs)
 *      bool                operator==(const Node& rhs)
 *      bool                operator!=(const Node& rhs)
 *      
 * Private Methods:
 *      None
 *
 * Usage:
 *
 *      Node()              // Default constructor that initializes a Node 
 *      Node(T d)           // Overloaded constructor that initializes a templated
 *                          // Node with whatever data type we want.
 *          Ex.) Node<int>* N1 = new Node<int>(34);
 *               Node<int>* N2 = new Node<int>(50);
 *
 *      cout << N1 << endl;  // Prints out the value 34
 *      N1 = N2;            // N1 now has the value of 50
 *      N1 < N2;             // Compares the nodes' data and results in true
 *      N1 > N2;             // Compares the nodes' data and results in false
 *      N1 == N2;            // Compares the nodes' data and results in false
 *      N1 != N2;            // Compares the nodes' data and results in true
 *
 */
template <typename T>
struct Node {
    T data;             // Now data will be whatever "T" is.
    
    Node* next;         // Declaring next and prev pointers
    Node* prev;
    
    /**
     * Constructor  :  Node 
     *
     * Description:
     *      Initializes the data members of the MyVector class.
     *
     * Params:
     *      none
     *
     * Returns:
     *      none
     */
    Node() { next = prev = NULL; } 

       
    
    /**
     * Overloaded Constructor  :  Node 
     *
     * Description:
     *      Initializes the data members of the MyVector class.
     *
     * Params:
     *      T d     :  d is whatever type "T" is
     *
     * Returns:
     *      none
     */
    Node(T d) { 
        data = d;
        next = prev = NULL;
    }
    
     /**
     * Public  :  friend operator<<
     *
     * Description:
     *      The "friend" keyword gives one class access to the
     *      private and protected components of another class.
     *      This overloads the "<<" operator allowing us to send
     *      the node "data" straight to the output stream.
     *
     * Params:
     *      ostream& os     :  an output file
     *      const Node&     :  a Node object
     *
     * Returns:
     *      ostream&        :  an os object that prints the Node's data
     */
    friend ostream& operator<<(ostream& os, const Node& obj) {

        return os << "[" << obj.data << "]";

    }
    
    /**
     * Public  :  operator=
     *
     * Description:
     *      This overloads the assignment (=) operator allowing us 
     *      to assign the value of one Node to another.
     *
     * Params:
     *      const Node&     :  a Node object
     *
     * Returns:
     *      void
     */
    void operator=(const Node& obj) {

        this->data = obj.data;

    }

    
    /**
     * Public  :  operator<
     *
     * Description:
     *      This overloads the less than (<) operator allowing us to 
     *      compare two nodes' "data" directly.
     *
     * Params:
     *      const Node&     :  a Node object
     *
     * Returns:
     *      bool            :  either returns true or false
     */
    bool operator<(const Node& rhs) {
        return this->data < rhs.data;
    }

    /**
     * Public  :  operator>
     *
     * Description:
     *      This overloads the greater than (>) operator allowing us to
     *      compare two nodes' "data" directly.
     *
     * Params:
     *      const Node&     :  a Node object
     *
     * Returns:
     *      bool            :  either returns true or false
     */
    bool operator>(const Node& rhs) {
        return this->data > rhs.data;
    }

    /**
     * Public  :  operator==
     *
     * Description:
     *      This overloads the equal to (==) operator allowing us to 
     *      compare twos nodes' "data" directly.
     *
     * Params:
     *      const Node&     :  a Node object
     *
     * Returns:
     *      bool            :  either returns true or false
     */
    bool operator==(const Node& rhs) {
        return this->data == rhs.data;
    }

    /**
     * Public  :  operator!=
     *
     * Description:
     *      This overloads the not equal to (!=)  operator allowing us
     *      to compare twos nodes' "data" directly.
     *
     * Params:
     *      ostream& os     :  an output file
     *      const Node&     :  a Node object
     *
     * Returns:
     *      bool            :  either returns true or false
     */
    bool operator!=(const Node& rhs) {
        return this->data != rhs.data;
    }

};



// We need to also template the MyVector class because
// if the Node is templated, then the methods in this class
// need to be templated as well so the data types can
// change to match what we need our Node to store.

/**
 * MyVector
 *
 * Description:
 *      This MyVector class is templated as well, so that the
 *      data types can change to match what we need our Node
 *      to store.
 *
 * Public Methods:          
 *                          MyVector()
 *                          MyVector(const MyVector& obj)
 *      int                 Size()
 *      void                pushBack(T d)
 *      void                pushFront(T d)
 *      T                   popBack()
 *      T                   popFront()
 *      void                print()
 *      T&                  operator[](int index)
 *      ostream&            friend operator<<(ostream& os, const MyVector& obj)
 *      MyVector            operator+(const MyVector& lhs)
 *      void                Sort(bool asc = true)
 *      string              randString(int len)
 *
 * Private Methods:
 *      None
 *
 * Usage:
 *
 *      MyVector<int> V1;               // Create instance of MyVector, V1
 *      MyVector<int> V2(V1);           // Create another instance of MyVector,
 *                                      // V2 with V1's data
 *      cout << V1.Size();              // Prints out the vectors size
 *      V1.pushBack(8);                 // Pushes a 8 onto the rear of the vector
 *      V1.pushFront(4);                // Pushes a 4 onto the front of the vector
 *      L.Print();                  // Prints out the list L, which is 7->8->
 *      L.PrintTail();       // Prints out the "Tail" of the list, which is 8
 *      List L3 = L1 + L2;   // Combines lists L1 and L2 to create list, L3
 *      cout << L3[5] << endl; // Gets the sixth element of the linked list
 *
 */
template <class T>

class MyVector {

private:

    Node<T>* Head;  // Pointers need to know what type the node will

    Node<T>* Tail;  // be storing.

    int size;



public:
                            // Constructor for MyVector class
    MyVector() {

        Head = Tail = NULL; // Initailizing Head and Tail

        size = 0;           // Initializing Size

    }


    // This is a copy constructor.
    // A copy constructor receives an object of the
    // same type, and then makes a copy of the incoming
    // object.
    // For simple objects, the system can create a copy
    // constructor on the fly, by when dealing with dynamic
    // memory we should handle it ourselves. Look at the
    // readme file to see deep copy vs shallow copy
    
    MyVector(const MyVector& obj) {
        
        Head = Tail = NULL;
        size = 0;
        cout << "Copy Constructor\n";
        Node<T>* Temp = obj.Head;
        
        while (Temp) {
            this->pushBack(Temp->data);
            Temp = Temp->next;
        }

    }


    int Size() { return size; }


    // we replace every "int" from previous version
    // with a "T".

    void pushBack(T d) {

        Node<T>* temp = new Node<T>(d);



        if (Head == NULL) {

            Head = temp;

            Tail = temp;

        }
        else {

            Tail->next = temp;

            temp->prev = Tail;

            Tail = temp;

        }

        size++;

    }



    void pushFront(T d) {

        Node<T>* temp = new Node<T>(d);



        if (Head == NULL) {

            Head = temp;

            Tail = temp;

        }
        else {

            temp->next = Head;

            Head->prev = temp;

            Head = temp;

        }

        size++;

    }



    T popBack() {

        if (Tail) {

            int d = Tail->data;

            Node<T>* temp = Tail;

            Tail = Tail->prev;

            if (Tail) {

                Tail->next = NULL;

            }
            else {

                Head = NULL;

            }



            delete temp;



            size--;



            return d;

        }



        return -1;

    }



    T popFront() {

        if (Head) {

            T d = Head->data;

            Node<T>* temp = Head;

            Head = Head->next;

            if (Head) {

                Head->prev = NULL;

            }
            else {

                Tail = NULL;

            }



            delete temp;



            size--;



            return d;

        }

        return -1;

    }



    void print() {

        Node<T>* temp = Head;



        while (temp) {

            cout << temp->data;

            if (temp->next) {

                cout << "->";

            }

            temp = temp->next;

        }

        cout << endl;

    }



    // Again we overload the "<<" operator letting us print a vector

    // straight to the output stream instead of using a "print" function.

    friend ostream& operator<<(ostream& os, const MyVector& obj) {

        Node<T>* temp = obj.Head;



        while (temp) {

            os << "[";

            os << temp->data;

            os << "]";

            if (temp->next) {

                os << "->";

            }

            temp = temp->next;

        }



        return os;

    }



    // Overload the "[]" square brackets so we can treat our list

    // similar to an array. This will let us obtain a value from

    // any existing node, or update that nodes value by assigning it

    // a new one.

    T& operator[](int index) {

        if (index >= size) {

            cout << "Array index out of bound, exiting";

            exit(0);

        }

        Node<T>* temp = Head;

        for (int i = 0; i < index; i++) {

            temp = temp->next;

        }

        return temp->data;

    }



    // This is the "+" plus sign being overloaded to

    // concatenate two lists end to end returning a

    // third new list.

    MyVector operator+(const MyVector& lhs) {

        Node<T>* temp1 = Head;

        Node<T>* temp2 = lhs.Head;



        MyVector V;



        while (temp1) {

            V.pushBack(temp1->data);

            temp1 = temp1->next;

        }



        while (temp2) {

            V.pushBack(temp2->data);

            temp2 = temp2->next;

        }



        return V;

    }



    // The sort will still work??

    // It should as long as the "T" values are defined

    // to use comparison operators (we will discuss later).

    // For now types like float,string,int will all work.

    void Sort(bool asc = true) {//bool asc = true

        Node<T>* Start = Head;



        while (Start) {

            Node<T>* minp = Start; // Starting minimum position

            int minv = Start->data; // Starting minimum value

            Node<T>* mint = Start; // Node pointer that walks down list and compares 
                                   // its value with minv
            bool doSwap = 0; // doSwap = false



            while (mint) {  // While walking down the list

                if (asc) {  // If asc = true or going in ascending order
                    doSwap = (*mint < *minp);
                }

                else {
                    doSwap = (*mint > *minp);
                }

                if (doSwap) {
                    minp = mint;
                    minv = mint->data;
                }

                    mint = mint->next;
                
            
            }

            // swap

            minp->data = Start->data;

            Start->data = minv;

            Start = Start->next;

        }

    }

};



// Griffins cheap random string function

// only does all caps. You should fix it

// to do both upper and lowercase!

string randString(int len) {

    string s;

    for (int i = 0; i < len; i++) {

        s += char((rand() % 26) + 65);

    }

    return s;

}



// main driver to test our new templated vector class

int main() {
    
    // Instances of our MyVector class
    MyVector<int> V1;

    MyVector<int> V2;

    bool asc = true;
    
    // Loading both vectors with integers
    for (int i = 0; i < 10; i++) {

        V1.pushFront(rand() % 100);

    }



    for (int i = 0; i < 5; i++) {

        V2.pushFront(rand() % 100);

    }


    // Creating a third vector, V3, and copying V2's data into it
    MyVector<int> V3(V2);



    cout << V3.Size() << endl;

    cout << V2 << endl;
    
    V2.Sort(asc);   // Sorts vector, V2's data in ascending order
    
    cout << V2 << endl;

    cout << V3 << endl;



    V2[4] = 0;  // Puts the value 0, into the fifth element of V2



    cout << V2 << endl;

    cout << V3 << endl;


    /*
    MyVector<string> V4;

    MyVector<string> V5;


    
    for (int i = 0; i < 10; i++) {

        V4.pushFront(randString(8));

    }



    for (int i = 0; i < 5; i++) {

        V5.pushFront(randString(8));

    }



    cout << V4 << endl;

    cout << endl;

    cout << V5 << endl;
    */

    return 0;
}
