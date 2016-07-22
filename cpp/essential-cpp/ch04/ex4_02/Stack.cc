#include "Stack.h"

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::find; using std::count;

bool Stack::pop(string &elem)
{
    if (empty())
        return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(string &elem)
{
    if (empty())
        return false;
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem)
{
    if (full())
        return false;
    _stack.push_back(elem);
    return true;
}

bool Stack::find(const string &elem) const
{
    vector<string>::const_iterator end = _stack.cend();
    return ::find(_stack.cbegin(), _stack.cend(), elem) != end;
}

int Stack::count(const string &elem) const
{
    return ::count(_stack.cbegin(), _stack.cend(), elem);
}
