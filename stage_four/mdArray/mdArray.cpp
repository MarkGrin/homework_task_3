/**
 * @author Melnikov Lev Computer Security 161.1
 * @brief Task 3. Multidimensional array
 */

# include "mdArray.hpp"

# include <cstddef> /* std::size_t */
# include <cstring>

namespace mdArray
{

bool* Array::getElementPtr (const std::size_t* coordinates) const
{
    std::size_t index = 0u;
    std::size_t step = 1u;
    for (std::size_t i = 0u; i < dimensionNumber_; i++)
    {
        index += step * coordinates[i];
        step  *= dimensions_[i];
    }
    return data_ + index;
}

Array::Array ()
    :
    dimensionNumber_ (0u),
    dimensions_ (nullptr),
    data_ (nullptr)
{}

Array::~Array ()
{
    delete[] data_;
    delete[] dimensions_;
}

Array::Array (std::size_t dimensionNumber, const std::size_t* dimensions)
    :
    Array()
{
    resize (dimensionNumber, dimensions);
}

Array::Array (std::size_t dimensionNumber, const std::size_t* dimensions, bool initialValue)
    :
    Array()
{
    resize (dimensionNumber, dimensions, initialValue);
}

Array::Array (const Array& right)
    :
    Array ()
{
    if ( this == &right )
        return ;

    copy (right);
}

Array::Array (Array&& right)
    :
    Array()
{
    if ( this == &right )
        return ;

    data_ = right.data_;
    dimensions_ = right.dimensions_;
    dimensionNumber_ = right.dimensionNumber_;

    right.data_ = nullptr;
    right.dimensions_ = nullptr;
    right.dimensionNumber_ = 0;
}

Array& Array::operator = (const Array& right)
{
    if ( this == &right )
        return *this;

    copy (right);
    return *this;
}

Array& Array::operator = (Array&& right)
{
    if ( this == &right )
        return *this;

    data_ = right.data_;
    dimensions_ = right.dimensions_;
    dimensionNumber_ = right.dimensionNumber_;

    right.data_ = nullptr;
    right.dimensions_ = nullptr;
    right.dimensionNumber_ = 0;

    return *this;
}

void Array::copy (const Array& right)
{
    dimensionNumber_ = right.dimensionNumber_;
    std::size_t* newDimensions = new std::size_t[dimensionNumber_];

    std::size_t copySize = dimensionNumber_ ? 1u : 0u;
    for (std::size_t i = 0u; i < dimensionNumber_; i++)
    {
        newDimensions[i] = right.dimensions_[i];
        copySize *= dimensions_[i];
    }
    bool* newData = new bool[copySize];
    
    std::memcpy(newData, right.data_, copySize);

    delete[] data_;
    delete[] dimensions_;

    data_ = newData;
    dimensions_ = newDimensions;
}

std::size_t Array::resize (std::size_t dimensionNumber, const std::size_t* dimensions)
{
    delete[] data_;
    delete[] dimensions_;

    dimensionNumber_ = dimensionNumber;
    dimensions_ = new std::size_t[dimensionNumber_];

    std::size_t allocSize = dimensionNumber_ ? 1u : 0u;
    for (std::size_t i = 0u; i < dimensionNumber; i++)
    {
        dimensions_[i] = dimensions[i];
        allocSize *= dimensions_[i];
    }
    data_ = new bool[allocSize];

    return allocSize;
}

std::size_t Array::resize (std::size_t dimensionNumber, const std::size_t* dimensions, bool initialValue)
{
    std::size_t allocSize = resize(dimensionNumber, dimensions);

    for (std::size_t i = 0u; i < allocSize; i++)
        data_[i] = initialValue;

    return allocSize;
}

void Array::free ()
{
    delete[] data_;
    delete[] dimensions_;

    data_ = nullptr;
    dimensions_ = nullptr;
    dimensionNumber_ = 0u;
}

std::size_t Array::getDimensionSize (std::size_t i) const
{
    return dimensions_[i];
}

void Array::write (const std::size_t* coordinates, bool value)
{
    *(getElementPtr(coordinates)) = value;
}

bool Array::read (const std::size_t* coordinates) const
{
    return *(getElementPtr(coordinates));
}

bool Array::isIdentical (const Array& right) const
{
    if ( this == &right )
        return right.dimensionNumber_;

    if ( dimensionNumber_ != right.dimensionNumber_ )
        return false;
    if ( !dimensionNumber_ )
        return true;

    std::size_t sizeRight = 1;
    for (std::size_t i = 0; i < dimensionNumber_; i++)
        sizeRight *= right.dimensions_[i];

    std::size_t size = 1;
    for (std::size_t i = 0; i < dimensionNumber_; i++)
        size *= dimensions_[i];

    if ( size != sizeRight )
        return false;

    return memcmp (data_, right.data_, size) ? false : true;
}

} /* namespace mdArray */

