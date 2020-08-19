#include <iostream>
#include "stock00.h"

/*
 * 在初始化成员函数 或者变量时,需要加上类声明. 调用成员函数时不用 因对象有类属性
 */

// 管理对某个公司股票的首次购买
void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if(n < 0)
    {
        std::cout << "Number of shares cant't be negative; "
                 << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();                                     // 计算持有该公司总股票价值
}

// 增加所持有的股票
void Stock::buy(long num, double price)
{
    if(num<0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Trabcesation is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

// 减少所持有的股票
void Stock::sell(long num, double price)
{
    using std::cout;
    if(num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n"; 
    }
    else if(num > shares)
    {
        cout <<"You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

// 更新股票价格 以及总股票价值
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

// 展示对象信息
void Stock::show() const                      // const成员函数
{
    std::cout << "Company: " << company
              << " Shares: " << shares
              << " shares Price: $" << share_val
         //   << " Months: " << Months
              << " Total Worth: $" << total_val << std::endl;
}


// 比较对象间的股票最大值
// 该函数传入类的对象 得到类的对象  因为都是引用 故直接找到对象所在位置操作
// 第一个const表示不能修改显示对象值 第二个const表示不能修改this对象值(隐式对象,调用该方法的对象)
const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val > total_val)
        return s;
    else
    {
        return *this;                        // this是对象的指针 *this表示对象
    }                                        // 每个方法都有一个this指针 指向用来调用成员函数的对象
    
}


Stock::Stock()                                // 默认构造函数
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;
    if(n < 0)
    {
        std::cerr << "Number of shares can't be negative;"
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
    
}

Stock::~Stock()                       // 析构函数  一般没有内容
{
    std::cout << "Bye, " << company << "!\n";
}

