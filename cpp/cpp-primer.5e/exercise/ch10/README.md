# Chapter 10 Generic Algorithms
## Exercise 10.1: 
## Exercise 10.2:
## Exercise 10.3:

## Exercise 10.4: 
> Assuming v is a vector<double>, what, if anything, is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?
可以这样操作，第三个参数是int类型,double类型的元素可以与int类型累加。

## Exercise 10.5: 
> In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings?
会比较指针指向的字符数组，即逐一比较两个C-style strings的每个字符是否相等。而不是比较指针地址值是否相等。

##Exercise 10.7: 
> Determine if there are any errors in the following programs and, if so, correct the error(s):
(a)
```cpp
vector<int> vec; list<int> lst; int i;
 while (cin >> i)
     lst.push_back(i);
 copy(lst.cbegin(), lst.cend(), vec.begin());
```
(b)
```cpp
vector<int> vec;
 vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
 fill_n(vec.begin(), 10, 0);
``` 

(a)error. vec is empty.
```cpp
copy(lst.cbegin(, lst.cend(), back_inserter(vec));
```
(b) correct.

## Exercise 10.8: 
> We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?
算法对迭代器而不是容器进行操作，算法不能直接添加或删除元素。而迭代器可以对容器进行操作，back_inserter是一个迭代器。

## Exercise 10.10: 
> Why do you think the algorithms don’t change the size of containers?
算法对迭代器进行操作而不是对容器进行操作，不直接改变容器大小。

## Exercise 10.23: 
> How many arguments does bind take?
bing接收至少2个参数，一个是函数名称，后面一个参数列表，参数列表至少有一个参数。

## Exercise 10.26: 
> Explain the differences among the three kinds of insert iterators.
主要插入元素的位置不同。
**back_inserter** creates an iterator that uses push_back.
**front_inserter** creates an iterator that uses push_front.
**inserter** creates an iterator that uses insert. This function takes a second argument, which must be an iterator into the given container. Elements are inserted ahead of the element denoted by the given iterator.

## Exercise 10.38: 
> List the five iterator categories and the operations that each supports.
输入迭代器(input iterator):可以读取序列中的元素。== !=, ++, \*, ->
输出迭代器(output iterator):只写不读元素。 ++, \*
前向迭代器(forward iterator):可以读写元素。
双向迭代器(bidirectional iterator):可以正向/反向读写序列中的元素。
随机访问迭代器(random-access iterator):提供在常量时间内访问序列中任意元素的能力。

## Exercise 10.39: 
> What kind of iterator does a list have? What about a vector?
list 使用双向迭代器; vector使用随机访问迭代器。

## Exercise 10.40: 
> What kinds of iterators do you think copy requires? What about reverse or unique?
copy前两个参数使用输入迭代器，第三个参数使用输出迭代器;
reverse使用双向迭代器;
unique使用前向迭代器。

## Exercise 10.41: 
> Based only on the algorithm and argument names, describe the operation that the each of the following library algorithms performs:
replace(beg, end, old_val, new_val);            // 替换输入序列中的旧元素为新元素
replace_if(beg, end, pred, new_val);            // 替换输入序列中使条件为真的旧元素为新元素
replace_copy(beg, end, dest, old_val, new_val); // 替换旧元素为新元素后复制到新的序列，原序列不变
replace_copy_if(beg, end, dest, pred, new_val); // 按条件替换旧元素为新元素后复制到新的序列，原序列不变


