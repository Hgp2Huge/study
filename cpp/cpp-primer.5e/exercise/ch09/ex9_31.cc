#include <iostream>
#include <list>
#include <forward_list>

using std::list; using std::forward_list;

void remove_even_copy_odd_on_list(list<int>& li)
{
    for (auto iter = li.begin(); iter != li.end(); ) {
        if (*iter % 2) {
            iter = li.insert(iter, *iter);
            iter++;
            iter++;
        }
        else {
            iter = li.erase(iter);
        }
    }
}

void remove_even_copy_odd_on_forward_list(forward_list<int>& fli)
{
    for (auto prev = fli.before_begin(), curr = fli.begin();
            curr != fli.end(); ) {
        if (*curr % 2) {
            curr = fli.insert_after(curr, *curr);
            prev = curr++;
        } else {
            curr = fli.erase_after(prev);
        }
    }
}

int main()
{
     list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
     forward_list<int> fli(li.cbegin(), li.cend());

     remove_even_copy_odd_on_list(li);
     remove_even_copy_odd_on_forward_list(fli);

     for (const auto i : li)
         std::cout << i << " ";
     std::cout << std::endl;
     for (const auto i : fli)
         std::cout << i << " ";
     std::cout << std::endl;

     return 0;
}
