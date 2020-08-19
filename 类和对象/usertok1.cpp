/*
 * 如果是类的话  他是一个类型 一定要用对象来操作
 */

#include <iostream>
#include "stock00.h"

int main()
{
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        
        Stock stock1("liuhaofeng_1", 12, 20.0);          // 初始化对象实例
        stock1.show();
        
        Stock stock2 = Stock("liuhaofeng_2", 2, 2.0);    //  初始化对象实例2
        stock2.show();

        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;                                 // 对象可以直接赋值
        cout << "Listing stock1 and stock2: \n";
        stock1.show();
        stock2.show();

        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("liuhaofeng_3", 10, 50.0);
        cout << "Revised stock1: \n";
        stock1.show();
        cout << "Done\n";

        const Stock land("const1", 1, 1.0);
        land.show();
    }

    // 对象数组   必须有类的默认构造函数, 因为数组可能初始化不全 那其他元素就是默认为0
    const int STKS = 4;
    Stock stocks[STKS] = {
        Stock("haofeng0", 12, 1.0),
        Stock("haofeng1", 20, 9.0),
        Stock("haofeng2", 30,3.0),
        Stock("haofeng3", 19, 9.0)
    };
    std::cout << "Stock holdings:\n";

    int st;
    for(st = 0; st < STKS; st++)
        stocks[st].show();

    const Stock * top = &stocks[0];                  // 初始化类的指针 指向一个对象
    for(st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);              // top为指针 调用类成员需要用->
    std::cout << "\nMost valueable holding: \n";
    top->show();


    return 0;
}