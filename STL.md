# STL用法总结

##  头文件
针对每一种容器，可以单独包含其头文件，比如
```
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
```
也可以使用如下"万能头文件" 
```
#include <bits/stdc++.h>
```
C++ 通常还需要使用标准命名空间和输入输出， 所以完整的头文件包含可以如下：
```
#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
```

## vector
vector容器可以理解我们C语言里的数组， 所有和数组相关的都可以用vector容器
### vector初始化
```
vector<int>  res; 
vector<int>  res(10, 0);  // 定义10个元素的vector， 每个元素都为0
vector<vector<int> > matrix(row, vector<int> (col, 0)); // 二维数组定义， row行,col列， 每一行初始化为0
res.clear() // 清空容器
```
### vector基本操作
#### 添加和删除
```
vector<int> res(10, 0);
// 添加元素
res.push_back(value);  // 在后面添加一个值为value的元素
// 删除元素
res.pop_back() // 删除最后一个元素
```
#### 遍历
```
res.size() // 数组大小

// 使用下标遍历
for (int i = 0;i < res.size();++i) {
    cout << res[i] <<endl;
}
// 使用迭代器遍历
for (auto it = res.begin();it != res.end();++it) {
    cout << *it << endl; 
}
```
#### 使用其它容器赋值
```
res.assign(b.begin(), b.begin()+3); //b为向量，将b的0~2个元素构成的向量赋给res
```

#### 插入元素
```
res.insert(res.begin() + 1, 5); // 在第1个位置(从0开始)插入元素5

res.insert(res.begin() + 1, 3, 5); // 在第1个位置(从0开始)插入3个元素5
```
#### 删除元素
```
res.erase(res.begin() + 1) // 删除第1个元素的, 返回下个迭代器
// 此处需要注意一点， 删除元素时要注意野指针的出现， 例如下面是错误的写法
for (auto it = res.begin(); it != res.end(); ++it)
{
    if (*it % 3==0)
    {
        res.erase(it);
    }
}
// 正确的写法如下
for (auto it = res.begin(); it != res.end(); )
{
    if (*it % 3==0)
    {
        it = res.erase(it);
    }
    else
    {
        ++it;
    }
}
```
#### 排序和反转
```
sort(res.begin(), res.end()); // 排序
reverse(res.begin(), res.end()); // 反转
```
### 例题

## string
string一般用于C++处理字符串, 在使用string类时，我们无需去关心C语言里字符串的'\0'符。

### string 初始化
```
string s; // 默认初始化，一个空字符串
string s5 ="ssss"; 
string s1("ssss"); // s1是字面值“ssss”的副本
string s2(s1); // s2是s1的副本
string s3 = s2; // s3是s2的副本
string s4(10,'c'); //把s4初始化
```
### string常用操作
#### 基本操作
```
string s = s1 + s2;
if (s1 == s2) // 判断字符串相等
string s = s1 + 'a';
string s = 'a' + s1;
```
####遍历
```
for (int i = 0;i < s.size();++i) {
    cout << s[i] << endl;
}
// 输出字符串， 直接 cout << s << endl; 就可以
```
#### 子串截取
```
string s = "abcdefg";
//s.substr(pos1, len)返回字符串位置为pos1开始长度为5的子串, 第二个参数为空表示截取到最后
string s2 = s.substr(1,5); // bcdef
string s3 = s.substr(1); // bcdefg  
```
#### 子串查找

```
int pos = s.find("ss", pos1); 
// 在pos1的位置后(包括pos1)查找子串"ss"的位置， 返回子串的开头的下标， 如果找不到， 返回 -1 或者npos
```
####  字符串插入
```
string str="to be question";
string str2="the ";
// s.insert(pos, str)  在s的pos位置插入str
str.insert(6, str2);                 // to be the question

```
#### 字符串删除
```
str.erase (9, 8);    // 直接指定删除的字符串位置第9个后面的8个字符
str.erase (str.begin()+9); // 删除迭代器指向的字符(第9个字符)
```
## map
map通常是表示键值对的映射， 和哈希表类似
### map常用操作
#### map初始化
```
map <int, int> m; // 表示一个 int -> int 的键值对映射
m[key] = value; // map的某一个key赋值为value
cout << m[key] <<endl; // 打印key对应的值
```
#### map的遍历
```
使用迭代器进行遍历
for (auto it = m.begin();it != m.end();++it) {
    cout << it->first <<" " <<it->second<<endl; // key为first, value为second
}
```
#### map元素查找
```
m.count(k);  // 返回m中键值等于k的元素的个数。
m.find(k);  // 如果m中存在按k索引的元素，则返回指向该元素的迭代器。如果不存在，则返回结束游标end()
if (m.find(key) != m.end()) {  //  找到了
    cout << m[key] << endl;
}
```
## stack
数据结构栈， 后进先出的结构
### 栈的常用操作
```
stack<int> s; // 初始化
s.size()  // 栈的元素个数
s.top()  // 栈顶的元素
s.push()  // 入栈
s.pop()  // 出栈
s.empty() // 栈是否为空
```
### 栈的典型应用


## queue
数据结构队列
### 队列的常用操作
```
queue<int> q;  // 创建一个int型的空队列
q.empty(); // 判断队列是否为空
q.push(s);  // 将变量s从队尾入队
q.pop();  // 将队首元素弹出
q.size();  // 队列中元素的个数
```
### 队列的典型应用


## priority_queue
优先级队列， 即我们通常数据结构里的堆， 始终保持队首元素时队列中所有元素的最大值/最小值
```
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> > q;
```
## set 
集合， 这种数据结构通常用来去除重复的值
```
set<int> a;
a.insert(10);  // 插入一个元素
a.erase(10)  // 删除元素10
for(auto it = a.begin();it != a.end();it++)	{  // 集合遍历，集合不可以通过下标访问
    cout << *it << endl;
}
a.empty()  // 集合为空
a.size()  // 集合大小
a.count(10) // 集合元素的个数
```
通常我们需要将一组元素去重， 可以把这些数依次添加进集合， 然后再把集合转成vector即可
```
vector<int> res;
res.assign(a.begin(), a.end());
```


