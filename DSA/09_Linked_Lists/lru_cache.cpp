// lc - 146
#include <bits/stdc++.h>
using namespace std;

// using vector - TLE
vector<pair<int, int>> cache;
int n;
LRUCache(int capacity)
{
    n = capacity;
}

int get(int key)
{
    for (int i = 0; i < cache.size(); i++)
    {
        if (cache[i].first == key)
        {
            int value = cache[i].second;
            auto temp = cache[i];
            cache.erase(cache.begin() + i);
            cache.push_back(temp);
            return value;
        }
    }
    return -1;
}

void put(int key, int value)
{
    for (int i = 0; i < cache.size(); i++)
    {
        if (cache[i].first == key)
        {
            cache.erase(cache.begin() + i);
            cache.push_back({key, value});
            return;
        }
    }
    if (cache.size() == n)
    {
        cache.erase(cache.begin());
        cache.push_back({key, value});
    }
    else
    {
        cache.push_back({key, value});
    }
}


// optimal

int n;
map<int, pair<list<int>::iterator, int>> mp;
list<int> dll;
LRUCache(int capacity)
{
    n = capacity;
}

void makeRecentlyUsed(int Key)
{
    dll.erase(mp[Key].first);
    dll.push_front(Key);
    mp[Key].first = dll.begin();
}
int get(int key)
{
    if (mp.find(key) == mp.end())
    {
        return -1;
    }
    makeRecentlyUsed(key);
    return mp[key].second;
}

void put(int key, int value)
{
    if (mp.find(key) != mp.end())
    {
        mp[key].second = value;
        makeRecentlyUsed(key);
    }
    else
    {
        dll.push_front(key);
        mp[key] = {dll.begin(), value};
        n--;
    }
    if (n < 0)
    {
        int keyToDel = dll.back();
        mp.erase(keyToDel);
        dll.pop_back();
        n++;
    }
}