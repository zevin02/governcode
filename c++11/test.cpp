#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <typeinfo>
#include <array>
using namespace std;

struct Point
{
    int _x;
    int _y;
    /*explicit*/ Point(int x, int y)
        : _x(x), _y(y) { cout << "1" << endl; }
};

class A
{
private:
    int _a;

public:
    explicit A(int a)
        : _a(a) {}
};

//单参数类型支持隐式类型转换
void test2()
{
    A aa(2); //单参数的类型，可以使用正常的方式
    // A b=2;//也可以使用这种隐式类型的转换
    // 2拷贝构造一个A，在进行拷贝构造成b
    //加一个explicit，就不能这样了
    string s1 = "hjs"; // string的构造函数没有加explicit
    vector<string> v;
    v.push_back("hjk"); //这也是隐式类型转换
}

void test1()
{

    //以前
    Point p = {1, 2};             // c语言是使用这种方式来初始化
    int brr[5] = {1, 2, 3, 4, 5}; //使用这种大括号进行初始化

    ////////////////////////////////////////////
    //现在s
    int a = 1;
    int b = {2}; //现在还可以这样进行初始化,=也省略了
    int c{3};
    int arr[5]{1, 2, 3, 4};
    Point k{1, 2};
    int *ptr = new int[5]{1, 2, 3};             //初始化了前3个值，后面的值全都是0
    Point *ptrd = new Point[2]{{1, 1}, {2, 2}}; //现在还可以这样进行初始化,里面必须要又两个{}
    // new要去调用他的构造函数

    //正常调用point
    Point p1(1, 2); //调用构造函数

    // c++11支持的多参数的构造函数
    Point p2 = {1, 2};
    Point p3{1, 2};
}

void test3()

{
    //都是因为支持initializer_list的构造函数

    //以前的vector初始化
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int> v2 = {1, 2, 3, 4}; //现在vector也可以这样初始化, 掉的就是initializer list进行初始化

    initializer_list<int> lt = {1, 2, 3};                         //
    list<int> l = {1, 2, 3};                                      //链表也可以这样初始化
    map<string, string> dic = {{"dasd", "dsa"}, {"dsada", "fd"}}; // map也可以
    v2 = {10, 20, 30};                                            //也可以用赋值，不是构造，在赋值运算符重载那里使用了initialzer_list

    for (auto e : v2)
    {
        cout << e << " ";
    }
}

int func(int a)
{
    return a;
}
void test4()
{
    const int x = 10;
    cout << typeid(x).name() << endl; //获得x的类型名字
    decltype(x) z = 2;                //获得x的类型名，来初始化另一个变量
    double y = 2.2;
    decltype(x * y) ret; // ret类型为double
    decltype(&x) p;      // p类型为int*

    int (*func)(int) = func;      //函数指针
    auto pfunc = func;            //直接用auto也可以
    decltype(pfunc) pfun3 = func; //定义一个变量
    map<string, string> dict = {{"sort", "排序"}, {"insert", "插入"}};
    auto it = dict.begin();
    auto cpit = it;
    //但是不能把auto作为模板参数
    vector<decltype(it)> v; //这样就很方便
    v.push_back(it);
}
void test5()
{
    array<int, 10> a; //静态数组
    a[11];            //可以支持对越界的检查
}

void test6()
{

    // forward_list//单链表,很少用，也是基类，只不过和list比较，每一个节点少了一个指针
    // unordered_map
    // unordered_set
    // cbegin()返回的就是const的begin，

    /*
        已有容器新增的函数接口
        1. 列表初始化
        2. cbegin
        3. 移动构造，移动赋值
        4. 右值引用版本的插入接口

        vector(vector&& x)
        void push_back(value_type&& val)

        emplace

        emplace_back

    */
}

void test7()
{
    /*
    右值引用和移动语义
    左值引用：给左值取别名
    右值引用：给右值取别名


    左值是一个表达式

*/

    int a = 10;
    int &r1 = a; //左值引用,在这里a，&a，*p都是左值
    int *p = &a;
    int &e2 = *p;
    const int b = 10;  //这个b不能对他进行赋值，但是也是一个左值
    const int &r3 = b; //可以这样对左值进行引用

    //左值可以是一个表示数据的表达式（如变量名或者解引用的指针），特点：可以获取他的地址，也可以对他赋值
    //左值可以出现在=的左边，但是右值不能出现在=的左边，所以=左边只能出现左值

    /*
        什么是右值
        右值也是一个表示数据的表达式，如：字面常量，表达式返回值，传值返回函数的返回值（）
        右值不能取地址，不能出现在=的左边，只能出现在=的右边，

        （不能取地址的对象就是右值）
    */

    //这几个都是常见的右值
    10;
    double x = 1.1, y = 2.2;
    min(x, y);
    //这几个都不能&

    int &&r0 = 10;
    double &&l = x + y;
    // double &&r3 = min(x, y);

    //左值引用不能引用右值----不能直接引用，但是可以加const，左值引用
    const int &c = 10;
    const double &e22 = x + y;
    // void pushback(const T & x)像直接传进去数字这样的右值，引用也可以实现

    //右值引用不能引用左值，那么也是引用move 后的左值
    int &&r = move(a);

    //所以是可以交叉引用的
    //需要注意的是，右值不能取地址，给右值取别名之后，又变成了左值,因为在特定的地方把他存起来了，
}

#include <assert.h>
#include <cstring>
//右值引用的产生是为了弥补左值引用的不足

namespace bit
{
    class string
    {
    public:
        typedef char *iterator;
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        string(const char *str = "")
            : _size(strlen(str)), _capacity(_size)
        {
            // cout << "string(char* str)" << endl;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        // s1.swap(s2)
        void swap(string &s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }
        // 拷贝构造
        string(const string &s)//编译器会判定，如果是左值就会到这里来
            : _str(nullptr)
        {
            cout << "string(const string& s) -- 深拷贝" << endl;
            string tmp(s._str);
            swap(tmp);
        }
        // 赋值重载
        string &operator=(const string &s)
        {
            cout << "string& operator=(string s) -- 深拷贝" << endl;
            string tmp(s);
            swap(tmp);
            return *this;
        }
        // 移动构造
         // 移动构造，如果是右值就会到这里来
        //这种将亡值资源析构了很可惜，直接给我把
        string(string &&s) //要开始移动资源,c++11中，将右值分为1.纯右值（10，x+t，min（x，y）），2.将亡值(自定义对象)
            : _str(nullptr), _size(0), _capacity(0)
        {
            cout << "string(string&& s) -- 移动语义" << endl;
            swap(s);
            
        }
        // 移动赋值
        string &operator=(string &&s)
        {
            cout << "string& operator=(string&& s) -- 移动语义" << endl;
            swap(s);//
            return *this;
        }
        ~string()
        {
            delete[] _str;
            _str = nullptr;
        }
        char &operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char *tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        void push_back(char ch)
        {
            if (_size >= _capacity)
            {
                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
                reserve(newcapacity);
            }

            // 左值引用的使用场景：
            // 做参数和做返回值都可以提高效率。
            // 左值引用的短板：
            // 但是当函数返回对象是一个局部变量，出了函数作用域就不存在了，就不能使用左值引用返回，
            // 只能传值返回。例如：bit::string to_string(int value)函数中可以看到，这里只能使用传值返回，
            // 传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷贝构造)。
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }
        // string operator+=(char ch)
        string &operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string operator+(char ch)
        {
            string tmp(*this);
            push_back(ch);
            //把他的资源直接转移走，销毁了是空
            return tmp; //这个东西出了作用域就销毁了，
                        //不能用左值返回，这里的tmp是一个右值
        }

        const char *c_str() const
        {
            return _str;
        }

    private:
        char *_str;
        size_t _size;
        size_t _capacity; // 不包含最后做标识的\0
    };
}

// 1。左值引用左参数，可以完美的解决所有的问题
// 2.左值引用做返回值，只能解决部分问题(出了作用域还在，没有进行拷贝)

//右值引用如何解决operator+的拷贝函数
//现在提高了一个移动构造
void func1(bit::string s) //这个会发生拷贝构造
{
}

void func2(const bit::string &s) //使用const的引用，既可以传递左值，也可以传递右值
{
}

void test8()
{
    bit::string s("dsa");
    s + 'd'; //会拷贝，左值引用只能解决+=，但是解决不了+，
    //这种传值返回的函数对象，右值，将亡值，
}
bit::string func()
{
    bit::string x("dasd");
    return x;//这里会先拷贝再析构是一种资源浪费，移动构造将x识别为右值，直接调用移动构造转移资源，提高效率
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test8();
    func();
    return 0;
}
