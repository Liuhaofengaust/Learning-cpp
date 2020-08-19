#ifndef STOCK00_H_                   // 防止重复加载头文件导致的编译出错
#define STOCK00_H_ 

#include <string>

class Stock
{
    private:                         // 只能通过公共成员方法访问 不能直接用对象访问
        std::string company;
        long   shares;               // 隐藏项是OOP的主要目标之一 故经常把数据成员放在私有部分 组成类接口的成员函数放在共有部分
        double share_val;
        double total_val;            // 股票总价格

        void set_tot() {total_val = shares * share_val; }           // 内联函数 也可以在类声明之外定义内联函数
        
        static const int Months = 12;                               // 创建常量 与其他静态变量存储在一起 不存储在对象中
        double costs[Months];                                       // 对象可以通过方法访问Months值

    public:                          // 组成类的公共接口类成员
        Stock();                     // 默认构造函数
        Stock(const std::string & co, long n=0, double pr=0.0);      // 程序声明对象时 将自动调用构造函数
        ~Stock();                    // 析构函数 --用于释放对象
        
        void acquire(const std::string & co, long n, double pr);
        void buy(long num, double price);            
        void sell(long num, double price);
        void update(double price);

        void show() const;           // const成员函数 为了确保该方法不修改调用对象 
                                     // 通常采用const 引用或指针作为形参  但该函数不接受参数

        const Stock & topval(const Stock & s) const;                  // 返回类型为引用意味着返回的是调用的对象本身  可见在类定义中也可以用类
                                                                      // const意味着不能通过this来修改对象的值
};


#endif

// inline void Stock::set_tot()      // 内联函数必须用 inline声明
// {
//     total_val = shares * share_val;
// }
