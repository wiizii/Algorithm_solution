#include <iostream>
#include <algorithm>
using namespace std;


int N;
int cache[3]={0};

int minCost(void)
{
    int RGB[3];
    int red, green, blue;
    cin >> red >> green >> blue;
    RGB[0] = red; RGB[1] = green; RGB[2] = blue;
    for(int i=1;i<N;i++)
    {
        cin >> red >> green >> blue;
        for(int i=0;i<3;i++)
            cache[i] = RGB[i];
        RGB[0] = red + min(cache[1],cache[2]);
        RGB[1] = green + min(cache[0],cache[2]);
        RGB[2] = blue + min(cache[0],cache[1]);
    }
    return RGB[0] > RGB[1] ? (RGB[1] > RGB[2] ? RGB[2]:RGB[1]) : (RGB[0] > RGB[2] ? RGB[2] : RGB[0]);
}

int main(){
    cin >> N;
    cout << minCost() << endl;
    return 0;
}
