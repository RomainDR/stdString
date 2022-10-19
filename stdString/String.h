#pragma once
#include <vector>
#include <ostream>
class String
{
private:
	const char* value = "";
	int length = 0;

public:
	String() = default;
	String(const char* _value);
	String(const String& _copy);


private:
public:
	bool Contains(const char* _value); //ok
	std::vector<String> Split(const char& _char); //ok
	String ToLower() const; //ok
	String ToUpper() const; //ok
	String SubString(const int& _begin); //ok
	String SubString(const int& _begin, const int& _end); //ok
	String Replace(const char _oldChar, const char _newChar) const;  //ok
	String Trim() const; //ok
	int LastIndexOf(const char _char) const; //ok
	int FirstIndexOf(const char _char) const; //ok
	int Length() const; //ok
	bool IsNullOrEmpty() const; //ok
	String Join(const std::vector<String>& _str) const; //ok



	operator const char*();
};

