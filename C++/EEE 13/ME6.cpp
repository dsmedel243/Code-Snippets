#include <iostream>
#include <map>
using namespace std;

int Q;

int main ()
{
    map<int, string> map1;
    cin >> Q;

    for( int a = 0; a != Q; a++)
    {
        int type = 0;
        cin >> type;
        if(type == 1)
        {
            string name;
            cin >> name;

            int grade;
            cin >> grade;
            map1[grade] = name;
        }
        else if(type == 2)
        {
            int key;
            cin >> key;
            if(map1.count(key) == 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << map1[key] << endl;                    
            }
        }
    }

    return 0;
}
