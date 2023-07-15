#pragma once

#include <string.h>
//vector的模拟实现
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
namespace tao
{
	template <class T>//定义一个模板T
	class vector
	{
		typedef T* iterator;//将T* 重命名为iterator
		typedef const T* const_iterator;
	public:
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		//成员函数
		vector()//空值构造
			: _start(nullptr)
			, _finish(nullptr)
			, _endstroage(nullptr)
		{}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endstroage = nullptr;
			}
		}
		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* temp = new T[n];//首先开空间
				if (_start != nullptr)
				{
					//将数据拷贝到temp去
					memcpy(temp, _start, sizeof(T) * sz);
					//删除原来空间
					delete[] _start;
				}
				//最后将空间赋值给_start
				_start = temp;
				_finish = _start + sz;
				//这里有一个问题，size()的计算是用_finish -start 而这里的start已经改变，而finish还没有改变
				//最后计算finish就变成空了，最终的问题在于start改变了，所有在之前要保留一份size()的数据
				_endstroage = _start + n;
			}
		}
		void push_back(const T& val)
		{
			//首先要考虑是否扩容
			if (_finish == _endstroage)
			{
				size_t newcapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newcapacity);
			}
			*_finish = val;
			++_finish;

		 }
		size_t capacity() const
		{
			return _endstroage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			return _start[pos];
		}
	private:
       //成员变量
		iterator _start;//指向开头位置的迭代器
		iterator _finish;//指向真实数据的最后位置
		iterator _endstroage;//指向容量的的最后位置

	};

}