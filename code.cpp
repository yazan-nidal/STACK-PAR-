#include "iostream"
using namespace std;

#define   size   100

typedef char itemtype;

typedef struct
{ itemtype items [size];
  int top;
} stack;

//typedef struct stacktype stack;

int empty(stack s)
{
        return s.top == -1;
}

int full(stack s)
{
        return s.top == size-1;
}

void clear(stack & s)
{
        s.top = -1;
}

void push(stack &s , itemtype i)
{
        s.items[++s.top] = i;
}

itemtype pop(stack &s)
{
        return s.items[s.top--];
}

int stacktop(stack s)
{
        return s.items[s.top];
}

int openParenthesis(char ch)
{
        return (ch == '(' || ch == '[' || ch == '{');
}

int closeParenthesis(char ch)
{
        return (ch == ')' || ch == ']' || ch == '}');
}

int match( char c1, char c2)
{
        return ((c1 == '(' && c2 == ')') ||  (c1 =='['  && c2 == ']') || (c1 == '{' && c2 =='}' ));
}

void main()
{ stack s;
  char st[50];
  itemtype ch;
  cout << "Enter string ===> ";
     cin >> st;
  cout << "The entered string is ===> ";
     cout << st <<endl;
  clear(s);
  int i = 0;
     while (st[i])
            { if (openParenthesis(st[i]))
                 if (!full(s))
                                 push(s, st[i]);
                         else {cout <<" Error stack is full\n"; return;}
                  else if (closeParenthesis (st[i]))
                       {if (! empty(s))
                                ch = pop(s);
                            else {cout <<" Error stack is empyu\n"; return;}
                            if (! match(ch, st[i]))
                                   {cout <<" Error No macthing\n"; return;}
                   }
              i ++;
            }

  if(! empty(s))
          cout <<" Error: invalid input \n";
  else cout <<"Input is valid\n";

}
