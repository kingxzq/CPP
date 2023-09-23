#pragma once
#include<iostream>
using namespace std;
template<class K, class V>
struct HashNode
{
	pair<K, V> _kv;
	HashNode<K, V>* _next;

	HashNode(const pair<K, V>& kv)
		:_kv(kv)
		, _next(nullptr)
	{}
};

template<class K, class V>
class HashTable
{
	typedef HashNode<K, V> Node;
public:

	~HashTable()
	{
		for (size_t i = 0; i < _tables.size(); ++i)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* next = cur->_next;
				free(cur);
				cur = next;
			}
			_tables[i] = nullptr;
		}
	}

	bool Insert(const pair<K, V>& kv)
	{
		// 去重
		if (Find(kv.first))
		{
			return false;
		}

		// 负载因子到1就扩容
		if (_size == _tables.size())
		{
			size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			vector<Node*> newTables;
			newTables.resize(newSize, nullptr);
			// 旧表中节点移动映射新表
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;

					size_t hashi = cur->_kv.first % newTables.size();
					cur->_next = newTables[hashi];
					newTables[hashi] = cur;

					cur = next;
				}

				_tables[i] = nullptr;
			}

			_tables.swap(newTables);
		}

		size_t hashi = kv.first % _tables.size();
		// 头插
		Node* newnode = new Node(kv);
		newnode->_next = _tables[hashi];
		_tables[hashi] = newnode;
		++_size;

		return true;
	}

	Node* Find(const K& key)
	{
		if (_tables.size() == 0)
		{
			return nullptr;
		}

		size_t hashi = key % _tables.size();
		Node* cur = _tables[hashi];
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				return cur;
			}

			cur = cur->_next;
		}

		return nullptr;
	}

	bool Erase(const K& key)
	{
		if (_tables.size() == 0)
		{
			return false; // 哈希表为空，无法删除
		}

		size_t hashi = key % _tables.size();
		Node* cur = _tables[hashi];
		Node* prev = nullptr; // 用于记录当前节点的前一个节点

		// 遍历链表
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				// 找到匹配的节点，进行删除操作
				if (prev)
				{
					prev->_next = cur->_next; // 从链表中移除当前节点
				}
				else
				{
					// 如果当前节点是链表的头节点，则更新哈希桶的头指针
					_tables[hashi] = cur->_next;
				}

				delete cur; // 释放当前节点的内存
				--_size;    // 减少有效数据个数
				return true; // 删除成功
			}

			prev = cur;
			cur = cur->_next; // 移动到下一个节点
		}

		return false; // 未找到匹配的键，删除失败
	}

private:
	vector<Node*> _tables;
	size_t _size = 0; // 存储有效数据个数
};
