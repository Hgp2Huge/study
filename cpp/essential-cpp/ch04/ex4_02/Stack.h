#include <string>
#include <vector>

class Stack {
public:
    bool push(const std::string&);
    bool pop(std::string&);
    bool peek(std::string&);

    bool empty();
    bool full();

    int size() { return _stack.size(); }

    bool find(const std::string&) const;
    int count(const std::string&) const;

private:
    std::vector<std::string> _stack;
};

inline bool Stack::empty()
{
    return _stack.empty();
}

inline bool Stack::full()
{
    return _stack.size() == _stack.max_size();
}


