#include <cmath>
#include "Math.cpp"

int calcPermutations(float val1, float val2, bool with_rep){
    if(with_rep){
        return (powf(val1, val2));
    } else {
        return factorial(val1) / factorial(val1 - val2);
    }
}