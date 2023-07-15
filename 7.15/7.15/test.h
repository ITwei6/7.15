#pragma once

#include <string.h>
//vector��ģ��ʵ��
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
namespace tao
{
	template <class T>//����һ��ģ��T
	class vector
	{
		typedef T* iterator;//��T* ������Ϊiterator
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
		//��Ա����
		vector()//��ֵ����
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
				T* temp = new T[n];//���ȿ��ռ�
				if (_start != nullptr)
				{
					//�����ݿ�����tempȥ
					memcpy(temp, _start, sizeof(T) * sz);
					//ɾ��ԭ���ռ�
					delete[] _start;
				}
				//��󽫿ռ丳ֵ��_start
				_start = temp;
				_finish = _start + sz;
				//������һ�����⣬size()�ļ�������_finish -start �������start�Ѿ��ı䣬��finish��û�иı�
				//������finish�ͱ�ɿ��ˣ����յ���������start�ı��ˣ�������֮ǰҪ����һ��size()������
				_endstroage = _start + n;
			}
		}
		void push_back(const T& val)
		{
			//����Ҫ�����Ƿ�����
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
       //��Ա����
		iterator _start;//ָ��ͷλ�õĵ�����
		iterator _finish;//ָ����ʵ���ݵ����λ��
		iterator _endstroage;//ָ�������ĵ����λ��

	};

}