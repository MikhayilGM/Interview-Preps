#ifndef ___BINARY_TREE_____
#define ___BINARY_TREE_____
#include <iostream>
#include <vector>

template<typename T>
class Tree
{
    public:

    virtual void insert(const T& val) = 0;
    virtual void erase(const T& val) = 0;
};


template<typename T>
class Binary_Tree : public Tree<T>
{
    private:

        struct B_TreeNode
        {
            public:

                B_TreeNode();
                B_TreeNode(const T& val);

            protected:

                B_TreeNode* less;
                B_TreeNode* more;

            public:

                T value;

            friend class Binary_Tree;
        };

    private: // utility member methods

        void delete_(B_TreeNode* node);
        void balance_to_more();
        void balance_to_less();
        void print_preOrderNode(B_TreeNode* node);
        void print_postOrderNode(B_TreeNode* node);
        void print_levelOrderNode(B_TreeNode* node, int level);

    public:

        class iterator
        {   
            public:

                iterator();
                iterator(B_TreeNode*);

                iterator operator=(B_TreeNode*);
                const B_TreeNode* operator->();

                void to_more();
                void to_less();

            private:

                B_TreeNode* current;

        };
        
    public:

        Binary_Tree();
        Binary_Tree(const T& value);
        ~Binary_Tree();
    
        void insert(const T& val) override;
        void erase(const T& val) override;
        iterator find(const T& val);
        void print_inOrder();
        void print_preOrder();
        void print_postOrder();
        void print_levelOrder();

    private:

        B_TreeNode* root;
        int less_height;
        int more_height;
};

#endif