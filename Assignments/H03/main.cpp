

/*
      ___  ___  ________  ________                                                             
     |\  \|\  \|\   __  \|\_____  \                                                            
     \ \  \\\  \ \  \|\  \|____|\ /_                                                           
      \ \   __  \ \  \\\  \    \|\  \                                                          
       \ \  \ \  \ \  \\\  \  __\_\  \                                                         
        \ \__\ \__\ \_______\|\_______\                                                        
         \|__|\|__|\|_______|\|_______|                                                        
                                                                                               
                                                                                               
                                                                                               
       _______   _____  ___   ___  ________                                                    
      /  ___  \ / __  \|\  \ |\  \|\_____  \                                                   
     /__/|_/  /|\/_|\  \ \  \\_\  \|____|\ /_                                                  
     |__|//  / ||/ \ \  \ \______  \    \|\  \                                                 
         /  /_/__   \ \  \|_____|\  \  __\_\  \                                                
        |\________\  \ \__\     \ \__\|\_______\                                               
         \|_______|   \|__|      \|__|\|_______|                                               
                                                                                               
                                                                                               
                                                                                               
      ________  ________  ________  _________  ________  ___  ________  ________  _______      
     |\   __  \|\   __  \|\   __  \|\___   ___\\   __  \|\  \|\   ___ \|\   ____\|\  ___ \     
     \ \  \|\  \ \  \|\  \ \  \|\  \|___ \  \_\ \  \|\  \ \  \ \  \_|\ \ \  \___|\ \   __/|    
      \ \   ____\ \   __  \ \   _  _\   \ \  \ \ \   _  _\ \  \ \  \ \\ \ \  \  __\ \  \_|/__  
       \ \  \___|\ \  \ \  \ \  \\  \|   \ \  \ \ \  \\  \\ \  \ \  \_\\ \ \  \|\  \ \  \_|\ \ 
        \ \__\    \ \__\ \__\ \__\\ _\    \ \__\ \ \__\\ _\\ \__\ \_______\ \_______\ \_______\
         \|__|     \|__|\|__|\|__|\|__|    \|__|  \|__|\|__|\|__|\|_______|\|_______|\|________| 
                                                                                  
*/




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
//       of comparing their data. This program also creats random strings with both,
//       lowercase and uppercase letters.
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
     *      Initializes the data members of the Node struct.
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
     *      Initializes the data members of the Node struct.
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
     *      ostream& os     :  a output stream object
     *      const Node&     :  the node to be printed out
     *
     * Returns:
     *      ostream&        :  a output stream object with the Node's data
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
 *      
 *      cout << V1.Size();              // Prints out the vectors size
 *      V1.pushBack(8);                 // Pushes a 8 onto the rear of the vector
 *      V1.pushFront(4);                // Pushes a 4 onto the front of the vector
 *      MyVector<int> V2(V1);           // Create another instance of MyVector,
 *                                            // V2 with V1's data
 *
 *      int val = V1.popBack();         // Deletes 8 from the rear of the vector
 *                                            // and val gets the value of 8
 *
 *      val = V1.popFront();            // Deletes 4 from the front of the vector
 *                                            // and val gets the value of 4
 *
 *      V1.Print();                     // Prints out the vector, which is [4][8]
 *      V1[1] = 1;                      // Element 2 of V1 now has the value 1
 *      cout << V1 << endl;             // Prints out [4][1]
 *      V1 = V1 + V2;                   // Combine vectors V1 and V2, which makes
 *                                          V1 -> [4][1][4][8]
 *      V1.Sort(asc);                   // V1 is now [1][4][4][8]
 *
 */
template <class T>

class MyVector {

private:

    Node<T>* Head;  // Pointers need to know what type the node will
    Node<T>* Tail;  // be storing.

    int size;
    
public:
     
    /**
     * Constructor  :  MyVector 
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
    MyVector() {

        Head = Tail = NULL; // Initailizing Head and Tail

        size = 0;           // Initializing Size

    }

    /**
     * Copy Constructor  :  MyVector 
     *
     * Description:
     *      A copy constructor recieves an object of the same type,
     *      and then makes a copy of the incoming object. 
     *
     * Params:
     *      const MyVector& obj    :  a MyVector object to be copied
     *
     * Returns:
     *      none
     */
    MyVector(const MyVector& obj) {
        
        Head = Tail = NULL;     // Initializing variables
        size = 0;
        cout << "Copy Constructor\n";
        Node<T>* Temp = obj.Head;
        
        while (Temp) {          // Add nodes to vector
            this->pushBack(Temp->data);
            Temp = Temp->next;
        }

    }

    /**
     * Public  :  Size 
     *
     * Description:
     *      Returns the size of the vector
     *
     * Params:
     *      none
     *
     * Returns:
     *      int   :   the vectors size
     */
    int Size() { return size; }

     /**
     * Public  :  pushBack 
     *
     * Description:
     *      Adds a node to the rear of a vector
     *
     * Params:
     *      T d  :  d is whatever data type T is
     *
     * Returns:
     *      void
     */
    void pushBack(T d) {

        Node<T>* temp = new Node<T>(d);  //Initializing Node* temp

        if (Head == NULL) {     // If the vector is empty,
            Head = temp;        // temp is the Head and Tail
            Tail = temp;
        }
        else {                  // else add to the rear of the
            Tail->next = temp;  // vector
            temp->prev = Tail;
            Tail = temp;
        }

        size++;                 // Increment size
    }


     /**
     * Public  :  pushFront 
     *
     * Description:
     *      Adds a node to the front of a vector
     *
     * Params:
     *      T d  :  d is whatever data type T is
     *
     * Returns:
     *      void
     */
    void pushFront(T d) {

        Node<T>* temp = new Node<T>(d);  // Initializing Node* temp

        if (Head == NULL) {     // If the vector is empty,
            Head = temp;        // temp is the Head and Tail
            Tail = temp;
        }
        else {                  // else add to the front of the
            temp->next = Head;  // vector
            Head->prev = temp;
            Head = temp;
        }

        size++;                 // Increment size
    }

     /**
     * Public  :  popBack 
     *
     * Description:
     *      Deletes the rear node of a vector and returns
     *      its value.
     *
     * Params:
     *      none
     *
     * Returns:
     *      T   :   a nodes data, whatever that might be
     */
    T popBack() {

        if (Tail) {               
            
            int d = Tail->data;     // Initializing Variables
            Node<T>* temp = Tail;
            
            Tail = Tail->prev;      // If Tail, connect pointers
            if (Tail) {             // and delete Tail and return
                Tail->next = NULL;  // Tail->data
            }
            else {
                Head = NULL;
            }
            delete temp;

            size--;                 // Decrement size
            
            return d;               // Tail->data
        }
        
        return -1;                  // Return -1 if the vector is empty
    }


    /**
     * Public  :  popFront 
     *
     * Description:
     *      Deletes the front node of a vector and returns
     *      its value.
     *
     * Params:
     *      none
     *
     * Returns:
     *      T   :   a nodes data, whatever that might be
     */
    T popFront() {

        if (Head) {                 
            
            T d = Head->data;       // Initializing Variables
            Node<T>* temp = Head;
                                    
            Head = Head->next;      // If Head, connect pointers
            if (Head) {             // and delete Head and return
                Head->prev = NULL;  // Head->data
            }
            else {
                Tail = NULL;
            }
            delete temp;

            size--;                 // Decrement

            return d;               // Head->data
        }

        return -1;                  // Returns -1 if the vector is empty
    }


    /**
     * Public  :  print 
     *
     * Description:
     *      Traverses a vector and prints out each of its nodes
     *
     * Params:
     *      none
     *
     * Returns:
     *      void
     */
    void print() {

        Node<T>* temp = Head;      // Initializing Node* temp

        while (temp) {             // Traversing through vector
            cout << temp->data;    // and printing out each value
            if (temp->next) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * Public  :  friend operator<< 
     *
     * Description:
     *      Overloads the "<<" operator letting us print a vector
     *      straight to the output stream instead of using a "print"
     *      function.
     *
     * Params:
     *      ostream& os          :  a output stream object
     *      const MyVector& obj  :  the vector to be printed out
     *
     * Returns:
     *      ostream&   :   an output stream object with the vectors data
     */
    friend ostream& operator<<(ostream& os, const MyVector& obj) {

        Node<T>* temp = obj.Head;   // Initializing Node* temp

        while (temp) {
            os << "[";              // Concatenating the final image of each
            os << temp->data;       // node in the vector
            os << "]";
            if (temp->next) {
                os << "->";
            }
            temp = temp->next;
        }

        return os;
    }
    
    /**
     * Public  :  operator[] 
     *
     * Description:
     *      Overloads the "[]" square brackets so we can treat our
     *      vector similar to an array. This will let us obtain
     *      a value from any existing node, or update that nodes'
     *      value by assigning it a new one.
     *
     * Params:
     *      int index   :   the index of the vector to be modified
     *
     * Returns:
     *      T&   :   the modified index with a new value
     */
    T& operator[](int index) {

        if (index >= size) {       // Checks if index is out of bounds
            cout << "Array index out of bound, exiting";
            exit(0);
        }
        Node<T>* temp = Head;      // Initializing Node* temp
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->data;
    }

    /**
     * Public  :  operator+ 
     *
     * Description:
     *      Overloads the "+" plus sign to concatenate
     *      two vectors end to end returning a third
     *      new vector
     *
     * Params:
     *      const MyVector& lhs  :  a vector that is already in memory
     *
     * Returns:
     *      T   :   a final vector of the two combined vectors
     */
    MyVector operator+(const MyVector& lhs) {

        Node<T>* temp1 = Head;    // Initializing Variables
        Node<T>* temp2 = lhs.Head;
        MyVector V;
        
        while (temp1) {         // While loops that concatenate two vectors
            V.pushBack(temp1->data);
            temp1 = temp1->next;
        }

        while (temp2) {
            V.pushBack(temp2->data);
            temp2 = temp2->next;
        }

        return V;
    }
    
    /**
     * Public  :  Sort 
     *
     * Description:
     *      Traverses a vector and puts its values in ascending order
     *      by comparing two nodes directly and swapping their values.
     *
     * Params:
     *      bool asc   :    is set to true because we want the vector
     *                      to be in ascending order
     *
     * Returns:
     *      void
     */
    void Sort(bool asc = true) {//bool asc = true

        Node<T>* Start = Head;
        
        while (Start) {
            Node<T>* minp = Start;       // Starting minimum position
            int minv = Start->data;      // Starting minimum value
            Node<T>* mint = Start;       // Node pointer that walks down list and compares 
                                         // its value with minv
            bool doSwap = 0;             // doSwap = false

            while (mint) {               // While walking down the list

                if (asc) {               // If asc = true or going in ascending order
                    doSwap = (*mint < *minp); // doSwap = true
                }
                else {
                    doSwap = (*mint > *minp); // doSwap = false
                }

                if (doSwap) {           // doSwap = true
                    minp = mint;        
                    minv = mint->data;  
                }                       

                    mint = mint->next;  // connect the nodes together
                
            }

            // swap the nodes data
            minp->data = Start->data;
            Start->data = minv;
            Start = Start->next;

        }

    }

};

/**
     * Public  :  randString 
     *
     * Description:
     *      Creates a string jumbled with uppercase and lowercase letters
     *
     * Params:
     *      int len   :   the length of the string
     *
     * Returns:
     *      s   :   a jumbled string
     */
string randString(int len) {

    string s; // Initializing string to be returned

    for (int i = 0; i < len; i++) {
         
        // AddS 65 to make uppercase letters and add 97 to
        // make lowercase letters.
        s += char((rand() % 26) + 65);
        s += char((rand() % 26) + 97);

    }

    return s;   // Returns a string jumbled with uppercase
                // and lowercase letter.
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
    
    V2.Sort(asc);               // Sorts vector, V2's data in ascending order
    
    cout << V2 << endl;
    cout << V3 << endl;

    V2[4] = 0;                  // Puts the value 0, into the fifth element of V2

    cout << V2 << endl;
    cout << V3 << endl;

    MyVector<string> V4;        // Initializing vectors that hold strings
    MyVector<string> V5;
  
    for (int i = 0; i < 10; i++) {  
                                       // For loops that push chars onto
        V4.pushFront(randString(8));   // the vectors

    }

    for (int i = 0; i < 5; i++) {

        V5.pushFront(randString(8));

    }

    cout << V4 << endl;
    cout << endl;
    cout << V5 << endl;

    return 0;
}
