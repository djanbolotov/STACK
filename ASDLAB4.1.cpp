//#include <iostream>
//using namespace std;
//
//struct Stack
//{
//    int item;
//    int key;
//};
//
//void initialize(Stack*, int, int*);
//void push(Stack*, int, int*);
//void pop(Stack*, int*);
//void Print(Stack*, int);
//void SearchValue(Stack*, int, int);
//void SearchKey(Stack*, int, int);
//void SearchMaximum(Stack*, int);
//void Size(int);
//void ClearStack(Stack*, int*);
//
//void stackIsEmpty();
//void deletedElement(int);
//int getVariant(int);
//int getValue();
//int getKey();
//void printMenu();
//void printSearchMenu();
//
//int main()
//{
//    const int MAXN = 100;
//    Stack topStack[MAXN];
//    Stack *top = topStack;
//    int count = 0, v = 0, v2 = 0, value, key;
//    int* Count = &count;
//    do {
//        system("CLS");
//        printMenu();
//        v = getVariant(8);
//        switch (v)
//        {
//        case 1:
//            value = getValue();
//            initialize(top, value, Count);
//            break;
//        case 2:
//            value = getValue();
//            push(top, value, Count);
//            break;
//        case 3:
//            pop(top, Count);
//            break;
//        case 4:
//            printSearchMenu();
//            v2 = getVariant(3);
//            switch (v2)
//            {
//            case 1:
//                value = getValue();
//                SearchValue(top, value, count);
//                break;
//            case 2:
//                key = getKey();
//                SearchKey(top, key, count);
//                break;
//            case 3:
//                SearchMaximum(top, count);
//                break;
//            }
//            break;
//        case 5:
//            ClearStack(top, Count);
//            break;
//        case 6:
//            Print(top, count);
//            break;
//        case 7:
//            Size(count);
//            break;
//        }
//        if (v != 6 && v != 8)
//        {
//            Print(top, count);
//        }
//        if (v != 8)
//        {
//            system("pause");
//        }
//    } while (v < 8);
//}
//
//void printMenu()
//{
//    cout << "(1: INITIALIZE, 2: PUSH, 3: POP, 4: SEARCH, 5: CLEAR, 6: OUTPUT, 7: SIZE, 8: EXIT)" << endl;
//    cout << "Select any value you want:";
//}
//void printSearchMenu()
//{
//    cout << "(1: SEARCH VALUE, 2: SEARCH KEY, 3: SEARCH MAXIMUM)" << endl;
//    cout << "Select any value you want:";
//}
//int getValue()
//{
//    int m;
//    cout << "Enter value: ";
//    cin >> m;
//    return m;
//}
//int getKey()
//{
//    int p;
//    cout << "Enter key: ";
//    cin >> p;
//    return p;
//}
//int getVariant(int s)
//{
//    int k;
//    cin >> k;
//    while (k < 1 || k > s)
//    {
//        cout << "Incorrect input. Try again: ";
//        cin >> k;
//    }
//    return k;
//}
//void stackIsEmpty()
//{
//    cout << "Stack is empty!" << endl;
//}
//void deletedElement(int value)
//{
//    cout << "Deleted element is " << value << endl;
//}
//
//void Print(Stack* top, int count)
//{
//    if (count > 1)
//    {
//        for (int i = 0; i < count - 1; i++)
//        {
//            cout << "S[v:" << top[i].item << ", k:" << top[i].key << "], ";
//        }
//        cout << endl;
//    }
//    else
//    {
//        stackIsEmpty();
//    }
//}
//
//void initialize(Stack* top, int value, int* count)
//{
//    *count = 1;
//    top[0].item = value;
//    top[0].key = *count;
//    *count += 1;
//}
//
//void push(Stack* top, int value, int* count)
//{
//    if (*count > 1)
//    {
//        for (int i = *count; i > 0; i--)
//        {
//            top[i].item = top[i - 1].item;
//            top[i].key = top[i - 1].key;
//        }
//        top[0].item = value;
//        top[0].key = *count;
//        *count += 1;
//    }
//}
//
//void pop(Stack* top, int* count)
//{
//    if (*count > 1)
//    {
//        int value = top[0].item;
//        for (int i = 0; i < *count - 1; i++)
//        {
//            top[i].item = top[i + 1].item;
//            top[i].key = top[i + 1].key;
//        }
//        deletedElement(value);
//        *count -= 1;
//    }
//}
//
//void SearchValue(Stack* top, int value, int count)
//{
//    if (count > 1)
//    {
//        bool found = false;
//        for (int i = 0; i < count; i++)
//        {
//            if (top[i].item == value)
//            {
//                cout << "Value that you entered is found in position: " << i + 1 << endl;
//                found = true;
//            }
//        }
//        if (!found)
//        {
//            cout << "Value that you entered is not found!" << endl;
//        }
//    }
//}
//
//void SearchKey(Stack* top, int key, int count)
//{
//    if (count > 1)
//    {
//        bool found = false;
//        for (int i = 0; i < count; i++)
//        {
//            if (top[i].key == key)
//            {
//                cout << "Key that you entered is found: S[v:" << top[i].item << ", k:" << top[i].key << "]" << endl;
//                found = true;
//                break;
//            }
//        }
//        if (!found)
//        {
//            cout << "Key that you entered is not found!" << endl;
//        }
//    }
//}
//
//void SearchMaximum(Stack* top, int count)
//{
//    if (count > 1)
//    {
//        int max = top[0].item;
//        for (int i = 1; i < count; i++)
//        {
//            if (top[i].item > max)
//            {
//                max = top[i].item;
//            }
//        }
//        cout << "Maximum value in stack is: " << max << endl;
//    }
//}
//
//void Size(int count)
//{
//    cout << "Size of stack is " << count - 1 << endl;
//}
//
//void ClearStack(Stack* top, int* count)
//{
//    if (*count > 1)
//    {
//        for (int i = 0; i < *count; i++)
//        {
//            top[i].item = 0;
//            top[i].key = 0;
//        }
//        *count = 2;
//    }
//}