#include <iostream>

class MyString {
private:
    char* _data;
    size_t _length;

public:

    MyString()  {
       _data = nullptr;
        _length = 0;
    }

    MyString(const char* str) {
        if (str) {
            _length = 0;
            while (str[_length] != '\0') {
                _length++;
            }
            _data = new char[_length + 1];
            for (size_t i = 0; i < _length; i++) {
                _data[i] = str[i];
            }
            _data[_length] = '\0';
        } else {
            _data = nullptr;
            _length = 0;
        }
    }

    MyString(const MyString& other) {
        _length = other._length;
        if (other._data) {
            _data = new char[_length + 1];
            for (size_t i = 0; i < _length; i++) {
                _data[i] = other._data[i];
            }
            _data[_length] = '\0';
        } else {
           _data = nullptr;
        }
    }

    MyString(MyString&& other) noexcept : _data(other._data), _length(other._length) {
        other._data = nullptr;
        other._length = 0;
    }

    MyString& operator=(MyString other) {
        delete[] _data;

        _data = other._data;
        _length = other._length;

        other._data = nullptr;
        other._length = 0;

        return *this;
    }


    ~MyString() {
        delete[] _data;
    }

    size_t get_length() const {
        return _length;
    }

    void append(const MyString& str) {
        if (str._length == 0) return;

        char* newData = new char[_length + str._length + 1];
        for (size_t i = 0; i < _length; i++) {
            newData[i] = _data[i];
        }
        for (size_t i = 0; i < str._length; i++) {
            newData[_length + i] = str._data[i];
        }
        newData[_length + str._length] = '\0';

        delete[] _data;
        _data = newData;
        _length += str._length;
    }

    MyString substring(int start, int len) const {
        if (start < 0 || start >= _length || len <= 0) {
            return MyString();
        }
        if (start + len > _length) {
            len = _length - start;
        }

        char* subData = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            subData[i] = _data[start + i];
        }
        subData[len] = '\0';
        MyString subString(subData);
        delete[] subData;
        return subString;
    }


    int find(const char* substr) const {
        if (!substr || !_data) return -1;

        for (size_t i = 0; i <= _length; i++) {
            bool found = true;
            for (size_t j = 0; substr[j] != '\0'; j++) {
                if (_data[i + j] != substr[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }

    void to_upper() {
        for (size_t i = 0; i < _length; i++) {
            if (_data[i] >= 'a' && _data[i] <= 'z') {
                _data[i] = _data[i] - ('a' - 'A');
            }
        }
    }

    void print() const {
        if (_data) {
            std::cout << _data << std::endl;
        } else {
            std::cout << "no data" << std::endl;
        }
    }
};

int main() {
    MyString str1("Hello");
    str1.print();

    MyString str2(" World");
    str1.append(str2);
    str1.print();

    MyString sub = str1.substring(6, 5);
    sub.print();

    std::cout << "Index of 'lo': " << str1.find("lo") << std::endl;
    std::cout << "Index of 'notfound': " << str1.find("notfound") << std::endl;

    str1.to_upper();
    str1.print();

    return 0;
}
