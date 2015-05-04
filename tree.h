/*!
 *  \file tree.h 
 */

#pragma once;

#include <iostream>

/*! 
 *  \brief Straight print mode
 */
#define PRINT_MODE_STRAIGHT   (1)

/*! 
 *  \brief Symmetric print mode
 */
#define PRINT_MODE_SYMMETRIC  (2)

/*! 
 *  \brief Inverted print mode
 */
#define    PRINT_MODE_INVERTED   (3)

/*! 
 *  \class Tree
 *  \brief Binary tree class
 */
template <class T> class Tree 
{ 
    /*! 
         *  \privatesection
         */
    private:

        /*! 
         *  \struct Node
         *  \brief Binary tree node
         */
        struct Node
        { 

            T value;

            Node* left;
            Node* right;

            int count;

            /*! 
             *  \brief Struct Node constructor a node.
             *  \param value Node value.
             */
            Node(T value)
            {
                this->value = value;
            }

            /*! 
             *  \brief Printing the tree.
             *  \warning Function is recursive.
             *  \param level Tree level, 0 by default.
             *  \return Function returns nothing.
             */
            void printGraph (int level = 0)
            {
                Node* node = this;

                if (node) 
                    node->right->printGraph (level + 1);

                    for (int i = 0; i < level; i ++)
                        std::cout << "     ";

                    if (node)
                        std::cout << node->value << "(" << node->count << ")" << std::endl;
                    else
                        std::cout << " " << std::endl;

                if (node) 
                    node->left->printGraph (level + 1);
            }

        } *root;

        /*! 
         *  \brief Removing a node.
         *  \private
         *  \warning Function is recursive.
         *  \param node Reference to removed node.
         *  \return Function returns nothing.
         */
        void removeNode (Node*& node)
        {
            if (!node) return;

            if (node->left) 
            { 
                removeNode (node->left);
                node->left = NULL;
            }

            if (node->right) 
            { 
                removeNode (node->right);
                node->right = NULL;
            }

            delete node;
            node = NULL;
        }

        /*! 
         *  \brief printing  a node.
         *  \warning Function is recursive.
         *  \param node Current node for printing.
         *  \param printMode Print mode.
         *  \return Function returns nothing.
         */
        void print (Node* node, int printMode = PRINT_MODE_STRAIGHT)
        {
            if (!node) return;

            switch (printMode)
            {
                case 1:
                {
                    std::cout << node->value << "  ";
                    if (node->left)  print (node->left,  printMode);
                    if (node->right) print (node->right, printMode);
                    break;
                }

                case 2:
                {
                    if (node->left)  print (node->left,  printMode);
                    std::cout << node->value << "  ";
                    if (node->right) print (node->right, printMode);
                    break;
                }

                case 3:
                {
                    if (node->left)  print (node->left,  printMode);
                    if (node->right) print (node->right, printMode);
                    std::cout << node->value << "  ";
                    break;
                }

                default: print (node, PRINT_MODE_STRAIGHT);
            }
        }

        /*! 
         *  \brief Creating a node.
         *  \param newNode Reference to created node.
         *  \param value Node value.
         *  \return Function returns nothing.
         */
        void createNode (Node*& newNode, T value)
        {
            newNode = new Node (value);
            newNode->left  = NULL;
            newNode->right = NULL;
            newNode->count = 1;
        }

        /*! 
         *  \brief Searching a node for removing by its value.
         *  \details When node is found, removeNode() method is launched.
         *  \warning Function is recursive.
         *  \param removeValue Removed node value.
         *  \param node Node the search is started with.
         *  \return Function returns nothing.
         */
        void findRemoveNode (T removeValue, Node*& node)
        {
            if (!node)
                return;

            if (removeValue < node->value) 
                findRemoveNode (removeValue, node->left);
            else if (removeValue > node->value) 
                findRemoveNode (removeValue, node->right);
            else
                removeNode (node);
        }

        /*! 
         *  \brief Adding value to the tree.
         *  \warning Function is recursive.
         *  \param addValue Added value.
         *  \param node Current existing node.
         *  \return Function returns nothing.
         */
        void addNode (T addValue, Node* node = NULL)
        {
            if(!root)
            {
                createNode (root, addValue);
                return;
            }

            if (!node)
                node = root;

            if (addValue < node->value)  
            { 
                if(node->left)
                    addNode (addValue, node->left);
                else
                {
                    createNode (node->left, addValue);
                    return;
                }
            }
            else if (addValue > node->value)  
            { 
                if(node->right)
                    addNode (addValue, node->right);
                else
                {
                    createNode (node->right, addValue);
                    return;
                }
            }
            else node->count ++;
        
            return;
        }

    public:

        /*! 
         *  \brief Class Tree constructor.
         *  \param rootValue Root value.
         */
        Tree (T rootValue)
        {
            createNode (root, rootValue);
        }

        /*! 
         *  \brief Class Tree destructor.
         */
        ~Tree ()
        {
            removeNode (root);
        }

        /*! 
         *  \brief Deleting the tree
         *  \return Function returns nothing.
         */
        void deleteTree()
        {
            removeNode (root);
        }

        /*! 
         *  \brief Adding a value to the tree
         *  \param addValue Added value.
         *  \return Function returns nothing.
         */
        void add (T addValue)
        {
            addNode (addValue);
        }

        /*! 
         *  \brief Removing a node by its value
         *  \param removeValue Value of removed node.
         *  \return Function returns nothing.
         */
        void remove (T removeValue)
        {
            findRemoveNode (removeValue, root);
        }

        /*! 
         *  \brief Printing a tree.
         *  \return Function returns nothing.
         */
        void printGraph()
        {
            root->printGraph();
            std::cout << std::endl;
        }

        /*! 
         *  \brief Printing the tree nodes.
         *  \param printMode Print mode.
         *  \return Function returns nothing.
         */
        void printTree(int printMode = PRINT_MODE_STRAIGHT)
        {
            print(root, printMode);
            std::cout << std::endl;
        }
};
