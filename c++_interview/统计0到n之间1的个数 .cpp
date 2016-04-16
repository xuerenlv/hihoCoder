#include <iostream>
#include <cstring>
using namespace std;

int countOne(int n)
{
    int current = 0;
    int before = 0;
    int after = 0;
    int i = 1;
    int count = 0;
    while (n / i != 0)
    {
        current = n / i % 10;
        before = n / (i * 10);
        after = n - (n / i) * i;
        if (current > 1)
        {
            count += (before + 1) * i;
        }
        else if (current == 0)
        {
            count += before * i;
        }
        else if (current == 1)
        {
            count += before * i + after + 1;
        }

        i *= 10;
    }

    return count;
}

int main()
{
    int n;
    while (cin>>n)
    {
        cout<<countOne(n)<<endl;
    }

    return 0;
}
