# include "acme.hpp"

# include <iostream>
# include <cmath>
# include <random>

namespace acme
{

namespace
{
    int uniform_random(int min,int max)
    {
        static std::mt19937 prng(std::random_device{}());
        return std::uniform_int_distribution<>(min,max)(prng);
    }

    double distance (int x1, int y1, int z1,
                     int x2, int y2, int z2)
    {
        return hypot( hypot(x1 - x2, y1 - y2), z1 - z2);
    }
}

void bomb (mdArray::Array& array, const std::size_t* dimensions, std::size_t radius)
{
    int bomb_x = uniform_random(0, dimensions[0]);
    int bomb_y = uniform_random(0, dimensions[1]);
    int bomb_z = uniform_random(0, dimensions[2]);

    std::size_t start_x = bomb_x - static_cast<int>(radius) > 0 ? bomb_x - radius : 0;
    std::size_t start_y = bomb_y - static_cast<int>(radius) > 0 ? bomb_y - radius : 0;
    std::size_t start_z = bomb_z - static_cast<int>(radius) > 0 ? bomb_z - radius : 0;

    std::size_t stop_x = bomb_x + radius;
    std::size_t stop_y = bomb_y + radius;
    std::size_t stop_z = bomb_z + radius;

    stop_x = stop_x > dimensions[0] ? dimensions[0] : stop_x;
    stop_y = stop_y > dimensions[1] ? dimensions[1] : stop_y;
    stop_z = stop_z > dimensions[2] ? dimensions[2] : stop_z;

    std::size_t coord[3] = {0, 0, 0};
    for (std::size_t x = start_x; x < stop_x; x++)
    {
        for (std::size_t y = start_y; y < stop_y; y++)
        {
            for (std::size_t z = start_z; z < stop_z; z++)
            {
                if ( distance (bomb_x, bomb_y, bomb_z, x, y, z) <= radius )
                {
                    coord[0] = x;
                    coord[1] = y;
                    coord[2] = z;
                    array.write (coord, false);
                }
            }
        }
    }
}

void printNice (const mdArray::Array& array, const std::size_t* dimensions)
{
    std::size_t coord[3] = {0, 0, 0};

    for (std::size_t z = 0; z < dimensions[2]; z++)
    {
        coord[2] = z;
        std::cout << "\n  / Z\n";
        std::cout << " /     Depth(Z) of slice : " << z << "\n";
        std::cout << "/";
        for (std::size_t x = 0; x < dimensions[0]; x++)
            std::cout << "-";
        std::cout << "> X\n";
        for (std::size_t y = 0; y < dimensions[1]; y++)
        {
            coord[1] = y;
            std::cout << "|";
            for (std::size_t x = 0; x < dimensions[0]; x++)
            {
                coord[0] = x;
                char output = array.read (coord) ? '#' : ' ';
                std::cout << output;
            }
            std::cout << "\n";
        }
        std::cout << "v Y\n";
    }
}

void print (const mdArray::Array& array, const std::size_t* dimensions)
{
    std::size_t coord[3] = {0, 0, 0};

    for (std::size_t z = 0; z < dimensions[2]; z++)
    {
        coord[2] = z;
        std::cout << "\n";
        for (std::size_t y = 0; y < dimensions[1]; y++)
        {
            coord[1] = y;
            for (std::size_t x = 0; x < dimensions[0]; x++)
            {
                coord[0] = x;
                char output = array.read (coord) ? '#' : ' ';
                std::cout << output;
            }
            std::cout << "\n";
        }
        std::cout << "---";
    }
    std::cout << "\n";
}


}
