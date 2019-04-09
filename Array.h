#pragma once
template <class ObjectType>
class Array
{
private:
	int length;
	ObjectType *objectArray;
public:
	Array(int setLength)
	{
		length = setLength;
		objectArray = new ObjectType[setLength];
	}
	~Array()
	{
		delete[] objectArray;
		objectArray = nullptr;
	}
	ObjectType &get(int get)
	{
		return *(objectArray + get);
	}
	void set(int set, ObjectType data)
	{
		*(objectArray + set) = data;
	}
	int getLength()
	{
		return length;
	}
	ObjectType &operator[] (int x)
	{
		return get(x);
	}
};
