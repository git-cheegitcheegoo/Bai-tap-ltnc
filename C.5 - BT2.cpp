#include <iostream>
using namespace std;
void print(int n)
{
    int decoy;
    for (int i = 1; i<= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            decoy = j + i - 1;
            if (decoy > n) decoy -= n;
            cout << decoy << " ";
        }
        cout << endl;
    }
}
int main()
{
   int n;
    cin >> n;
    print(n);
    return 0;
}