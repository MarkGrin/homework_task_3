/**
 * @author Melnikov Lev Computer Security 161.1
 * @brief Task 3. Multidimensional array
 */

# include "mdArray.hpp"

# include <cstddef> /* std::size_t */

namespace mdArray
{

struct Array
{
    std::size_t dimensionNumber;
    std::size_t* coordinates;
    bool* data;
};


namespace
{

inline bool* getElementPtr (const Array* obj, std::size_t* coordinates)
{
    std::size_t index = 0;
    std::size_t step = 1;
    for (std::size_t i = 0; i < obj->dimensionNumber; i++)
    {
        index += step * coordinates[i];
        step  *= obj->coordinates[i];
    }
    return obj->data + index;
}

}


Array* init (std::size_t dimensionNumber, std::size_t* dimensions)
{
    Array* obj = new Array;
    obj->dimensionNumber = dimensionNumber;
    obj->coordinates = new std::size_t[dimensionNumber];

    std::size_t allocSize = 1;
    for (std::size_t i = 0; i < dimensionNumber; i++)
    {
        obj->coordinates[i] = dimensions[i];
        allocSize *= dimensions[i];
    }
    obj->data = new bool[allocSize];

    return obj;
}

Array* init (std::size_t dimensionNumber, std::size_t* dimensions, bool initialValue)
{
    Array* obj = new Array;
    obj->dimensionNumber = dimensionNumber;
    obj->coordinates = new std::size_t[dimensionNumber];

    std::size_t allocSize = 1;
    for (std::size_t i = 0; i < dimensionNumber; i++)
    {
        obj->coordinates[i] = dimensions[i];
        allocSize *= dimensions[i];
    }
    obj->data = new bool[allocSize];

    for (std::size_t i = 0; i < allocSize; i++)
        obj->data[i] = initialValue;

    return obj;
}

void free (Array* obj)
{
    delete[] obj->data;
    delete[] obj->coordinates;
    delete obj;
}

std::size_t getDimensionNumber (const Array* obj)
{
    return obj->dimensionNumber;
}

std::size_t getDimensionSize (const Array* obj, std::size_t i)
{
    return obj->coordinates[i];
}

void write (Array* obj, std::size_t* coordinates, bool value)
{
    *(getElementPtr(obj, coordinates)) = value;
}

bool read  (const Array* obj, std::size_t* coordinates)
{
    return *(getElementPtr(obj, coordinates));
}

bool isIdentical (const Array* a, const Array* b)
{
    std::size_t size = 1;
    for (std::size_t i = 0; i < a->dimensionNumber; i++)
        size *= a->coordinates[i];

    for (std::size_t i = 0; i < size; i++)
        if ( a->data[i] != b->data[i] )
            return false;

    return true;
}

}
