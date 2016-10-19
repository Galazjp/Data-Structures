//
//  Linked_List.hpp
//
//
//  Created by Galazjp on 10/5/16.
// 
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>

/*
    Node
 
    struct that represents an elements in a linked list
 
    Stores:
    A pointer to the next value in the linked list
    A value of type T representing the value at the node
 
*/

template <class T>
struct Node
{
    Node* next = NULL;
    T value;
    int weight;
};

/*
    LinkedList
 
    class that represents a linked list of nodes of type T
 
    Stores:
    A private pointer to the the first value in the List set to NULL if list is empty
 
    Implements:
    printList() a public function to print the entire list
    isEmpty() a public function that returns whether a given list is empty
    insert(T value) a public function to insert a node with a given value of type T into the list
    remove(T value) a public function to remove a node with a given value of type T from the list
    search(T value) a public function to search for a given node in the list with a given value of type T
 
 
*/

template <class T>
class LinkedList
{
private:
    Node<T>* _head = NULL;
public:
    
    void printList();
    bool isEmpty();
    void insert(T value, int weight = -1);
    void remove(T value);
    Node<T>* search(T value);
    void reverse();
};

/*
    printList()
    
    A function to print all elements in the linked list
    
    Parameters:
    none
    Returns:
    void
 
*/

template <class T>
void LinkedList<T>::printList()
{
    Node<T>* temp = _head;
    while (temp != NULL)
    {
        std::cout<< temp->value<<std::endl;
        temp = temp->next;
    }
}

template <class T>
void LinkedList<T>::reverse()
{
    // O(N)
    Node<T>* next = _head;
    Node<T>* node = NULL;
    
    while(next->next != NULL)
    {
        Node<T>* prev = node;
        node = next;
        next = next->next;
        node->next = prev;

    }
    
    next->next = node;
    _head = next;
}


/*
    isEmpty()
 
    A function that tells whether the linked list is empty
 
    Parameters:
    none
    Returns:
    a boolean, true if empty, false if not
 
*/

template <class T>
bool LinkedList<T>::isEmpty()
{
    bool isEmpty = false;
    
    if (_head == NULL)
    {
        isEmpty = true;
    }
    return isEmpty;
}


/*
    insert(T value)
 
    A function to insert a node with a given value of type T into the linked list
 
    Parameters:
    T value, the new node with that value
    int weight soley for adjacency list purposes
    Returns:
    void
 
 */
template <class T>
void LinkedList<T>::insert(T value, int weight)
{
    Node<T>* node = new Node<T>();
    node->value = value;
    node->next = _head;
    node->weight = weight;
    
    // add to the front of linked list keeping 0(1) insert
    _head = node;
}

/*
    search(T value)
 
    A function to search for a node with a given value of type T in the linked list
 
    Parameters:
    T value, the new node with that value
    Returns:
    a pointer to the node being searched for, NULL if it doesn't exist
 
*/

template <class T>
Node<T>* LinkedList<T>::search(T value)
{
    Node<T>* node = _head;
    
    int on = true;
    
    while (node != NULL && on)
    {
        if (node->value == value )
        {
            on = false;
        }
        node = node->next;
    }
    return node;
}

/*
    remove(T value)
 
    A function to remove a node with a given value of type T from the linked list

    Parameters:
    T value, the value for the node to delete
    Returns:
    void; returns if element does not exist or is empty
 
 */

template <class T>
void LinkedList<T>::remove(T value)
{
    if (!isEmpty())
    {
        Node<T>* node = _head;
        Node<T>* prev = NULL;
        
        // check to see that you are still in inside the linked list memory
        while(node != NULL)
        {
            
            if (node->value == value)
            {
                if (_head == node)
                {
                    _head = node->next;
                    node->next = NULL;
                }
                else
                {
                    prev->next = node->next;
                }
                
                node = NULL;
                delete node;
            }
            if (node != NULL)
            {
                prev = node;
                node = node->next;
            }
        }
    }

}

#endif /* LinkedList_hpp */
