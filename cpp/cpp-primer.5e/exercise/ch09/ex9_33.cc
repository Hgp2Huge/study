#include <vector>

using std::vector;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5};
    auto begin = v.begin();
    // an endless loop
    while (begin != v.end()) {
        ++begin;
        v.insert(begin, 42); // begin is invalide after insert
        ++begin;
    }

    return 0;
}
