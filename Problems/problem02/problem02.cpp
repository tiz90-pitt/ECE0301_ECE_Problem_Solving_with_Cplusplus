#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[])
{
    double voltage, current;
    int resistance = 1000;
    
    if (argc >= 2)
    {
        resistance = std::stod(argv[1]);
    }
    bool resistpos = (resistance > 0);
    if (!resistpos)
    {
        std::cout << "Invalid resistance, must be positive." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Enter voltage: " << std::endl;
    std::cin >> voltage; //No need for voltage = 5;

    // bool check = std::cin.good();

    // if (!check)
    // {
    //     std::cout << "Invalid voltage" << std::endl;
    //     return EXIT_FAILURE;
    // }
    if (voltage < 0)
    {
        std::cout << "Invalid voltage, must be positive." << std::endl;
        return EXIT_FAILURE;
    }
    if (voltage == 0)
    {
        std::cout << "Invalid voltage, cannot be divided by zero." << std::endl;
        return EXIT_FAILURE;
    }
    // current = voltage / resistance;
    // std::cout << "If R = 1000 Ohms and V = " << voltage << " Volts, then I = " << current << " Amps" << std::endl;

    //std::cout << "Resistance is " << argv[1] << std::endl;

        current = voltage / resistance;
        std::cout << "If R = " << resistance << std::fixed << std::setprecision(3) << " Ohms and V = " << voltage << " Volts, then I = " << current << " Amps" << std::endl;

// code below is placeholder for resistance by using cin for now
    // std::cout << "We are now using Ohm's Law again, please enter resistance: ";
    // std::cin >> resistance;

    return EXIT_SUCCESS;
}