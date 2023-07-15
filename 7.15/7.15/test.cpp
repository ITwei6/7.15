#include "test.h"


void Test1()
{
    tao::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (auto e : v)
	{
		cout << e;
	}
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << ++v[i];
	}
}

int main()
{
	Test1();
}



