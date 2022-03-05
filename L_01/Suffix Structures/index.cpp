#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    int cnt_s[26] = {0}, cnt_t[26] = {0};
    bool need_tree = false, array = false, automaton = false;
    for (int i = 0; i < s.size(); i++)
    {
        cnt_s[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        cnt_t[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt_t[i] > cnt_s[i])
        {
            need_tree = true;
        }
        else if (cnt_t[i] < cnt_s[i])
        {
            automaton = true;
        }
    }

    int index_found = 0, match = -1;
    for (int i = 0; i < s.size(); i++)
    {
        index_found = s.find_first_of(t[i], match + 1);
        if (index_found > match)
        {
            match = index_found;
        }
        else
        {
            array = true;
            break;
        }
    }

    if (need_tree)
    {
        cout << "need tree";
    }
    else if (automaton && array)
    {
        cout << "both";
    }
    else if (automaton)
    {
        cout << "automaton";
    }
    else
    {
        cout << "array";
    }

    return 0;
}