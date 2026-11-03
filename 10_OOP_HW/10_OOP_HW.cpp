#include <iostream>
using namespace std;

class Stack
{
private:
    enum { EMPTY = -1, FULL = 9 };
    char arr[FULL + 1];
    int topIndex;
public:
    Stack()
    {
        topIndex = EMPTY;
    }
    bool IsFull()
    {
        return topIndex == FULL;
    }
    bool Push(char elem)
    {
        if (!IsFull())
        {
            arr[++topIndex] = elem;
            return true;
        }
        return false;

    }
    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }
    char Pop()
    {

        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
    }
    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int GetCount()
    {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
    }
};

template<typename Template>
class DynamicStack
{
private:
    enum { EMPTY = -1 };
    Template* arr;
    int size;
    int topIndex;
public:
    DynamicStack() = default;
    DynamicStack(int size) :size(size)
    {
        arr = new Template[size];
        topIndex = EMPTY;
    }
    DynamicStack(initializer_list<Template>list)
    {
        topIndex = EMPTY;
        this->size = list.size();
        arr = new Template[size];
        for (Template i : list)
        {
            Push(i);
        }      
    }
    ~DynamicStack()
    {
        if (arr != nullptr)
            delete[]arr;
    }
    bool IsFull()
    {
        return topIndex == size - 1;
    }
    void Push(Template elem)
    {
        if (!IsFull())
        {
            arr[++topIndex] = elem;
        }
        else
        {
            cout << "Stack is full!!" << endl;
            size *= 2;
            Template* temp = new Template[size];
            for (int i = 0; i <= topIndex; i++)
            {
                temp[i] = arr[i];
            }
            delete[]arr;
            arr = temp;

            Push(elem);
        }
    }
    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }

    Template Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
    }
    int GetCount()
    {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    Template Peek()
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
    }
    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
};

int main()
{
    Stack st;
    st.Push('a');
    st.Push('b');
    st.Push('c');
    st.Push('d');
    st.Push('e');
    st.Push('f');
    st.Push('g');
    st.Print();
    st.Pop();
    st.Print();
    cout << "stack's count : " << st.GetCount() << endl;
    cout << "stack's top symbol : " << (char)st.Peek() << endl;
    cout << "================================================================================================" << endl;
    DynamicStack<string> dnSt({"Hello", "World", "C++"});
    dnSt.Print();
    cout << "stack's top symbol : " << dnSt.Peek() << endl;
    dnSt.Push("What");
    dnSt.Print();
    dnSt.Pop();
    dnSt.Print();
}