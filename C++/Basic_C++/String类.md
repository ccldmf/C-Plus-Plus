* string类模板类

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**typedef basic_string &lt;char&gt; string;**

​		使用时包含头文件：

```
	#include <string>
```

* 特点：

    * string对象的长度用成员函数length()读取。

    * string支持流读取运算符。

    * string支持getline函数。

    * 用=赋值。

    * 用assign成员函数复制。

    * 用assign成员函数部分复制。

    * 逐个访问string对象中的字符，可以使用s.at(i)和s[i]，区别是at会做范围检查，超出范围，会抛出out_of_range异常，而[]不做范围检查。

    * 用+运算符连接字符串。

    * 用append连接字符串。

    * 用==,>=,<=,>,<进行比较，也可用compare函数进行比较。

    * substr函数返回指定的开始，结束的字符串。

    * find查找一个字符串的位置。

    * erase删除string中的字符

    * replace替换string中的字符

    * insert插入字符串

    * c_str转换成C语言的char*字符串
    * string str;  str只是定义，没有初始化，编译器将默认赋值为""，即空字符串
        string str1 = "hello world",str1结尾没有`\0`,这和C风格的字符串不同