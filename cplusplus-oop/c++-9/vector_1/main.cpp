#include <iostream>


template<typename T>
class MyVector {
private:
    size_t _capacity;
    size_t _size;
    T* _data;

    void resize(size_t new_capacity)
    {
        T* temp_data = new T[new_capacity];
        for (size_t i = 0; i < _size; i++)
        {
            temp_data[i] = _data[i];
        }
        delete[] _data;
        _data = temp_data;
        _capacity = new_capacity;
    }

public:
    MyVector() : _capacity(0), _size(0), _data(nullptr) {}
    ~MyVector()
    {
        delete[] _data;
    }

    void add(const T& value)
    {
        if (_size == _capacity)
        {
            resize(_capacity == 0 ? 1 : _capacity * 2);
        }

        _data[_size++] = value;
    }

    bool remove(size_t index)
    {
        if (index >= _size)
        {
            return false;
        }
        else
        {
            for (size_t i = index; i < _size - 1; i++)
            {
                _data[i] = _data[i + 1];
            }
            --_size;
            return true;
        }
    }

    size_t get_capacity() const
    {
        return _capacity;
    }

    size_t get_size() const
    {
        return _size;
    }

    T& operator[](size_t index)
    {
        return _data[index];
    }
    T pop_back()
    {
        if (_size == 0)
        {
            return T();
        }
        return _data[--_size];
    }

    bool contains(const T& value) const
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_data[i] == value)
            {
                return true;
            }
        }
        return false;
    }
    void reverse()
    {
        size_t left = 0, right = _size - 1;
        while (left < right)
        {
            T temp = _data[left];
            _data[left] = _data[right];
            _data[right] = temp;
            left++;
            right--;
        }
    }
    MyVector<T> copy() const
    {
        MyVector<T> new_vector;
        for (size_t i = 0; i < _size; i++)
        {
            new_vector.add(_data[i]);
        }
        return new_vector;
    }
    bool operator==(const MyVector<T>& other) const
    {
        if (_size != other._size)
        {
            return false;
        }

        for (size_t i = 0; i < _size; i++)
        {
            if (_data[i] != other._data[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const MyVector<T>& other) const
    {
        return !(*this == other);
    }
    void sort()
    {
        for (size_t i = 0; i < _size - 1; i++)
        {
            size_t min_index = i;
            for (size_t j = i + 1; j < _size; j++)
            {
                if (_data[j] < _data[min_index])
                {
                    min_index = j;
                }
            }
            if (min_index != i)
            {
                T temp = _data[i];
                _data[i] = _data[min_index];
                _data[min_index] = temp;
            }
        }
    }


    void swap(MyVector<T>& other)
    {
        T* temp_data = _data;
        _data = other._data;
        other._data = temp_data;

        size_t temp_capacity = _capacity;
        _capacity = other._capacity;
        other._capacity = temp_capacity;

        size_t temp_size = _size;
        _size = other._size;
        other._size = temp_size;
    }

};

template<typename T>
void display_array(MyVector<T>& my_vector)
{
    for (size_t i = 0; i < my_vector.get_size(); i++)
    {
        std::cout << my_vector[i] << " ";
    }std::cout << std::endl;
}


int main()
{
    MyVector<int> arr;
    arr.add(7);
    arr.add(2);
    arr.add(3);
    std::cout << "Original vector: ";
    display_array(arr);

    std::cout << "Vector after pop: ";
    display_array(arr);

    arr.add(4);
    arr.add(5);
    std::cout << "Vector after adding more elements: ";
    display_array(arr);

    std::cout << "Contains 3? " << (arr.contains(3) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 7? " << (arr.contains(7) ? "Yes" : "No") << std::endl;

    arr.reverse();
    std::cout << "Vector after reverse: ";
    display_array(arr);

    MyVector<int> copied_arr = arr.copy();
    std::cout << "Copied vector: ";
    display_array(copied_arr);

    arr.sort();
    std::cout << "Vector after sort: ";
    display_array(arr);

    MyVector<int> swap_arr;
    swap_arr.add(100);
    swap_arr.add(200);
    arr.swap(swap_arr);
    std::cout << "Vector after swap: ";
    display_array(arr);
    std::cout << "Swap vector: ";
    display_array(swap_arr);

    return 0;
}
