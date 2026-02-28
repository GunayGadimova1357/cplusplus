#include <iostream>

class MyString {
private:
    char* _data;
    size_t _length;

public:
    static size_t instance_count;

    MyString()  {
       _data = nullptr;
        _length = 0;
        instance_count++;
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
        }
        instance_count++;
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
        instance_count++;
    }

    MyString(MyString&& other) noexcept : _data(other._data), _length(other._length) {
        other._data = nullptr;
        other._length = 0;
        instance_count++;
    }

    MyString& operator=(MyString other) {
        delete[] _data;

        _data = other._data;
        _length = other._length;

        other._data = nullptr;
        other._length = 0;

        return *this;
    }

    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _length = other._length;

            other._data = nullptr;
            other._length = 0;
        }
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
    MyString operator+(const MyString& other) const {
        MyString result;
        result._length = _length + other._length;
        result._data = new char[result._length + 1];

        for (size_t i = 0; i < _length; i++) {
            result._data[i] = _data[i];
        }
        for (size_t i = 0; i < other._length; i++) {
            result._data[_length + i] = other._data[i];
        }
        result._data[result._length] = '\0';

        return result;
    }

    bool operator==(const MyString& other) const {
        if (_length != other._length) {
            return false;
        }
        for (size_t i = 0; i < _length; i++) {
            if (_data[i] != other._data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const MyString& other) const {
        return !(*this == other);
    }

    MyString& operator+=(const MyString& other) {
        if (other._length == 0) {
            return *this;
        }
        char* newData = new char[_length + other._length + 1];
        for (size_t i = 0; i < _length; i++) {
            newData[i] = _data[i];
        }
        for (size_t i = 0; i < other._length; i++) {
            newData[_length + i] = other._data[i];
        }

        newData[_length + other._length] = '\0';

        delete[] _data;
        _data = newData;
        _length += other._length;

        return *this;
    }
    MyString operator*(int n) const {
        if (n <= 0) {
            return MyString();
        }

        MyString result;
        result._length = _length * n;
        result._data = new char[result._length + 1];

        for (int i = 0; i < n; i++) {
            for (size_t j = 0; j < _length; j++) {
                result._data[i * _length + j] = _data[j];
            }
        }

        result._data[result._length] = '\0';
        return result;
    }

    MyString operator/(size_t CharsToRemove) const {
        size_t newLength = (_length > CharsToRemove) ? (_length - CharsToRemove) : 0;
        MyString result;
        result._length = newLength;
        result._data = new char[newLength + 1];
        for (size_t i = 0; i < newLength; i++) {
            result._data[i] = _data[i];
        }
        result._data[newLength] = '\0';
        return result;
    }

};
size_t MyString::instance_count=0;

int main() {
    std::cout<<"print str1: ";
    MyString str1("Hello");
    str1.print();
    std::cout<<"append str2 to 1 ";
    MyString str2(" World");
    str1.append(str2);
    str1.print();
    std::cout<<"substring: ";
    MyString sub = str1.substring(6, 5);
    sub.print();

    std::cout << "Index of 'lo': " << str1.find("lo") << std::endl;
    std::cout << "Index of 'notfound': " << str1.find("notfound") << std::endl;
    std::cout<<"upper: ";
    str1.to_upper();
    str1.print();
    std::cout<<"-------------------"<<std::endl;
    std::cout<<"+ op: ";
    MyString str1_1("Hello");
    MyString str2_2(" World");
    MyString str3 = str1_1 + str2_2;
    str3.print();

    if (str1 == str2) {
        std::cout << "str1 and str2 are equal" << std::endl;
    }
    if (str1 == str3) {
        std::cout << "str1 and str3 are equal" << std::endl;
    } else {
        std::cout << "str1 and str3 are not equal" << std::endl;
    }
    if (str1 != str3) {
        std::cout << "str1 and str3 are not equal" << std::endl;
    }
    MyString str1_0("Hello");
    MyString str2_0(" World");
    std::cout<<"-------------------"<<std::endl;
    str1_0 += str2_0;
    str1_0.print();
    std::cout<<"-------------------"<<std::endl;
    MyString str1_2("Hello");
    MyString repeated = str1_2 * 3;
    repeated.print();
    std::cout<<"-------------------"<<std::endl;
    MyString str1_3("HelloWorld");
    MyString shortened = str1_3 / 5;
    shortened.print();
    return 0;
}


