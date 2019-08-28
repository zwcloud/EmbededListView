#pragma once
#include <string>
#include <vector>

class MyObject
{
public:
    MyObject(int index, std::string name, std::vector<int> values)
    {
        m_index = index;
        m_name = name;
        m_values.swap(values);
    }

    int m_index;
    std::string m_name;
    std::vector<int> m_values;
};
