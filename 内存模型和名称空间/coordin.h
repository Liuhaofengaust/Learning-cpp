#ifndef COORDIN_H_                // 条件编译  
#define COORDIN_H_                // 先检查COORDIN_H_是否被定义过 否则这段代码块将不被编译

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar rect_to_polar(rect xypos);   // 声明函数
void show_polar(polar dapos);      // 声明函数

#endif                             // 防止重复包含头文件引起的编译出错 那会导致声明两次许多内容
