* new

  * 重载为成员函数

    ```
    void * className::operator new( size_t size ){
        //TODO:
        }
    ```

  * 重载为全局函数

    ```
    void * operator new( size_t size ){
        //TODO:
        }
    ```

  重载 new 或 new[] 时，无论是作为成员函数还是作为全局函数，它的第一个参数必须是 size_t 类型。size_t 表示的是要分配空间的大小，对于 new[] 的重载函数而言，size_t 则表示所需要分配的所有空间的总和。

* delete

  * 重载为成员函数

    ```
    void className::operator delete( void *ptr){
        //TODO:
        }
    ```

  * 重载为全局函数

    ```
    void operator delete( void *ptr){
        //TODO:
        }
    ```

    