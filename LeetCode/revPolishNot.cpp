#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
        {
            st.push(stoi(tokens[i]));
            continue;
        }
        else
        {
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();

            if (tokens[i] == "+")
                st.push(x + y);
            else if (tokens[i] == "-")
                st.push(x - y);
            else if (tokens[i] == "*")
                st.push(x * y);
            else
                st.push(x / y);
        }
    }
    return st.top();
}

int main()
{
    vector<string> vtr{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(vtr);
    return 0;
}
