# include <iostream>
# include "mdArray.hpp"
# include "acme.hpp"

int main ()
{
    std::size_t x, y, z, radius, num;
    std::cout << "Enter simulation parameters\nCheese width:";
    std::cin >> x;
    std::cout << "\nCheese height:";
    std::cin >> y;
    std::cout << "\nCheese depth:";
    std::cin >> z;
    std::cout << "\nNumber of bombs:";
    std::cin >> num;
    std::cout << "\nRadius of bombs:";
    std::cin >> radius;

    if ( !std::cin || !x || !y || !z || !radius || !num )
    {
        std::cout << "\nFATAL ERROR!\nSome of inputs were incorrect!\nAborting\n";
        return 1;
    }

    std::size_t* coord = new size_t[3];
    coord[0] = x;
    coord[1] = y;
    coord[2] = z;

    mdArray::Array* array = mdArray::init (3, coord, true);

    for (std::size_t i = 0; i < num; i++)
        acme::bomb (array, coord, radius);

    std::cout << "After bombardment:\n";
    acme::printNice (array, coord);

    delete[] coord;
    mdArray::free (array);
    return 0;
}
