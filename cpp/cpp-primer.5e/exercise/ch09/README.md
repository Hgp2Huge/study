# Chapter 9. Sequential Containers

## Exercise 9.1: 
> Which is the most appropriate—a vector, a deque, or a list—for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.
> * (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.
> *(b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
> * (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

(a) list, 需要在容器中间插入元素
(b) deque, 只需要在容器首尾插入和删除元素
(c) vector, 排序操作使用vector最方便。不需要在首尾插入或删除元素，无需使用deque；对于int型数据，如果使用list，指针数据占用的空间与数据空间几乎相当。

## Exercise 9.2: 
> Define a list that holds elements that are deques that hold ints.
std::list<std::deque<int>> list_hold_deque_of_int;

## Exercise 9.3: 
> What are the constraints on the iterators that form iterator ranges?
1. begin,end必须指向相同的容器
2. end不在begin之前

## [Exercise 9.4: ](ex9_04_05.cc)
## Exercise 9.5:
## Exercise 9.6: 
> What is wrong with the following program? How might you correct it?
```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
                    iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```
std::list 实际上是双链表实现的。链表的各个节点并不是连续存储的。没有'<'操作.
应该这样写:
    while (iter != iter2)

## Exercise 9.7:
> What type should be used as the index into a vector of ints?
std::vector<int>::reference
 
## Exercise 9.8: 
> What type should be used to read elements in a list of strings? To write them?
read only:
std::list<std::string>::const_reference or
std::list<std::string>::const_iterator
write:
std::list<std::string>::reference or
std::list<stdLLstring>::iterator

## Exercise 9.9: 
> What is the difference between the begin and cbegin functions?
begin()获取的迭代器属于iterator类型，可以对元素读写;
cbegin()获取的迭代器属于const_iterator类型，属于只读。

## Exercise 9.10: 
> What are the types of the following four objects?
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

it1 vector<int>::iterator; it2 vector<int>::const_iterator;
it3 vector<int>::const_iterator; it4 vector<int>::const_iterator;

## Exercise 9.11: 
> Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.
```cpp
vector<string> s0;
vector<string> s1{"Henry", "Peter", "John"};
vector<string> s2(s1);
vector<string> s3(s1.begin(), s1.end());
vector<string> s4(10, "Henry");             // 10个Henry

vector<int> i;
vector<int> i1{1, 2, 3, 4, 5, 6};
vector<int> i2(i1);
vector<int> i3(i1.begin(), i1.end());
vector<int> i4(10);                         // 10个0,构造函数默认初始化
vector<int> i5(10, 2);                      // 10个2

```
 
## Exercise 9.12: 
> Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.
从容器构造，要求容器类型和元素类型都一样；
从迭代器范围构造，只需要元素类型相容。
 
## Exercise 9.13: 
## Exercise 9.17: 
> Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?
    if (c1 < c2)

必须是同一种容器，且只有元素类型也定义了'<'运算符时，才可以进行比较。 

## Exercise 9.21: 
> Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.

插入之前需要先移动已有的元素，腾出一个空间。
插入元素后返回当前插入元素的位置。

## Exercise 9.22: 
> Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?
```cpp
vector<int>::iterator iter = iv.begin(),
                      mid = iv.begin() + iv.size()/2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```
1、迭代器没有自增运算，循环无法结束。
2、插入元素后，原来的迭代器将会失效,需要重新返回迭代器的值
另外，不确定这个mid到底是要用固定不变的值，还是要随vector变化的值。

## Exercise 9.23: 
> In the first program in this section on page 346, what would the values of val, val2, val3, and val4 be if c.size() is 1?
```cpp
// check that there are elements before dereferencing an iterator or calling front or back
if (!c.empty()) {
    // val and val2 are copies of the value of the first element in c
    auto val = *c.begin(), val2 = c.front();
    // val3 and val4 are copies of the of the last element in c
    auto last = c.end();
    auto val3 = *(--last); // can't decrement forward_list iterators
    auto val4 = c.back();  // not supported by forward_list
}```

四个值相等

## Exercise 9.24: 
> Write a program that fetches the first element in a `vector` using `at`, the subscript operator, `front`, and `begin`. Test your program on an empty `vector`.

运行时异常'std::out_of_range'

## Exercise 9.25: 
> In the program on page 349 that erased a range of elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?
```cpp
// delete the range of elements between two iterators
// returns an iterator to the element just after the last removed element
elem1 = slist.erase(elem1, elem2); // after the call elem1 == elem2
```
if elem1 == elem2, delete no element.
if elem2 is off-the-end, after erase , elem1 is off-the-end.
if elem1 and elem2 are both off-the-end, delete none element, elem1 is off-the-end.

## Exercise 9.29: 
> Given that vec holds 25 elements, what does vec.resize(100) do? What if we next wrote vec.resize(10)?
vec.resize(100),调整vec，，增加元素到100个，对新元素进行值初始化。
vec.resize(10)，丢弃多出的元素。

## Exercise 9.30: 
> What, if any, restrictions does using the version of resize that takes a single argument place on the element type?
元素类型element type必须能进行初始化。

## Exercise 9.32: 
> In the program onpage 354 would it be legal to write the call to insert as follows? If not, why not?
    iter = vi.insert(iter, *iter++);
不合法。在插入元素之后，iter已经失效。再进行自增运算是未定义的操作。

## Exercise 9.33: 
> In the final example in this section what would happen if we did not assign the result of insert to begin? Write a program that omits this assignment to see if your expectation was correct.
begin 将永远无法等于v.end()，循环无法结束。
插入的元素位于当前begin的前面，因此当前的begin已经失效，如果不更新begin的值，后面的自增运算将是未定义的。

## Exercise 9.34: 
> Assuming vi is a container of ints that includes even and odd values, predict the behavior of the following loop. After you’ve analyzed this loop, write a program to test whether your expectations were correct.
```cpp
iter = vi.begin();
while (iter != vi.end())
    if (*iter % 2)
        iter = vi.insert(iter, *iter);
    ++iter;
```
无限循环。
如果第一个数是偶数，循环一直判断iter是否是v.end(), 而iter一直是是初始的那个迭代器。
如果第一个数是奇数，循环在第一个奇数位置之前无限插入该奇数, 插入元素后iter指向第一个奇数。

## Exercise 9.35: 
> Explain the difference between a vector’s capacity and its size.
size指已经保存的元素的数量。
capacity指在不分配新空间的前提下可以保存元素的数量。

## Exercise 9.36: 
> Can a container have a capacity less than its size?
不能。

## Exercise 9.37: 
> Why don’t list or array have a capacity member?
list存储并不是连续的，添加元素时随机存储，没有容量限制。
array是固定大小的，声明时大小就已经固定，不能再改变。

## Exercise 9.39: 
> Explain what the following program fragment does:
```cpp
vector<string> svec;
svec.reserve(1024);                         // 分配能容纳1024个string元素的内存空间
string word;
while (cin >> word)
        svec.push_back(word);               // 读取string存入, 如果需要的内存空间超过1024，会重新分配内存空间
svec.resize(svec.size()+svec.size()/2);     // 调整大小至存储元素数目的1.5倍,增加的元素初始化位空字符串
```

## Exercise 9.40: 
> If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1,000? 1,048?

| words  | size   | capacity | note                                        |
| ------ | ------ | -------  | ------                                      |
| 256    | 384    | 1024     | 未用完预留空间                              |
| 512    | 768    | 1024     | 未用完预留空间                              |
| 1000   | 1500   | 2000     | resize()时重新分配内存空间,依赖于标准库实现 |
| 1048   | 1572   | 2048     | 添加第1025个元素时重新分配内存空间,容量翻倍 |

## Exercise 9.42: 
> Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?
提前给string 申请至少大于100的内存空间。


## Exercise 9.48: 
> Given the definitions of name and numbers on page 365, what does numbers.find(name) return?
```cpp
string numbers("0123456789"), name("r2d2");
// returns 1, i.e., the index of the first digit in name
auto pos = numbers.find_first_of(name);
```
返回pos = 2, numbers中2的下标。
