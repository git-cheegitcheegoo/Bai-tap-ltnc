#include <iostream>
using namespace std;
void print(int n)
{
    int decoy;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j <= n*2 - 1; j++)
        {
            decoy = n - i;
            if (j > decoy && j <= n*2 - 1 - decoy) cout << "*";
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
