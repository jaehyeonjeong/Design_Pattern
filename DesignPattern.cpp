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
	E* _array; //�Ķ���� ������ ��
	int _size;

	Array(int size) : _array(new E[size]), _size(size) //: ���� �ι� ���ԵǴ� �Ÿ� ����
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
	arr[3] = 40; //����
	arr.size(); //4

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30); //����
	arr.size(); //7

	int arr2[] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++)
	{
		cout << i << " = " << arr2[i] << endl;
	}//�������� å��

	for (const auto& value : arr2)//�迭���� Ÿ���� �ڵ������� �߷�, const�� ���� ¤�� �Ѿ
	{
		//value += 10; ó�� �ٵ� �Ǽ��� �־��ָ� �ȵ�(������ å��)
		cout << " = " << value << endl;
	}//Access�� ����, &:������ �ؼ� ȣ��

	//�� �տ��� ���� ����

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

