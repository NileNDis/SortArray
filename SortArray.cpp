#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::size_t partition(std::vector<int>& vec, std::size_t left, std::size_t right)
{
    int value = vec[(left + right) / 2];
    auto i = left;
    auto j = right;
    while (i <= j)
    {
        while (vec[i] < value)
        {
            i++;
        }
        while (vec[j] > value)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        std::swap(vec[i++], vec[j--]);
    }
    return j;
}

void q_sort(std::vector<int>& vec, std::size_t left, std::size_t right)
{
    if (left < right)
    {
        auto q = partition(vec, left, right);
        q_sort(vec, left, q);
        q_sort(vec, q + 1, right);
    }
}
int main()
{
    int size, num;
    cin >> size;
    std::vector<int> unsorted(size);
    for (int i = 0; i < size; ++i)
    {
        cin >> unsorted[i];
    }

    cout << size << " ";

    q_sort(unsorted, 0, unsorted.size() - 1);

    for (auto num : unsorted)
    {
        std::cout << num << " ";
    }

    system("pause");

    return 0;
}