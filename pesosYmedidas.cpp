#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Tortuga
{
    int w, s;
};

bool peso(const Tortuga &t1, const Tortuga &t2)
{
   return t1.s < t2.s;
}

vector<Tortuga> T;
int arr[5607];

void problema()
{
    sort(T.begin(), T.end(), peso);

    fill(arr, arr + 5607, numeric_limits<int>::max());
    arr[0] = 0;
    
    int maxNTortugas = 0;

    for (int i = 0; i < T.size(); ++i)
        for (int j = maxNTortugas; j >= 0; --j)
            
            if (T[i].s >= arr[j] + T[i].w
                && T[i].w + arr[j] < arr[j + 1])
            {
                arr[j + 1] = arr[j] + T[i].w;
                maxNTortugas = max(maxNTortugas, j + 1);
            }
    
    cout << maxNTortugas << endl;
}

int main()
{
    Tortuga t;
    while (cin >> t.w >> t.s)
        T.push_back(t);

    problema();
}