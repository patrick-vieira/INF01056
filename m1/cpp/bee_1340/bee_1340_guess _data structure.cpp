#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_elements;
    int a, b;


    // creata a prioriry queue
    priority_queue<int> pq;

    // create a stack
    stack<int> s;

    // create a queue
    queue<int> q;

    while (cin >> n_elements)
    {

        // clear the priority queue
        while (!pq.empty())
        {
            pq.pop();
        }

        // clear the stack
        while (!s.empty())
        {
            s.pop();
        }

        // clear the queue
        while (!q.empty())
        {
            q.pop();
        }

        bool is_pq = 1;
        bool is_stack = 1;
        bool is_queue = 1;

        for (int i = 0; i < n_elements; i++)
        {
            cin >> a >> b;

            if (a == 1)
            {
                pq.push(b);
                s.push(b);
                q.push(b);
            }
            else
            {
                if (!pq.empty() && pq.top() != b)
                {
                    is_pq = 0;
                }
                if (!s.empty() && s.top() != b)
                {
                    is_stack = 0;
                }
                if (!q.empty() && q.front() != b)
                {
                    is_queue = 0;
                }

                if(!pq.empty())                
                    pq.pop();

                if(!s.empty())
                    s.pop();
                
                if(!q.empty())
                    q.pop();
            }

            // cout << a + b << endl;
        }

        // stack
        // It's definitely a stack.

        // queue
        // It's definitely a queue.

        // priority queue
        // It's definitely a priority queue.

        // impossible
        // It can't be a stack, a queue or a priority queue.

        // not sure
        // It can be more than one of the three data structures mentioned above.

        if (is_pq + is_stack + is_queue > 1)
        {
            cout << "not sure" << endl;
        }
        else if (is_pq + is_stack + is_queue == 0)
        {
            cout << "impossible" << endl;
        }
        else if (is_pq)
        {
            cout << "priority queue" << endl;
        }
        else if (is_stack)
        {
            cout << "stack" << endl;
        }
        else if (is_queue)
        {
            cout << "queue" << endl;
        }
    }

    return 0;
}