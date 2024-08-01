#include<bits/stdc++.h>
using namespace std;

int minimumDeviation(int shirts, int bags){
    if(bags == 1) return 0; // for a single bags deviation 0

    int deviations = (shirts % bags); // specail bag contais some extra shirts which is deviation
    int normalBagsContains = (shirts / bags) + 1;  

    int specialBagContains = shirts - normalBagsContains * (bags - 1);

    if(specialBagsContains >= 0){  // check for enough shirts available
        deviations = min(deviations , abs(normalBagsContains - specialBagsContains));
    } 
    return deviations; 
}

//Test cases explanation
//103 10 -> 10 10 10 10 10 10 10 10 10 13 => 3
//100 6 -> 17 17 17 17 17 15 => 2
//107 10 -> 11 11 11 11 11 11 11 11 11 8 => 3

int main() {
    //If the number is over 1e9 we will use long long instead int type
    int shirts, bags;
    cin >> shirts >> bags; 
    cout << "Minimum deviation is : " << minimumDeviation(shirts, bags) << '\n';
   return 0;
}

