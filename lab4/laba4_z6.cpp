
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{       
    
    string word;

    cout << "Enter word: ";

    cin >> word;

    string::size_type n = std::count(word.begin(), word.end(), '*');

    if (n)
    {
        auto m = word.size();
        word.resize( m + n);

        for (auto i = m; n != 0; )
        {
            if (word[--i] == '*')
            {
                word[i + n--] = ' ';
            }
            word[i + n] = word[i];
        }
    }

    cout << word << endl;

    return 0;
    // не работает если добавлять пробел
}