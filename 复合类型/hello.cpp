#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>

using namespace std;

struct inflatable{
    char name[10];
    float volime;
    double price;
};

int main()
{
    // 结构数组
    inflatable guese[2] = {
        {"wu kong", 0.5, 99},
        {"hello ", 0.3, 22}
    };
    // cout<< "The gueses " << guese[0].name << " and " << guese[1].name
    //     << "\nhave a combined volume of "
    //     << guese[0].volime + guese[1].volime << "cubic feet." << endl;



    // 共用体　节省内存
    struct widget
    {
        char brand[20];
        int type;
        union id
        {
            int int_val;
            double double_val;
        }id_val;
    };
    widget prize;
    // cout << prize.type;              // 不赋值的话则是随机数
    // if(prize.type == 1)
    // {
    //     cin >> prize.id_val.int_val;
    // }
    // else
    // {
    //     cin >> prize.id_val.double_val;
    // }
    // cout << prize.id_val.int_val;    //共用体中未被赋值的对象值为０



    // 枚举　　枚举类型只有赋值运算 可以转化为int类型,  但int不能转化为枚举
    enum spectrum {red, orange, yellow=1, green, blue, indigo=100};
    // cout << "green: " << green << endl;

    // spectrum band;                   // 声明枚举变量
    // band = blue;
    // int color = blue;
    // color = 3 + blue;
    // cout << "color :" << color 
    //      << " band :" << band << endl; 

    // band = spectrum(4);
    // cout << "spectrum(4): " << band << endl;

    // band = red + blue;
    // band = 3;                         // 这是不被允许的



    // 指针 数组
    // 指针的用武之地 在运行阶段分配未命名的内存 以存储值, 需要和new delete一起使用
    // 最危险的指针   int* p1; *p1=23222;     危险之二: 释放同一个内存块两次
    // 一定记得   创建new 就需要考虑 delete 

    double* p3 = new double [3];
    // p3[0] = 0.1;
    // p3[1] = 0.2;
    // p3[2] = 0.3;

    // cout << "p3[0]: " << p3[0] << endl;
    // p3 += 1;
    // cout << "p3[0]: " << p3[0] << endl;
    // p3 -= 1;
    // delete [] p3;                        // 释放内存 但不删除指针


    // 指针名和数组名大多数情况下相同 包括用法   区别1:数组名为常量不能修改 2:sizeof 数组得到是整个数组大小,指针为指针变量大小
    double wages[3] = {1.0, 2.0, 3.0};
    // double* ps = wages;
    // cout << "ps: " << ps 
    //      << " *ps: " << *ps << endl;
    // cout << "&wages: " << wages << endl;
    // cout << "*(wages+1): " << *(wages+1) << endl;   // 数组名当成指针名用


    // char指针 char数组名 字符串常量 都被解释成字符串第一个字符的地址
    // char flower[10] = "hello";               
    // cout << flower << " is a char\n";          // cout对象认为char地址是字符串的地址,故打印改地址处的字符串,遇到空字符为止

    char animal[20] = "bear";
    const char * bird = "wren";                   // 字符串常量被解释成是第一个字符地址  const意味着不能修改字面值
    char * p5;

    // cout << animal << " and "
    //      << bird << endl;                      // 输出为 bear and wren

    // cout << "animal add: " << (int* )animal << endl
    //      << "bird add: " << (int* )bird << endl;  // 强制输出char类型地址

    // cout << "Enter a animal: ";
    // cin >> animal;                             // 避免用字符串常量 未被初始化的指针 来接收输入
    // p5 = animal;
    // cout << p5 << "!\n";                       // 输出为ha!
    // cout << "Before using strcpy():\n";
    // cout << animal << " at " << (int*)animal << endl;
    // cout << p5 << " at " << (int*)p5 << endl;
    // p5 = new char[strlen(animal) + 1];
    // strcpy(p5, animal);                        // 将数组中内容复制到p5  并不能p5=animal 这样是赋值地址 且再也找不到new的内存
    // cout << "After using strcpy():\n";
    // cout << animal << " at " << (int*)animal << endl;
    // cout << p5 << " at " << (int*)p5 << endl;  // 这里显示地址和animal不一样了
    // delete [] p5;



    // new 和 结构
    struct thing
    {
        char name[20];
        int volu;
        double price;
    };

    // thing* p6 = new thing;
    // cin.get(p6->name, 20);                         // get getline 用来接收整行字符串 getline抛弃空字符
    // cin >> (*p6).volu;
    // cout << "name: " << (*p6).name << endl;        // 指针对于结构的两种方式
    // cout << "volu: " << p6->volu << endl;
    // delete p6;



    // 动态分配数组空间实例  大量开辟数组存储字符串 且字符串长短差距过大
    char * getname(void);
    // char * name;
    // name = getname();                               // 指向动态分配空间的地址 该空间存储用户输入的信息
    // cout << name << " at " << (int *)name << endl;
    // cout << name << " strlen(): " << strlen(name) << endl;
    // delete [] name;



    // 指针的指针
    struct years_and
    {
        int year;
    };

    // years_and s01, s02, s03;
    // s01.year = 01;
    // years_and * pa = &s02;
    // pa -> year = 02;
    // years_and trio[3];
    // trio[0].year = 03;
    // cout << trio->year << endl;                         // 数组名和指针名一样                  03
    // const years_and * arp[3] = {&s01, &s02, &s03};      // 结构指针数组(指向数组的指针)        
    // cout << arp[1]->year << endl;                                                        // 02
    // const years_and ** ppa = arp;                       // 结构指针指针(指向结构指针的结构指针)
    // auto ppb = arp;
    // cout << (*ppa)->year << endl;                                                        // 01
    // cout << (*(ppb+1))->year << endl;                                                    // 02



    // vector array 模板类
    double a1[4] = {1.1, 1.2, 1.3, 1.4};
    vector<double> a2(4);
    // a2[0] = 1.0/3.0;
    // a2[1] = 1.0/5.0;
    // a2[2] = 1.0/7.0;
    // a2[3] = 1.0/9.0;
    // array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    // array<double, 4> a4;
    // a4 = a3;                                                  // 两种对象都可用标准数组表示法来访问各元素
    // cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;   // array对象可以赋值给另一个对象 对于数组必须逐元素复制
    // cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    // cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    // cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    // a1[-2] = 20.2;
    // cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;

    






    return 0;
}

char * getname()
    {
        char temp[80];
        cout << "Enter last name: ";
        cin >> temp;                             // 输入的单词放到数组中  秩序开辟一个最大的数组即可 其他在运行过程中按需分配
        char * pn = new char[strlen(temp) +1];
        strcpy(pn, temp);                        // 将输入(数组)内容赋值到新分配的内存空间  达到运行时输入多少分配多少,动态分配
        return pn;                               // 返回新分配空间指针(空间地址)
    }
