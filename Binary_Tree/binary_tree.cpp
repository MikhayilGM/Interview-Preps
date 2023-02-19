#include "binary_tree.h"

template<typename T>
void Binary_Tree<T>::delete_(B_TreeNode* node)
{
    if(node->more)
    {
        delete_(node->more);
    }

    if(node->less)
    {
        delete_(node->less);
    }

    delete node;
}

template<typename T>
void Binary_Tree<T>::balance_to_more()
{
    B_TreeNode* tmp = root->less;
    root->less = tmp->more;
    tmp->more = root;
    root = tmp;
}

template<typename T>
void Binary_Tree<T>::balance_to_less()
{
    B_TreeNode* tmp = root->more;
    root->more = tmp->less;
    tmp->less = root;
    root = tmp;
}

template<typename T>
Binary_Tree<T>::iterator::iterator() : current(nullptr)
{

}

template<typename T>
Binary_Tree<T>::iterator::iterator(B_TreeNode* node) : current(node)
{

}

template<typename T>
Binary_Tree<T>::iterator Binary_Tree<T>::iterator::operator=(B_TreeNode* node)
{
    current = node;
    return this;
}

template<typename T>
const Binary_Tree<T>::B_TreeNode*  Binary_Tree<T>::iterator::operator->()
{
    if(current)
    {
        return current;
    }
    else
    {
        return current = new B_TreeNode(T());
    }
}

template<typename T>
void Binary_Tree<T>::iterator::to_more()
{
    if(current)
    {
        if(current->more)
        {
            current = current->more;
        }
    }
}

template<typename T>
void Binary_Tree<T>::iterator::to_less()
{
    if(current)
    {
        if(current->less)
        {
            current = current->less;
        }
    }
}

template<typename T>
Binary_Tree<T>::B_TreeNode::B_TreeNode() : value(T()), less(nullptr), more(nullptr)
{

}

template<typename T>
Binary_Tree<T>::B_TreeNode::B_TreeNode(const T& val) : value(val), less(nullptr), more(nullptr)
{
}

template<typename T>
Binary_Tree<T>::Binary_Tree() : root(nullptr)
{

}

template<typename T>
Binary_Tree<T>::Binary_Tree(const T& val) : root(new B_TreeNode(val))
{

}

template<typename T>
Binary_Tree<T>::~Binary_Tree()
{
    if(!root)
    {
        return;
    }

    delete_(root);
}

template<typename T>
void Binary_Tree<T>::insert(const T& val)
{
    if(!root)
    {
        root = new B_TreeNode(val);
        return;
    }
    bool is_less_side = root->value > val ? 1 : 0;
    int height = 0;
    B_TreeNode* tmp = root;

    while(1)
    {
        if(tmp->value == val)
        {
            return;
        }

        if(tmp->value > val)
        {
            if(!tmp->less)
            {
                tmp->less = new B_TreeNode(val);
                ++height;

                if(is_less_side)
                {
                    if(height > less_height)
                    {
                        less_height = height;
                    }    
                }
                else 
                {
                    if(height > less_height)
                    {
                        more_height = height;
                    }
                }
                break;
            }
            else
            {
                tmp = tmp->less;
                ++height;
            }
        }
        else
        {
            if(!tmp->more)
            {
                tmp->more = new B_TreeNode(val);
                ++height;

                if(is_less_side)
                {
                    if(height > less_height)
                    {
                        less_height = height;
                    }    
                }
                else 
                {
                    if(height > less_height)
                    {
                        more_height = height;
                    }
                }
                break;
            }
            else
            {
                tmp = tmp->more;
                ++height;
            }
        }
    }

    if(less_height - more_height == -10 || less_height - more_height == 10)
    {
        if(less_height - more_height == -10)
        {
            for (int i = 0; i < 5; ++i)
            {
                balance_to_less();
            }
        }
        else
        {
            for (int i = 0; i < 5; ++i)
            {
                balance_to_more();
            }
        }
    }
}

template<typename T>
void Binary_Tree<T>::erase(const T& val)
{
    if(!root)
    {
        return;
    }
    else if(root -> value == val)
    { 
        if(!(root->less && root->more))
        {
            delete root;
            root = nullptr;
        }
        else
        {
            
        }
    }

    B_TreeNode* tmp = root;
    B_TreeNode* prev = root;

    while(1)
    {
        if(tmp->value == val)
        {    
            while(1)
            {
                while(tmp->more)
                {
                    if(prev->less != tmp || tmp->value == val)
                    {
                        std::cout << tmp->value;
                        std::cout << prev->value;
                        prev = tmp;
                        tmp = tmp->more;
                        prev->value = tmp->value;
                    }
                    else
                    {
                        prev -> value = tmp->more->value;
                        prev = tmp;
                        tmp = tmp->more;
                    }
                    std::cout << tmp->value;
                }
                std::cout << "|" << prev->value;
                std::cout << tmp->value << "|";
                if(tmp->less)
                {
                    prev = tmp;
                    tmp = tmp->less;
                    if(!tmp->more)
                    {
                        prev->value = tmp -> value;
                    }
                }
                else
                {
                    break;
                }
            }

            std::cout << "dsaf";

            if(prev->less == tmp)
            {
                delete prev->less;
                prev->less = nullptr;
            }
            else
            {
                delete prev->more;
                prev->more = nullptr;
            }

            break;
        }

        if(tmp->value > val)
        {
            if(!tmp->less)
            {
                return;
            }
            else
            {
                prev = tmp;
                tmp = tmp->less;
            }
        }
        else
        {
            if(!tmp->more)
            {
                return;
            }
            else
            {
                prev = tmp;
                tmp = tmp->more;
            }
        }
    }
}

template<typename T>
Binary_Tree<T>::iterator Binary_Tree<T>::find(const T& val)
{
    if(!root)
    {
        return nullptr;
    }

    B_TreeNode* tmp = root;

    while(1)
    {
        if(tmp->value == val)
        {
            return tmp;
        }

        if(tmp->value > val)
        {
            if(!tmp->less)
            {
                return nullptr;
            }
            else
            {
                tmp = tmp->less;
            }
        }
        else
        {
            if(!tmp->more)
            {
                return nullptr;
            }
            else
            {
                tmp = tmp->more;
            }
        }
    }
}

template<typename T>
void Binary_Tree<T>::print_inOrder()
{
    if(!root)
    {
        return;
    }

    const B_TreeNode* prev_pointers[(less_height > more_height ? less_height : more_height)+1];
    int level_count = 0;
    const B_TreeNode* tmp = root;
    prev_pointers[0] = root;
    
    while(1)
    {
        if(tmp->less != prev_pointers[level_count+1])
        {
            while(tmp->less)
            {
                tmp = tmp->less;
                ++level_count;
                prev_pointers[level_count] = tmp;
            }
        }

        std::cout << tmp->value << " ";

        if(tmp->more)
        {
            tmp = tmp->more;
            ++level_count;
            prev_pointers[level_count] = tmp;
        }
        else
        {
            while(!tmp->more || tmp->more == prev_pointers[level_count+1])
            {
                --level_count;

                if(level_count == -1)
                {
                    return;
                }

                tmp = prev_pointers[level_count];
                

                if(tmp->less == prev_pointers[level_count+1] && !tmp->more && tmp != root)
                {
                    std::cout << tmp->value << " ";
                }
            }
        }
    }
}


template<typename T>
void Binary_Tree<T>::print_preOrderNode(B_TreeNode* node)
{
    std::cout << node->value << " ";

    if(node->less)
    {
        print_preOrderNode(node->less);
    }

    if(node->more)
    {
        print_preOrderNode(node->more);
    }
}

template<typename T>
void Binary_Tree<T>::print_preOrder()
{
    if(!root)
    {
        return;
    }

    std::cout << root->value << " ";

    if(root->less)
    {
        print_preOrderNode(root->less);
    }

    if(root->more)
    {
        print_preOrderNode(root->more);
    }
    
}

template<typename T>
void Binary_Tree<T>::print_postOrderNode(B_TreeNode* node)
{
    if(node->less)
    {
        print_postOrderNode(node->less);
    }

    if(node->more)
    {
        print_postOrderNode(node->more);
    }

    std::cout << node->value << " ";
}

template<typename T>
void Binary_Tree<T>::print_postOrder()
{
    if(!root)
    {
        return;
    }

    if(root->less)
    {
        print_postOrderNode(root->less);
    }

    if(root->more)
    {
        print_postOrderNode(root->more);
    }

    std::cout << root->value << " ";
}

template<typename T>
void Binary_Tree<T>::print_levelOrderNode(B_TreeNode* node, int level)
{
    if(!node)
    {
        return;
    }

    if(level == 0)
    {
        std::cout << node->value << " ";
    }
    else
    {
        print_levelOrderNode(node->less, level-1);
        print_levelOrderNode(node->more, level-1);
    }
}

template<typename T>
void Binary_Tree<T>::print_levelOrder()
{
    if(!root)
    {
        return;
    }

    int height = less_height > more_height ? less_height : more_height;

    for (int i = 0; i <= height; i++)
    {
        print_levelOrderNode(root, i);
        std::cout << std::endl;
    } 
    
}

int main()
{
    Binary_Tree<int> test(5);
    test.insert(8);
    test.insert(6);
    test.insert(7);
    test.insert(4);
    test.insert(2);
    test.insert(3);
    test.insert(1);
    test.print_inOrder();
    test.print_levelOrder();
    std::cout << "asf";
    return 0;
}
