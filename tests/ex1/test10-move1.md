Move Semantics
===============

C++ has a special kind of reference (denoted &&) called *r-value reference*.
While the usual reference (denoted with a single &) is actually called *l-value reference*.

First toy example
------------------

Let us take the following code as example.
```C++
void my_function(std::string&& s)
{
  // Something the 
}
void my_function(std::string const& s)
{
  // Something
}

int main () 
{
  std::string hello = "Hello world";
  my_function(std::move(hello)); // we use std::move() to make a r-value reference.
}
```
A &&-reference is like a &-reference but with the extra meaning that the referenced object (`s`) is unimportant to the caller (`main`), often because it is about to be deleted.
C++ uses the &&-reference to implement *move semantics* meaning that the called function (`my_function`) is allowed to *steal the content* of the argument.

Here for instance, 
- nothing happens in `main` after the call to `my_function` hence the string `hello` will be destroyed anyway; 
- the program has two versions of `my_function`, one uses the type `std::string&&` meaning that `my_function` can benefit from stealing the content of the passed `std::string`

Hence, it makes sense to choose the version `my_function` using &&-reference.


Real example: concatenation of `std::list`
------------------------------------
The strengh of `std::list` is that concatenation may be done in constant time. Indeed `std::list` is a doubly-linked list hence consider the two lists below.

- `list1=`  null <-> 0 <-> 1 <-> 2 <-> null
- `list2=`  null <-> 4 <-> 5 <-> 6 <-> null

We want to concatenate `list2` at the end of `list1`, in order to obtain the following list.

- null <-> 0 <-> 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> null

This can be done in constant time by:

- changing the forward pointer of 2 to 4
- changing the backward pointer from 4 to 2.

Howevever, we just used the content of `list2` in such a way that makes `list2` invalid.
- We can make this concatenation in constant time only if we are allowed to *destroy* one of `list1` or `list2`.
- Otherwise, we can still do it, it will be linear in the length of `list2`

This is a typical case where *move semantics* and an *r-value reference* allow to express what we want.
In file [concatenate.hpp]("../concatenate.hpp"), we define two functions that concatenate `list2` at the end of `list1`.
```C++
//                                                    vv r-value reference
void concatenate(std::list<int>& list1, std::list<int>&& list2);
//                             ^
//      list1 is an l-value reference because we will modify it
//                             v
void concatenate(std::list<int>& list1, const std::list<int>& list2);
//                                      ^^^^^               ^ const l-value reference
```
- If we use the first function, `list1` will *steal the content* of `list2`.
- If we use the second function, `list1` will *copy* the content `list2`.

Look and execute [test11](test11-splice.cpp) for an example.



