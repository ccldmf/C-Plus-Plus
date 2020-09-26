 # C++_9-2-map-multimap关联容器

 map/multimap容器里放的都是pair模板类的对象。

multimap中的元素由<关键字,值>组成，**每个元素是一个pair对象**，关键字就是first成员变量，其类型是Key。

multimap中**允许多个元素的关键字相同**。元素按照first成员变量从小到大排列，缺省情况下用less<Key>定义关键字的“小于”关系。

**multimap举例：**
```
int main()
{
       typedef **multimap**<int, double, less<int> > mmid;
       mmid pairs;
       cout << "1)" << pairs.count(15) << endl;
       pairs.insert(mmid::value_type(15, 2.7));
       pairs.insert(mmid::value_type(15, 99.3));
       cout << "2)" << pairs.count(15) << endl;
       pairs.insert(mmid::value_type(30, 11.11));
       pairs.insert(mmid::value_type(10, 222.2));

       for (mmid::const_iterator i = pairs.begin(); i != pairs.end(); i++)
       {
              cout << "(" << i->first << "," << i->second << ")," ;
       }
       cout << endl;
       return 0;
}
```
map中的**元素都是pair模板类对象**。**关键字(first成员变量)各不相同**。元素按照关键字从小到大排列，缺省情况下用less<key>,即<定义“小于”。

**map有[]成员函数.**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**注意**: **pairs[key]**,返回对关键字等于key的元素的值的引用。若没有关键字key的元素，则会往pairs里插入一个关键字key的元素，其值用无参构造函数初始化，并返回其值的引用。

**map举例：**
```
template <class key, class value>

ostream& operator <<(ostream& ostr, const pair<key, value>& p)
{
       ostr << "(" << p.first << "," << p.second << ")";
       return ostr;
}

int main()
{
       typedef **map**<int, double, less<int> > mmid;
       mmid pairs;
       cout << "1)" << pairs.count(15) << endl;
       pairs.insert(mmid::value_type(15, 2.7));
       pairs.insert(**make_pair**(15, 99.3));
       cout << "2)" << pairs.count(15) << endl;
       pairs.insert(mmid::value_type(30, 11.11));
       pairs.insert(mmid::value_type(10, 222.2));
       cout << "3)";

       for (mmid::const_iterator i = pairs.begin(); i != pairs.end(); i++)
       {
              cout << *i<<"," ;
       }

       cout << endl;
       cout << "4)";
       int n = **pairs[40]**;

       for (mmid::const_iterator i = pairs.begin(); i != pairs.end(); i++)
       {
              cout << *i << ",";
       }
       cout << endl;
       cout << "5)";
       **pairs[15] = 6.25**;

       for (mmid::const_iterator i = pairs.begin(); i != pairs.end(); i++)
       {
              cout << *i << ",";
       }
       cout << endl;
       return 0;
}
```