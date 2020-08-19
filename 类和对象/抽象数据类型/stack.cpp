#include "stack.h"

Stack::Stack() {top = 0; }

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}


// 引用一个Item类型的值 不能修改
bool Stack::push(const Item & item)
{
    if(top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

// 引用一个Item类型的值
bool Stack::pop(Item & item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }
    else
    {
        return false;
    }
}
