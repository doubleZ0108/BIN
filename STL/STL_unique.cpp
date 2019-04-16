/*
序列    6	2	3	1	3	2	4	2	3
sort	 1 2 2 2 3 3 3 4 6
unique 1 2 3 4 6 2 2 3 3

只有前5个数是我们需要的, 则 排序 => unique => erase
*/

//unique会返回一个迭代器，指向的是去重后的最后一个有效元素的后面一个位置

sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
