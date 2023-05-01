#include <unordered_map>
#include <vector>

using std::unordered_multimap;
using std::vector;
using std::pair;
using std::swap;

struct heap
{
    typedef pair<unordered_multimap<int, int>::iterator, unordered_multimap<int, int>::iterator> prange;

    vector<int> __heap;
    unordered_multimap<int, int> elm2ind;

    void __swap(int __x, int __y)
    {
        prange x_range = elm2ind.equal_range(__heap[__x]);
        prange y_range = elm2ind.equal_range(__heap[__y]);
        for (auto it = x_range.first; it != x_range.second; it++)
            if (it->second == __x)
            {
                it->second = __y;
                break;
            }

        for (auto it = y_range.first; it != y_range.second; it++)
            if (it->second == __y)
            {
                it->second = __x;
                break;
            }

        swap(__heap[__x], __heap[__y]);
    }

    void up(int pos)
    {
        int parent = (pos - 1) >> 1;
        while (parent >= 0 && __heap[parent] < __heap[pos])
        {
            __swap(parent, pos);
            pos = parent;
            parent = (pos - 1) >> 1;
        }
    }

    void down(int pos)
    {
        int left = (pos << 1) + 1, right = (pos << 1) + 2;
        int size = __heap.size();
        while (left < size)
        {
            int y = pos;
            if (__heap[left] > __heap[y])
                y = left;
            if (right < size && __heap[right] > __heap[y])
                y = right;
            if (y != pos)
            {
                __swap(pos, y);
                pos = y;
                left = (pos << 1) + 1, right = (pos << 1) + 2;
            }
            else
                break;
        }
    }

    void random_delete(int data)
    {
        prange range = elm2ind.equal_range(data);
        int pos = range.first->second;
        int size = __heap.size();

        __swap(pos, size - 1);
        __heap.pop_back();
        elm2ind.erase(range.first);

        //关键调整操作
        up(pos);
        down(pos);
    }

    int &top()
    {
        return __heap[0];
    }

    void push(int data)
    {
        __heap.push_back(data);
        elm2ind.insert({data, __heap.size() - 1});
        up(__heap.size() - 1);
    }
};
