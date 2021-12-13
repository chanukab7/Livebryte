#include <iostream>
using namespace std;

int main(){
    const char test[] = R"rawliteral(
        heh
        hehi
    )rawliteral";

    const char test2[] = R"rawliteral(
        hiihoo
    )rawliteral";

    sprintf(test, "%s", test2);


}