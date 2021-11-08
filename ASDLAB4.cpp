#include <iostream>
using namespace std;

struct Stack
{
    int item;
    int key;
    Stack* next;
};

void initialize(Stack**, int, int*);
void push(Stack**, int, int*);
Stack* pop(Stack*, int*);
void Print(Stack*);
void SearchValue(Stack*, int);
void SearchKey(Stack*, int, int*);
void SearchMaximum(Stack*);
void Size(int*);
void ClearStack(Stack*, int*);

void stackIsEmpty();
void deletedElement(int);
int getVariant(int);
int getValue();
int getKey();
void printMenu();
void printSearchMenu();

int main()
{
    Stack* top = NULL;
    Stack** TOP = &top;
    int count = 0, v = 0, v2 = 0, value, key;
    int* Count = &count;
    do {
        system("CLS");
        printMenu();
        v = getVariant(8);
        switch (v)
        {
        case 1:
            value = getValue();
            initialize(TOP, value, Count);
            break;
        case 2:
            value = getValue();
            push(TOP, value, Count);
            break;
        case 3:
            top = pop(top, Count);
            break;
        case 4:
            printSearchMenu();
            v2 = getVariant(3);
            switch (v2)
            {
            case 1: 
                value = getValue();
                SearchValue(top, value);
                break;
            case 2:
                key = getKey();
                SearchKey(top, key, Count);
                break;
            case 3:
                SearchMaximum(top);
                break;
            }
            break;
        case 5:
            ClearStack(top, Count);
            break;
        case 6:
            Print(top);
            break;
        case 7:
            Size(Count);
            break;
        }
        if (v != 6 && v != 8)
        {
            Print(top);
        }
        if (v != 8)
        {
            system("pause");
        }
    } while (v < 8);
}

void printMenu()
{
    cout << "(1: INITIALIZE, 2: PUSH, 3: POP, 4: SEARCH, 5: CLEAR, 6: OUTPUT, 7: SIZE, 8: EXIT)" << endl;
    cout << "Select any value you want:";
}
void printSearchMenu()
{
    cout << "(1: SEARCH VALUE, 2: SEARCH KEY, 3: SEARCH MAXIMUM)" << endl;
    cout << "Select any value you want:";
}
int getValue()
{
    int m;
    cout << "Enter value: ";
    cin >> m;
    return m;
}
int getKey()
{
    int p;
    cout << "Enter key: ";
    cin >> p;
    return p;
}
int getVariant(int s)
{
    int k;
    cin >> k;
    while (k < 1 || k > s)
    {
        cout << "Incorrect input. Try again: ";
        cin >> k;
    }
    return k;
}
void stackIsEmpty()
{
    cout << "Stack is empty!" << endl;
}
void deletedElement(int value)
{
    cout << "Deleted element is " << value << endl;
}

void Print(Stack* top)
{
    Stack* pv = new Stack;
    pv = top;
    if (pv != NULL)
    {
        while (pv != NULL)
        {
            cout << "S[v:" << pv->item << ", k:" << pv->key << "], ";
            pv = pv->next;
        }
        cout << endl;
    }
    else
    {
        stackIsEmpty();
    }
}

void initialize(Stack** top, int value, int* count)
{
    *count = 1;
    Stack* pv = new Stack;
    pv->item = value;
    pv->next = NULL;
    pv->key = *count;
    *top = pv;
}

void push(Stack** top, int value, int* count)
{
    if (*top != NULL)
    {
        *count += 1;
        Stack* pv = new Stack;
        pv->item = value;
        pv->key = *count;
        pv->next = *top;
        *top = pv;
    }
    else 
    {
        stackIsEmpty();
    }
}

Stack* pop(Stack* top, int* count)
{
    if (top != NULL)
    {
        Stack* pv = new Stack;
        int value = top->item;
        pv = top;
        top = top->next;
        *count -= 1;
        delete pv;
        deletedElement(value);
    }
    else 
    {
        *count = 0;
        stackIsEmpty();
    }
    return top;
}

void SearchValue(Stack* top, int value)
{
    Stack* pv = new Stack;
    int position = 0, pos = -1;
    pv = top;
    if (pv != NULL)
    {
        position = 1;
        while (pv != NULL)
        {
            if (pv->item == value)
            {
                pos = position;
                cout << "Value that you entered is in position: " << position << endl;
            }
            pv = pv->next;
            position++;
        }
    }
    else
    {
        stackIsEmpty();
    }
    if (pos == -1)
    {
        cout << "Value that you entered is not found!" << endl;
    }
}

void SearchKey(Stack* top, int key, int* count)
{
    Stack* pv = new Stack;
    pv = top;
    bool found = false;
    if (count != 0)
    {
        while (pv != NULL)
        {
            if (pv->key == key)
            {
                found = true;
                cout << "Key that you entered is: S[v:" << pv->item << ", k:" << pv->key << "]" << endl;
                break;
            }
            pv = pv->next;
        }
        if (!found)
        {
            cout << "Key that you entered is not found!" << endl;
        }
    }
    else
    {
        stackIsEmpty();
    }
}

void SearchMaximum(Stack* top)
{
    Stack* pv = new Stack;
    pv = top;
    if (pv != NULL)
    {
        int max = pv->item;
        while (pv != NULL)
        {
            if (pv->item > max)
            {
                max = pv->item;
            }
            pv = pv->next;
        }
        cout << "Maximum value in stack is: " << max << endl;
    }
    else
    {
        stackIsEmpty();
    }
}

void Size(int* count)
{
    cout << "Size of stack is: " << *count << endl;
}

void ClearStack(Stack* top, int* count)
{
    Stack* pv = new Stack;
    pv = top;
    if (top != NULL)
    {
        while (pv != NULL)
        {
            Stack* temp = pv->next;
            *pv = {};
            pv = temp;
        }
    }
    else
    {
        stackIsEmpty();
    }
    *count = 1;
    delete pv;
}