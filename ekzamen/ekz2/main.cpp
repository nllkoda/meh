#include <iostream>
#include <algorithm>
#include <vector>

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <bitset>

using namespace std;


int main() {

        int32_t b = 251; //вводим b
        cout << bitset<8>(b) << endl;

        int k = 128; //10000000
        int k1, count=0;

        for (int i = 7; i >= 1; i--){

            k1 = k & b; //действуем операцией И
            //смотрим 1 или 0 выходит в результате

            if (k1){
                count++;
            }

            k = k >> 1; //двигаем 1 вправо
        }

        cout << "count " << count << endl;;
        //если мы насчитали четное кол-во единиц,
        //то мы ставим 0 в конце (сложение мод 2)
        //в ином случае - 1
        int y;
        if (count % 2){
            y = 1;
            b = b | y;
        } else {
            y = 0;
            b = b - 1;
        }

        cout << "res " << bitset<8>(b) << endl;

  return 0;
}
