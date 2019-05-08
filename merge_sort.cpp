// Simple implementation of Merge Sort algorithm (Bottom Up Variant)
#include <iostream>
#include <vector>


template <typename T>
void merge(std::vector<T>& array, std::vector<T>& array_left, std::vector<T>& array_right) 
{
    array.clear();
    
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < array_left.size() && j < array_right.size(); k++)
    {
        if (array_left.at(i) <= array_right.at(j))
        {
            array.push_back(array_left.at(i));
            i++;
        }
        else if (array_left.at(i) > array_right.at(j))
        {
            array.push_back(array_right.at(j));
            j++;
        }
        k++;
    }

    while(i < array_left.size())
    {
        array.push_back(array_left.at(i));
        i++;
    }

    while(j < array_right.size())
    {
        array.push_back(array_right.at(j));
        j++;
    }
}


// Splits the arrays
template <typename T>
void merge_sort(std::vector<T>& array) 
{
    if (1 < array.size()) 
    {
        // Left Array (Goes from the begining of the array until the middle)
        std::vector<T> array_left(array.begin(), array.begin() + array.size() / 2);
        merge_sort(array_left);
        // Right Array (Goes from the middle of array until the end)
        std::vector<T> array_right(array.begin() + array.size() / 2, array.end());
        merge_sort(array_right);

        merge(array, array_left, array_right);
    }
}


int main (int argc, char *argv[])
{
    std::cout << "G++ test";
    return EXIT_SUCCESS;
}
