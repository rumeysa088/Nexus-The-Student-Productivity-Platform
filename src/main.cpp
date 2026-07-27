#include <iostream>
#include "../include/User.h"

using namespace std;

int main()
{
    cout << "=====================================\n";
    cout << "         Welcome to Nexus\n";
    cout << "    Your Academic Command Center\n";
    cout << "=====================================\n\n";

    User user1("rumaisa123",
               "password123",
               "Rumaisa Abbasi",
               "rumaisa@example.com");

    user1.displayUser();

    return 0;
}