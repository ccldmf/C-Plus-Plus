 # C++_9-1-set-multiset关联容器

 **set/mutiset,map/multimap**

**特点：**

&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp; 内部元素有序排列，新元素插入的位置取决于它的值，查找速度快。

支持其他的成员函数：
```
find:                查找等于某个值的元素（x<y和y<x同时成立即为相等）
lower_bound: 		 查找某个下界
upper_bound: 	     查找某个上界
equal_range:   		 同时查找上界和下界
count:               计算等于某个值的元素个数
insert:              用于插入一个元素或一个区间
```

multiset用法：
```
template <class T>

void Print(T first, T last)
{
       for (; first != last; ++first)
       {
              cout << *first << " ";
       }
       cout << endl;
}

class A
{
private:
       int n;

public:
       A(int n_) { n = n_; }
       friend bool operator<(const A& a1, const A& a2) { return a1.n < a2.n; }
       friend ostream& operator<<(ostream& ostr, const A& a2) { ostr << a2.n;  return ostr; }
       friend class MyLess;
};

struct MyLess
{

       bool operator()(const A& a1, const A& a2)
       {
              return (a1.n % 10) < (a2.n % 10);
       }
};

typedef multiset<A> MSET1;

typedef multiset<A, MyLess> MSET2;

int main()
{
       const int SIZE = 6;
       A a[SIZE] = {4,22,19,8,33,40};
       MSET1 m1;
       m1.insert(a, a + SIZE);
       m1.insert(22);
       cout << "1)" << m1.count(22) << endl;    //1)2
       cout << "2)";
       Print(m1.begin(),m1.end());                     //2)4 8 19 22 22 33 40
       MSET1::iterator pp = m1.find(19);
       if (pp != m1.end())
       {
              cout << "Found" << endl;                 //Found
       }
       cout << "3)";
       cout << *m1.lower_bound(22) << "," << *m1.upper_bound(22) << endl;
                                                                           //3)22  33
       cout << "4)";
       Print(m1.begin(), m1.end());                    //4)4 8 19 22 22 33 40
       cout << "5)" << *pp << endl;                    //5)19
       MSET2 m2;
       m2.insert(a, a + SIZE);
       cout << "6)";
       Print(m2.begin(), m2.end());                    //6)40 22 33 48 19
       return 0;
}
```
set用法：
```
int main()
{
       typedef set<int>::iterator IT;
       int a[5] = {3,4,6,1,2};
       set<int> st(a, a + 5);
       pair<IT, bool>result;
       result = st.insert(5);

       if (result.second)
       {
              cout << *result.first << " inserted" << endl;
       }

       if (st.insert(5).second)
       {
              cout << *result.first << endl;
       }
       else
       {
              cout << *result.first << " already exits" << endl;
       }
       pair<IT, IT> bounds = st.equal_range(4);
       cout << *bounds.first << "," << *bounds.second << endl;
       return 0;
}
```