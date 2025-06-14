#include <iostream>
#include <stdexcept>

using namespace std;

class MyArray
{
private:
    int *data;
    int size;
    int capacity;

public:
    MyArray() : capacity(2), size(0)
    {
        this->data = new int[2];
        // memset(this->data, 0, this->capacity*sizeof(int));
    }

    MyArray(int cap) : capacity(cap > 0 ? cap : 1), size(0)
    {
        this->data = new int[cap];
        // memset(this->data, 0, this->capacity*sizeof(int));
    }

    // 禁用拷贝构造函数和赋值运算符
    MyArray(const MyArray &) = delete;
    MyArray &operator=(const MyArray &) = delete;

    bool set(int index, int val);
    int get(int index);

    bool add(int index, int val);
    bool addFirst(int val);
    bool addLast(int val);

    int remove(int index);
    int removeFirst();
    int removeLast();

    int getSize();
    bool isValidIndex(int index);
    bool isEmpty();
    void resize(int newCap);
    void display();

    ~MyArray()
    {
        delete[] data;
    }
};

int MyArray::getSize()
{
    return this->size;
}

bool MyArray::isValidIndex(int index)
{
    return index >= 0 && index < this->size;
}

bool MyArray::isEmpty()
{
    return this->size == 0;
}

void MyArray::resize(int newCap)
{
    if (newCap < 1)
    {
        newCap = 1;
    }

    int *newData = new int[newCap];
    int elementToCopy = (newCap > this->size) ? this->size : newCap;
    memmove(newData, this->data, elementToCopy * sizeof(int));

    delete[] this->data;
    this->data = newData;
    this->capacity = newCap;
    this->size = (newCap > this->size) ? this->size : newCap;
}

bool MyArray::set(int index, int val)
{
    if (!isValidIndex(index))
    {
        return false;
    }

    this->data[index] = val;
    return true;
}

int MyArray::get(int index)
{
    if (isValidIndex(index))
    {
        return data[index];
    }

    return -1;
}

bool MyArray::add(int index, int val)
{
    if (index < 0 || index > this->size)
    {
        return false;
    }

    try
    {
        if (this->size == this->capacity)
        {
            resize(this->capacity << 1);
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return false;
    }

    if (index < this->size)
    {
        memmove(data + index + 1, data + index, (this->size - index) * sizeof(int));
    }

    data[index] = val;
    this->size++;
    return true;
}

bool MyArray::addFirst(int val)
{
    return add(0, val);
}

bool MyArray::addLast(int val)
{
    return add(this->size, val);
}

int MyArray::remove(int index)
{
    if (!isValidIndex(index) || isEmpty())
    {
        //return -1;
        throw std::out_of_range("NoSuchElementException");
    }

    int oldValue = this->data[index];
    if (index != this->size - 1)
    {
        memmove(data + index, data + index + 1, this->size - index - 1);
    }
    if (this->capacity > 2 && this->size <= this->capacity / 4)
    {
        resize(this->capacity >> 1);
    }
    this->size--;
    return oldValue;
}

int MyArray::removeFirst()
{
    return remove(0);
}

int MyArray::removeLast()
{
    return remove(this->size - 1);
}

void MyArray::display()
{
    std::cout << "Size: " << size << "/" << capacity << "\nElements: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n"
              << std::endl;
}

int main()
{
    // 初始容量设置为 3
    MyArray arr(3);
    arr.display();

    // 添加 5 个元素
    for (int i = 1; i <= 5; i++)
    {
        arr.addLast(i);
    }
    arr.display(); // 1 2 3 4 5

    arr.remove(3);
    arr.display();

    arr.add(1, 9);
    arr.addFirst(100);
    arr.display(); // 100 1 9 2 3 5

    int val = arr.removeLast();
    arr.display(); // 100 1 9 2 3

    return 0;
}