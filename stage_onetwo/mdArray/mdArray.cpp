/**
 * @author Melnikov Lev Computer Security 161.1
 * @brief Task 3. Multidimensional array
 */

# include "mdArray.hpp"

# include <cstddef> /* std::size_t */
# include <iostream>

namespace mdArray
{

namespace
{
    inline bool* getElementPtr (const Array* obj, const Coordinates* size)
    {
        std::size_t index = 0;
        std::size_t step = 1;
        for (std::size_t i = 0; i < obj->size.dimensionNumber; i++)
        {
            index += step * size->coordinates[i];
            step  *= obj->size.coordinates[i];
        }
        return obj->data + index;
    }
}

std::size_t init (Array* obj, const Coordinates* size)
{
    obj->size.dimensionNumber = size->dimensionNumber;
    obj->size.coordinates = new std::size_t[obj->size.dimensionNumber];

    std::size_t allocSize = 1;
    for (std::size_t i = 0; i < obj->size.dimensionNumber; i++)
    {
        obj->size.coordinates[i] = size->coordinates[i];
        allocSize *= size->coordinates[i];
    }
    obj->data = new bool[allocSize];

    return allocSize;
}

std::size_t init (Array* obj, const Coordinates* size, bool initialValue)
{
    std::size_t allocSize = init (obj, size);

    for (std::size_t i = 0; i < allocSize; i++)
        obj->data[i] = initialValue;

    return allocSize;
}

void free (Array* obj)
{
    delete[] obj->data;
    delete[] obj->size.coordinates;
}

void write (Array* obj, const Coordinates* place, bool value)
{
    *(getElementPtr(obj, place)) = value;
}

bool read  (const Array* obj, const Coordinates* place)
{
    return *(getElementPtr(obj, place));
}

bool isIdentical (const Array* a, const Array* b)
{
    std::size_t size = 1;
    for (std::size_t i = 0; i < a->size.dimensionNumber; i++)
        size *= a->size.coordinates[i];

    for (std::size_t i = 0; i < size; i++)
        if ( a->data[i] != b->data[i] )
            return false;

    return true;
}

}
