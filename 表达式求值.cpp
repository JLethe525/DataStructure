#include <iostream>

using namespace std;

template<typename T> //模板 
struct StackNode
{
    T data;
    StackNode<T>* next;
};

template<typename T>
using LinkStack = StackNode<T>*;//命名 

//建立 
template<typename T>
void CreateStack(StackNode<T>*& S)
{
    S = NULL;
}

//入栈 
template<typename T>
void Push(StackNode<T>*& S, T ch)
{
    StackNode<T>* p = new StackNode<T>;
    if (!p)
        return;
    p->data = ch;
    p->next = S;
    S = p;
}

//出栈 
template<typename T>
void Pop(StackNode<T>*& S, T& ch)
{
    if (S == NULL)
        return;
    StackNode<T>* p = S;
    ch = p->data;
    S = p->next;
    p->next = NULL;
    delete p;
}

//取栈顶元素 
template<typename T>
T GetTop(LinkStack<T> S)
{
    if (!S)
        return 0;
    return S->data;
}

//比较算数优先级
int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

//运算 
int Calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        if (b != 0)
            return a / b;

    default:
        return -999;
    }
}


int main()
{
    LinkStack<char> OPTR = NULL;//保存运算符 
    LinkStack<int> OPND = NULL; //保存计算过程 

    char str[100];
    cin >> str;

    int num1, num2;
    char top_op;

    for (int i = 0; str[i] != '#'; i++)
    {

        char ch = str[i];
        if (ch >= '0' && ch <= '9')
        {
            Push(OPND, ch - '0');//转换int 
        }
        //非数字 
        else
        {
            //① 
            if (ch == '(')
                Push(OPTR, ch);
            //②    
            else if (ch == ')')
            {
                while (GetTop(OPTR) != '(')
                {
                    Pop(OPTR, top_op);
                    Pop(OPND, num1); Pop(OPND, num2);
                    Push(OPND, Calculate(num2, num1, top_op));//2在1下面
                }
                Pop(OPTR, top_op);//弹出'(' 
            }
            //③遇到加减乘除  
            else
            {
                //一直算 直到优先级大于栈顶运算符 
                while (GetTop(OPTR) != 0 && GetTop(OPTR) != '(' && priority(ch) <= priority(GetTop(OPTR)))
                {
                    Pop(OPTR, top_op);
                    Pop(OPND, num1); Pop(OPND, num2);
                    Push(OPND, Calculate(num2, num1, top_op));
                }
                //    if(GetTop(OPTR)==0)    && if(priority(ch)>priority(GetTop(OPTR)))和while循环后 
                Push(OPTR, ch);
            }
        }
    }
    //读取完毕，继续计算 
    while (OPTR)
    {
        Pop(OPTR, top_op);
        Pop(OPND, num1); Pop(OPND, num2);
        Push(OPND, Calculate(num2, num1, top_op));
    }
    //输出
    cout << GetTop(OPND);

    return 0;
}