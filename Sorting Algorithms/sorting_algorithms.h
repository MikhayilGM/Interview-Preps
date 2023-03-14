#include <vector>
#include <iostream>
#include <list>

template<typename T>
std::vector<T>& bubble_sort(std::vector<T>& vec);

template<typename T>
std::vector<T>& selection_sort(std::vector<T>& vec);

template<typename T>
std::vector<T>& insertion_sort(std::vector<T>& vec);

template<typename T>
void r_bubble_sort(std::vector<T>& vec, int pos, bool& is_not_sorted);

template<typename T>
std::vector<T>& recursive_bubble_sort(std::vector<T>& vec);

template<typename T>
void r_selection_sort(std::vector<T>& vec, int pos);

template<typename T>
std::vector<T>& recursive_selection_sort(std::vector<T>& vec);

template<typename T>
void r_insertion_sort(std::vector<T>& vec, int pos);

template<typename T>
std::vector<T>& recursive_insertion_sort(std::vector<T>& vec);

template<typename T>
std::list<T>& list_bubble_sort(std::list<T>& list);

template<typename T>
std::list<T>& list_selection_sort(std::list<T>& list);

template<typename T>
std::list<T>& list_insertion_sort(std::list<T>& list);