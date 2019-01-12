#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Option 5 zpi-zp82-005*/
const float A = 2.54;
const float B = 1.23;
const float C = -2.14;
const float D = -0.23;

/* Represent calculation f(x) = 2*cos(a^b) + | arccos(-√c/d) | */
int main() {

    /*arccos(x) = y; cos(y) = x; 0<=y<=П, |x|<=1;*/
    float argument = -sqrt(C/D);

    if( fabs(argument) <= 1) {

        printf("f(x) = 2*cos(a^b) + | arccos(-√c/d) | result is %f \n", 2*cos(pow(A, B)) + abs(acos(argument)));

    } else {

        printf("You can not calculate arccos. \nExceptional condition |argument| > 1. \n");

    }


/*return value int*/
    return 0;
}


#include <cmath>
#include <iostream>

/*
template<typename T>
T taskFunction(const T t, const size_t i) {
    if (i > 2) {
        T result{};

        for (size_t k = 1; k <= i; ++k) {
            result += 1 / k;
        }

        return result * std::sin(t);
    }
    return std::log(t);
}

template<typename T>
T AskUserForParameter(const char* name, std::ostream& output, std::istream& input) {
    T result{};
    output << name << " = ";
    input >> result;
    return result;
}

int main() {
    auto& output = std::cout;
    auto& input = std::cin;

    auto t = AskUserForParameter<float>("t", output, input);
    auto i = AskUserForParameter<int>("i", output, input);

    if (i < 1) {
        output << "Invalid input parameter i. It should be more than zero" << std::endl;
        return 1;
    }

    auto result = taskFunction(t, static_cast<size_t>(i));
    output << "Result: " << result << std::endl;

    return 0;
}
*/
