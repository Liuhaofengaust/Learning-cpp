#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using namespace std;
    Stack st;
    char ch;
    unsigned long po;

    cout << "Please enter a to add purchase order,\n"
         << "P to process a PO, or Q to quiet.\n";
    
    while(cin >> ch && toupper(ch) != 'Q')
    {
        while(cin.get() != '\n')
            continue;
        if(!isalpha(ch))                  // isalpha判断字母是否为英文字母 是返回非0
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if(st.isfull())
                        cout << "stack already full\n";
                      else
                        st.push(po);
                      break;
            case 'p': if(st.isempty())
                        cout << "stack already empty\n";
                      else
                      {
                          st.pop(po);
                          cout << "PO #" << po << " popped\n";
                      }
                      break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}