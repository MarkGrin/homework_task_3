# ifndef HPP_F3C7F4F57F0C4B39AB3DE30C21AE4B8C

# define HPP_F3C7F4F57F0C4B39AB3DE30C21AE4B8C

# include <cstddef>
# include "mdArray.hpp"

namespace acme
{

/**
 *
 * This function sets values in three dimensional array to false in spherical area in random place
 * with random radius
 *
 * @param array array to write
 * @param dimensions size of array
 * @param radius radius of an sphere
 *
 * radiusMin should be <= radiusMax
 *
 * @complexity linear to width*height*depth of array
 */
void bomb (mdArray::Array& array, const std::size_t* dimensions, std::size_t radius);

/**
 *
 * This function prints contents of array in slices
 *
 * @param array array to print
 * @param dimensions sizes of dimensions of array
 *
 * @complexity linear to width*height*depth of array
 */
void print (const mdArray::Array& array, const std::size_t* dimensions);

/**
 *
 * This function prints contents of array in slices with nice pseudo graphics
 *
 * @param array array to print
 * @param dimensions sizes of dimensions of array
 *
 * @complexity linear to width*height*depth of array
 */
void printNice (const mdArray::Array& array, const std::size_t* dimensions);

}

# endif /* HPP_F3C7F4F57F0C4B39AB3DE30C21AE4B8C */
