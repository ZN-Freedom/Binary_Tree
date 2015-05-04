/*! 
 *  \mainpage Binary Tree
 *  \section intro_sec Description
 *  There is example of using binary tree based on templates.\n
 *  Available operations: adding and removing values, printing and deleting the tree.
 */

/*!
 *  \file main.cpp 
 */

#include "tree.h"

/*! 
 *  \brief Program entry point.
 *  \details User creates the tree, adds some elements and remove them, prints the tree itself and its nodes.
 */
void main ()
{
    // Check 1
    Tree <int> tree(7);
    tree.add(5);
    tree.add(3);
    tree.add(5);
    tree.add(7);
    tree.add(9);
    tree.add(2);
    tree.add(1);
    tree.add(10);
    tree.add(8);
    tree.add(6);
    tree.add(4);

    std::cout << "Graph : " << std::endl;
    tree.printGraph ();

    std::cout << "Straight : " ;
    tree.printTree (PRINT_MODE_STRAIGHT);

    std::cout << "Symmetric : " ;
    tree.printTree (PRINT_MODE_SYMMETRIC);

    std::cout << "Inverted : " ;
    tree.printTree (PRINT_MODE_INVERTED);


    // Check 2
    tree.remove(3);
    std::cout << "Graph : " << std::endl;
    tree.printGraph ();


    // Check3
    tree.deleteTree();
    std::cout << "Graph : " << std::endl;
    tree.printGraph ();
}
