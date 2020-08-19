#ifndef MYTIME0_HPP_
#define MYTIME0_HPP_

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        Time Sum(const Time & t) const;
        void Show() const;
};



Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}


// 不能返回局部变量 或 临时对象的引用                              因函数执行完毕后 这些将消失
Time Time::Sum(const Time & t) const                      // 返回类型不能是引用 因为sum对象是局部变量
{
    Time sum;                                             // 创建一个对象 来表示另外两个对象的和
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;                                           // 返回对象将创建对象的副本, 调用函数可以使用它
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << "minutes \n";
}

#endif