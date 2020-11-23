* const成员函数

    const成员函数可以使用类中的所有成员变量，但是不能修改它们的值，这种措施主要还是为了保护数据而设置的。const 成员函数也称为常成员函数。通常将get函数设置为常成员函数。常成员函数必须在声明和定义的时候在函数头部的结尾加上 const 关键字。如：

    ```
    int getage() const;
    ```

    * const位置区分

        * 函数开头的 const 用来修饰函数的返回值，表示返回值是 const 类型，也就是不能被修改，例如:

            ```
            const char * getname()
            ```

        * 函数头部的结尾加上 const 表示常成员函数，这种函数只能读取成员变量的值，而不能修改成员变量的值，例如:

            ```
            char * getname() const
            ```

            

* const对象

    const对象，又叫**常对象**。一旦将对象定义为常对象之后，就只能调用类的const成员(包括const成员变量和const成员函数),非const成员可能会修改对象的数据,C++禁止这样做。

    语法：

    ```
    const  class  object(params);
    class const object(params);
    ```

    const指针

    ```
    const class *p = new class(params);
    class const *p = new class(params);
    ```

    

