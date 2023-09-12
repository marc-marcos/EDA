#include <iostream>
#include <queue>

using namespace std;

int get_greatest_number(priority_queue<int> &q)
{
    return q.top();
}

void store_number(priority_queue<int> &q, int n)
{
    q.push(n);
}

void remove_number(priority_queue<int> &q)
{
    q.pop();
}

void change_top_value(priority_queue<int> &q, int units)
{
    int top = q.top();
    q.pop();
    q.push(top + units);
}

int main()
{
    char option;
    priority_queue<int> q;

    while (cin >> option)
    {
        if (option == 'A')
        {
            if (not q.empty())
            {
                cout << get_greatest_number(q) << endl;
            }

            else
            {
                cout << "error!" << endl;
            }
        }

        else if (option == 'S')
        {
            int x;
            cin >> x;
            store_number(q, x);
        }

        else if (option == 'R')
        {
            if (not q.empty())
            {
                remove_number(q);
            }

            else
            {
                cout << "error!" << endl;
            }
        }

        else if (option == 'I')
        {
            int x;
            cin >> x;

            if (not q.empty())
            {
                change_top_value(q, x);
            }

            else
            {
                cout << "error!" << endl;
            }
        }

        else
        {
            int x;
            cin >> x;

            if (not q.empty())
            {
                change_top_value(q, x * (-1));
            }

            else
            {
                cout << "error!" << endl;
            }
        }
    }
}