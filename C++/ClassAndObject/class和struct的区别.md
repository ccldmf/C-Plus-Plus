C++中，struct既包含成员变量，又可以包含成员函数.
		**不同点：**

* 使用 class 时，类中的成员默认都是 private 属性的；而使用 struct 时，结构体中的成员默认都是 public 属性的
* class 继承默认是 private 继承，而 struct 继承默认是 public 继承
* class 可以使用模板，而 struct 不能