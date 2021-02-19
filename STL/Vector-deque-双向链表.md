* vector

  * Vector实现一维数组：

  ```
  int main()
  {
         int a[5] = {1,2,3,4,5};
         vector<int> v(a, a + 5);
         cout << "1)" << v.end() - v.begin() << endl;
         cout << "2)";
         for (int i = 0; i < v.size(); i++)
         {
                cout << v[i] << " ";
         }
         cout << endl;
         v.insert(v.begin() + 2, 13);
         cout << "3)";
         for (int i = 0; i < v.size(); i++)
         {
                cout << v[i] << " ";
         }
         cout << endl;
         return 0;
  }
  ```

  * Vector实现二维数组：

  ```
  int main()
  {
         vector<vector<int>> v(3);
         for (int i = 0; i < v.size(); i++)
         {
                for (int j = 0; j < 4; j++)
                {
                       v[i].push_back(j);
                }
         }
         for (int i = 0; i < v.size(); i++)
         {
                for (int j = 0; j < v[i].size(); j++)
                {
                       cout << v[i][j] << " ";
                }
                cout << endl;
         }
         cout << endl;
         return 0;
  }
  ```

* deque

  所有适用于vector的操作都适用于deque。deque还有push_front（将元素插入到前面）和pop_front（删除最前面的元素）操作。复杂度为O(1).

* 双向链表

  在任何位置插入删除都是常数时间，不支持随机存取。

  除了具有所有顺序容器都有的成员函数之外，还支持8个成员函数：

  ```
  push_front:  在前面插入
  pop_front:   删除前面的元素
  sort:        排序（list不支持STL的算法sort)
  remove:      删除和指定值相同的所有元素
  unique:      删除所有和前一个元素相同的元素(要做到元素不重复，则unique之前还需要sort)
  merge:       合并两个链表，并清空被合并的那个
  reverse:     颠倒链表
  splice:      在指定位置前面插入另一个链表中的一个或多个元素，并在另一个链表中删除被插入的元素。
  ```

  ```
  class A {
  private:
         int n;
  public:
         A(int n_) { n = n_; }
         friend bool operator<(const A& a1, const A& a2);
         friend bool operator==(const A& a1, const A& a2);
         friend ostream& operator<<(ostream& o, const A& a);
  };
  
  bool operator<(const A& a1, const A& a2)
  {
         return a1.n < a2.n;
  }
  
  bool operator==(const A& a1, const A& a2)
  {
         return a1.n == a2.n;
  }
  
  ostream& operator<<(ostream& ostr, const A& a)
  {
         ostr << a.n;
         return ostr;
  }
  
  template <class T>
  
  void PrintList(const list<T>& lst)
  {
         typename list<T>::const_iterator i;             //typename用来说明list<T>::const_iterator是个类型
         i = lst.begin();
         for (i = lst.begin(); i != lst.end(); i++)
         {
                cout << *i << ",";
         }
  }
  
  int main()
  {
         list<A> list1, list2;
         list1.push_back(1);list1.push_back(3);
         list1.push_back(2);list1.push_back(4);
         list1.push_back(2);
         list2.push_back(10);list2.push_back(20);
         list2.push_back(30);list2.push_back(30);
         list2.push_back(30);list2.push_back(40);
         list2.push_back(40);
         cout << "1)"; PrintList(list1); cout << endl;   //1)1 3 2 4 2
         cout << "2)"; PrintList(list2); cout << endl;   //2)10 20 30 30 30 40 40
         list2.sort();
         cout << "3)"; PrintList(list2); cout << endl;   //3)10 20 30 30 30 40 40
         list2.pop_front();
         cout << "4)"; PrintList(list2); cout << endl;   //4)20 30 30 30 40 40
         list1.remove(2);
         cout << "5)"; PrintList(list1); cout << endl;   //5)1 3 4
         list2.unique();
         cout << "6)"; PrintList(list2); cout << endl;   //6)20 30 40
         list1.merge(list2);
         cout << "7)"; PrintList(list1); cout << endl;   //7)1 3 4  20 30 40
         cout << "8)"; PrintList(list2); cout << endl;   //8)
         list1.reverse();
         cout << "9)"; PrintList(list1); cout << endl;   //9)40 30 20 4 3 1
         return 0;
  }
  ```