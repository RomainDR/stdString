#include "String.h"
#include <string>
#include <iostream>

#pragma warning(disable: 4996)

String::String(const char* _value)
{
    const int _otherLength = strlen(_value);
    const int& _length = length;
    const int _newLength = _length + _otherLength;
    char* _char = new char[_newLength + 1];
    // ReSharper disable CppDeprecatedEntity
    strcpy(_char, value);
    // ReSharper disable once CppDeprecatedEntity
    strcat(_char, _value);
    value = _char;
    length = _newLength;
}

String::String(const String& _copy)
{
	value = _copy.value;
    length = _copy.length;
}

String String::ToLower() const
{
    const char* _str = value;
    char* _newStr = new char[length];
    for (int i = 0; i < length;i++)
    {
        if ((int)_str[i] >= 65 && (int)_str[i] <= 90)
            _newStr[i] = (char)((int)_str[i] + 32);
        else
            _newStr[i] = _str[i];
    }
    _newStr[length] = '\0';
    return _newStr;
}

String String::ToUpper() const
{
    const char* _str = value;
    char* _newStr = new char[length];
    for (int i = 0; i < length;i++)
    {
        if ((int)_str[i] >= 97 && (int)_str[i] <= 122)
            _newStr[i] = (char)((int)_str[i] - 32);
        else
            _newStr[i] = _str[i];
    }
    _newStr[length] = '\0';
    return _newStr;
}

String String::SubString(const int& _begin)
{
    return SubString(_begin, length);
}

String String::SubString(const int& _begin, const int& _end)
{
    const char* _str = value;
    char* _string = new char[_end - _begin];
    for (int i = _begin; i < _end;i++)
        _string[i - _begin] = _str[i];
    _string[_end - _begin] = '\0';
    return _string;
}

String String::Replace(const char _oldChar, const char _newChar) const
{
    char* _str = new char[length];
    for (int i = 0; i < length; i++)
        if (value[i] == _oldChar)
            _str[i] = _newChar;
        else
            _str[i] = value[i];
    _str[length] = '\0';
    return _str;
}

String String::Replace(const std::string _oldStr, const std::string _newStr) const
{
   
}

String String::Trim() const
{
    int _length = length;
    int numSpace = 0;
    char* _str = new char[length];
    for (int i = 0; i < length; i++)
    {
        if (value[i] == ' ')
        {
            numSpace++;
            _length--;
            char* _str2 = _str;
            _str = new char[_length];
            _str = _str2;
        }
        else
            _str[i-numSpace] = value[i];
    }
    _str[_length] = '\0';
    return _str;
}

bool String::Contains(const char* _value)
{
    if (_value == nullptr) throw std::exception("nullptr value");
    int _size = 0;
    while (_value[_size] != 0)
        _size++;
    int y = 0;
    for (int i = 0; i < length; i++) {
        if (value[i] == _value[y])
        {
            y++;
            if (y == _size)
                return true;
        }
        else
            y = 0;
    }
    return false;
}

std::vector<String> String::Split(const char& _char)
{   
    std::vector<String> _str = std::vector<String>();
    int _start = -1;
    std::vector<int> positionChar = std::vector<int>();

    for (int i = 0; i < length; i++)
    {
        if (value[i] == _char)
            positionChar.push_back(i);
    }
    
    for (int i = 0; i < positionChar.size(); i++)
    {
        _str.push_back(SubString(_start + 1, positionChar[i]));
        _start = positionChar.at(i);
    }
    _str.push_back(SubString(positionChar[positionChar.size() - 1] +1));
    return _str;
    
    return _str;
}


int String::LastIndexOf(const char _char) const
{
    int _lastIndex = -1;
    for (int i = 0;i < length; i++)
        if (value[i] == _char)
            _lastIndex = i;
    return _lastIndex;
}

int String::FirstIndexOf(const char _char) const
{
    for (int i = 0; i < length; i++)
        if (value[i] == _char)
            return i;
    return -1;
}

int String::Length() const
{
    return length;
}

bool String::IsNullOrEmpty() const
{
    return value == nullptr || length == 0;
}

String String::Join(const std::vector<String>& _str) const
{
    size_t _size = _str.size();
    int _currentIndex = 0;
    int _newLength = length;
    for (int i = 0; i < _size; i++)
        _newLength += _str.at(i).length;
    char* _string = new char[_newLength + _size];
    for (int i = _currentIndex; i < length; i++) {
        _string[i] = value[i];
        _currentIndex = i;
    }
    for (int i = 0; i < _size; i++)
    {
        String _s = _str.at(i);
        int _length = _s.length;
        for (int i = _currentIndex, y = 0; y < _length; i++, y++) {
            _string[i] = _s.value[y];
            _currentIndex = i + 1;
        }
        _string[_currentIndex] = '\0';
    }
    return _string;
}


String::operator const char* ()
{
    return value;
}


