#include <iostream>
using namespace std;
void print(int n)
{

    for (int i = 0; i<= n-1; i++)
    {
        for (int j = 1; j <= n*2 - 1; j++)
        {
            if (j > i && j <= n*2 - 1 - i ) cout << "*";
            else cout << " ";
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
