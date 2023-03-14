#include "sorting_algorithms.h"

int main()
{
    std::list<int> list;
    list.push_back(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(4);
    list.push_back(1);
    list.push_back(0);
    
    list_insertion_sort(list);

    for(std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}