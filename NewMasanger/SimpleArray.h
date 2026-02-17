#pragma once
#include <memory>

template<typename T, int MAX_COUNT>
class SimpleArray {
private:
    std::unique_ptr<T> items[MAX_COUNT];
    int count;

public:
    SimpleArray() : count(0) {}

    ~SimpleArray() {}

    bool Add(std::unique_ptr<T> item)
    {
        if (count >= MAX_COUNT) return false;
        items[count] = std::move(item);
        count++;
        return true;
    }

    int Size() const { return count; }

    T* Get(int index)
    {
        if (index < 0 || index >= count) return nullptr;
        return items[index].get();
    }

    const T* Get(int index) const
    {
        if (index < 0 || index >= count) return nullptr;
        return items[index].get();
    }

    void Clear()
    {
        count = 0;
    }
};