#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum class Color { RED, GREEN, BLUE };
enum class Size { SMALL, MEDIUM, LARGE };

struct Product
{
	string name;
	Color color;
	Size size;
};

struct ProductFilter
{
	static vector<Product> by_color(vector<Product> items, Color color)
	{
		vector<Product> result;
		for (auto item : items)
		{
			if (item.color == color)
			{
				result.push_back(item);
			}
		}
		return result;
	}

	static vector<Product> by_size(vector<Product> items, Size size)
	{
		vector<Product> result;
		for (auto& item : items)
		{
			if (item.size == size)
			{
				result.push_back(item);
			}
		}
		return result;
	}

	static vector<Product> by_size(vector<Product> items, Color color, Size size)
	{
		vector<Product> result;
		for (auto& item : items)
		{
			if (item.color == color && item.size == size)
			{
				result.push_back(item);
			}
		}
		return result;
	}
};

int main()
{
	Product apple{ "���", Color::GREEN, Size::SMALL };
	Product tree{ "����", Color::GREEN, Size::LARGE };
	Product horse{ "��", Color::BLUE, Size::LARGE };
	vector<Product> all{ apple, tree, horse };

	vector<Product> greenItems = ProductFilter::by_color(all, Color::GREEN);
	for (const auto& item : greenItems)
	{
		cout << item.name << " is green" << endl;
	}
	vector<Product> largeItems = ProductFilter::by_size(all, Size::LARGE);
	for (const auto& item : largeItems)
	{
		cout << item.name << "is Large size" << endl;
	}
}