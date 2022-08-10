#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Shape 
{

};

class Rectangle : public Shape
{

};

template<typename T>
T add(T a, T b)
{
	if (a < 0 || b < 0) return -1;
	return a + b;
}

template<typename E>
struct Array {
	E* _array; //파라미터 변수로 봄
	int _size;

	Array(int size) : _array(new E[size]), _size(size) //: 값이 두번 대입되는 거를 방지
	{}
	~Array()
	{
		if (_array != NULL)
		{
			delete[] _array;
		}
	}
	void setAt(int idx, E value)
	{
		if (0 > idx || idx >= _size) return;
		_array[idx] = value;
	}
	int getAt(int idx)
	{
		if (0 > idx || idx >= _size) return;
		return _array[idx];
	}
};

int main()
{
	Array<int> array_1(10);
	Array<float> array_2(20.2);

	int a = 'A';

	char ch = static_cast<char>(a);

	vector<int> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40; //정적
	arr.size(); //4

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30); //동적
	arr.size(); //7

	int arr2[] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++)
	{
		cout << i << " = " << arr2[i] << endl;
	}//개발자의 책임

	for (const auto& value : arr2)//배열안의 타입을 자동적으로 추론, const는 논리에 짚고 넘어감
	{
		//value += 10; 처럼 바디에 실수로 넣어주면 안됨(개발자 책임)
		cout << " = " << value << endl;
	}//Access가 빠름, &:참조만 해서 호출

	//맨 앞에만 대입 가능

	//
	cout << "ch = " << ch << endl;

	cout << a << ", " << ch << endl;

	array_1.setAt(0, 10);

	int sum = 0;
	int x, y;
	cin >> x >> y;
	sum = add(x, y);


	return 0;
}

