#include "sorting_algorithms.h"

template<typename T>
std::vector<T>& bubble_sort(std::vector<T>& vec)
{
    bool is_not_sorted = 1;
    while(is_not_sorted)
    {
        is_not_sorted = 0;
        for(int i = 0; i < vec.size()-1; ++i)
        {
            if(vec[i] > vec[i+1])
            {
                
                T tmp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = tmp;
                is_not_sorted = 1;
            }
        }
    }

    return vec;
}

template<typename T>
std::vector<T>& selection_sort(std::vector<T>& vec)
{
    int min;
    T tmp;
    for(int i = 0; i < vec.size()-1; ++i)
    {
        min = i;
        for(int j = i + 1; j < vec.size(); ++j)
        {
            if(vec[min] > vec[j])
            {
                min = j;
            }
        }

        tmp = vec[min];
        vec[min] = vec[i];
        vec[i] = tmp;
    }

    return vec;
}

template<typename T>
std::vector<T>& insertion_sort(std::vector<T>& vec)
{
    for(int i = 0; i < vec.size()-1; ++i)
    {
        if(vec[i] > vec[i+1])
        {
            for(int j = i+1; j > 0; --j)
            {
                if(vec[j] < vec[j-1])
                {
                    T tmp = vec[j];
                    vec[j] = vec[j-1];
                    vec[j-1] = tmp;
                }
                else
                {
                    break;
                }
            }
        }       
    }

    return vec;
}

template<typename T>
void r_bubble_sort(std::vector<T>& vec, int pos, bool& is_not_sorted)
{
    if(pos+1 >= vec.size())
    {
        return;
    }

    if(vec[pos] > vec[pos+1])
    {
        T tmp = vec[pos];
        vec[pos] = vec[pos+1];
        vec[pos+1] = tmp;
        is_not_sorted = 1;
    }

    r_bubble_sort(vec, pos+1, is_not_sorted);
}

template<typename T>
std::vector<T>& recursive_bubble_sort(std::vector<T>& vec)
{
    bool is_not_sorted = 1;
    while(is_not_sorted)
    {
        is_not_sorted = 0;
        r_bubble_sort(vec, 0, is_not_sorted);
    }

    return vec;
}

template<typename T>
void r_selection_sort(std::vector<T>& vec, int pos)
{
    if(pos < vec.size() - 1)
    {
        int min = pos;

        for(int i = pos+1; i < vec.size(); ++i)
        {
            if(vec[min] > vec[i])
            {
                min = i;
            }
        }

        if(min != pos)
        {
            T tmp = vec[min];
            vec[min] = vec[pos];
            vec[pos] = tmp;
        }

        r_selection_sort(vec, pos+1);
    }
}

template<typename T>
std::vector<T>& recursive_selection_sort(std::vector<T>& vec)
{
    r_selection_sort(vec, 0);
    return vec;
}

template<typename T>
void r_insertion_sort(std::vector<T>& vec, int pos)
{
    if(pos < vec.size() - 1)
    {
        if(vec[pos] > vec[pos+1])
        {
            for(int j = pos+1; j > 0; --j)
            {
                if(vec[j] < vec[j-1])
                {
                    T tmp = vec[j];
                    vec[j] = vec[j-1];
                    vec[j-1] = tmp;
                }
            }
        }

        r_insertion_sort(vec, pos+1);
    }
}

template<typename T>
std::vector<T>& recursive_insertion_sort(std::vector<T>& vec)
{
    r_insertion_sort(vec, 0);
    return vec;
}

template<typename T>
std::list<T>& list_bubble_sort(std::list<T>& list)
{   
    auto it_prev = list.begin();
    auto it_next = ++list.begin();
    bool is_not_sorted = 1;
    ++it_next;

    while(is_not_sorted)
    {
        is_not_sorted = 0;
        while(it_next != list.end())
        {
            if(*it_next < *it_prev)
            {
                T tmp = *it_next;
                *it_next = *it_prev;
                *it_prev = tmp;
                is_not_sorted = 1;
            }
            ++it_prev;
            ++it_next;
        }

        it_prev = list.begin();
        it_next = ++list.begin();
    }

    return list;
}

template<typename T>
std::list<T>& list_selection_sort(std::list<T>& list)
{
    auto it_current = list.begin();
    auto it_max = list.begin();
    auto iter = list.begin();

    while(it_current != --list.end())
    {
        it_max = it_current;
        iter = it_current;
        ++iter;
        while(iter != list.end())
        {
            if(*it_max > *iter)
            {
                it_max = iter;
            }
            ++iter;
        }

        if(it_max != it_current)
        {
            T tmp = *it_max;
            *it_max = *it_current;
            *it_current = tmp;
        }

        ++it_current;
    }

    return list;
}

template<typename T>
std::list<T>& list_insertion_sort(std::list<T>& list)
{
    auto it_current = list.begin();
    auto iter = list.begin();

    while(it_current != list.end())
    {
        iter = it_current;
        ++iter;
        if(*it_current > *iter)
        {
            auto iter2 = iter;
            --iter2;
            while(iter != list.begin())
            {
                T tmp = *iter;
                *iter = *iter2;
                *iter2 = tmp;
                --iter;
                --iter2; 
            }
        } 

        ++it_current; 
    }

    return list;

}