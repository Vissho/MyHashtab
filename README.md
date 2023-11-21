# MyHashtab
Implementation of the hashtable structure and analysis of its algorithms.

## Introduction
In this project I wanted to study the hash table and analyze its operations.
One of the simplest and most effective data structures in programming can be considered a hash
table. In it, the functions of adding, searching and deleting an element are performed in constant
time. However, the hash table has its drawbacks. For example, a problem with collisions and
a large amount of allocated memory. A hash table is a data structure that stores all elements as a key-value pair.
Basic operations on a hash table: search, add, delete.

## Advantages and disadvantages of hash tables
Studying hash tables allows you to understand the principles of their operation, analyze the advantages and
disadvantages and choose the right use strategies for optimal implementation in
specific situations.

Advantages:
* Quick access to elements: Hash tables provide almost constant access time to elements, since the search is carried out directly by the index.
* Efficiency: With the right choice of a good hash function and a large enough table, hash tables can be very effective for insertion, deletion and element search operations.
* Flexibility: Hash tables can be used for various types of data and tasks, they can be easily adapted to specific requirements.

Disadvantages:
* Collisions: When using hash tables, collisions are possible when two different keys correspond to the same hash value. Collisions should be manageable and handled efficiently to preserve the performance of the table.
* Memory consumption: Hash tables can consume more memory than other data structures, especially if the table is large or contains many empty slots.
* Hash function dependency: Hash table efficiency strongly depends on the quality of the selected hash function. A bad hash function can lead to a large number of collisions and performance degradation.
* Disordered elements: the elements in the hash table are not ordered, iteration by elements may be unstructured. If ordering of elements is required, then a hash table may not be the most appropriate choice.

## Analysis
Let's do some research to find out which hash functions are better to use. To
the main hash function (KR), we will add four more and compare them for speed and solutions
to the problem with collisions.

Hash functions selected for testing:
* Jenkins hash functions
* The hash function of Dan Bernstein (djb2)
* FNV (Fowler-Noll-Vo)
* KR (Knuth-Rolling)
* ELF

**The result can be viewed in pdf in /graph**

## Conclusion
Summing up all of the above, the hash table has quick access to memory and easily
operates on it, although it takes up a large amount of memory. The main operations are performed in
constant time. The key hashing technique is used, which can be
improved in various ways. There is always a problem with collisions,
a small number of solutions, but with great potential for development. The best hash functions
that can be used in a hash table are KR and djb2 hash functions. Easy to write
code and its implementation in other more complex structures.
