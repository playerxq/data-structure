// leetcode-146-list-splice函数用法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache{
public:
	size_t m_capacity;
	unordered_map<int,list<pair<int,int>>::iterator> m_map;
	list<pair<int,int>> m_list;
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
		auto found_it = m_map.find(key);
		if(found_it==m_map.end())
			return -1;
		m_list.splice(m_list.begin(),m_list,found_it->second);
		return found_it->second->second;
    }
    
    void set(int key, int value) {
		auto found_it = m_map.find(key);
		if(found_it!=m_map.end())
		{
			m_list.splice(m_list.begin(),m_list,found_it->second);
			found_it->second->second = value;
			return;
		}
		if(m_map.size()==m_capacity)
		{
			int de = m_list.back().first;
			m_list.pop_back();
			m_map.erase(de);
		}
		m_list.emplace_front(make_pair(key,value));
		m_map[key] = m_list.begin();
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

