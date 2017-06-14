/**
 * @author Melnikov Lev Computer Security 161.1
 * @brief Task 3. Multidimensional array
 */

# ifndef HPP_71A2B637EFC840C8961B25D75659B872

# define HPP_71A2B637EFC840C8961B25D75659B872

# include <cstddef> /* std::size_t */

namespace mdArray
{

/**
 * This struct contains all data that is needed to work
 * with multidiemsional array.
 */
struct Array;

/**
 * This function creates multidimensional array.
 * If obj points to already created array it will be overridden.
 *
 * @param dimensionNumber number of dimensions
 * @param dimensions array with sizes of dimensions
 *
 * @return newly created array
 *
 * @complexity O(1)
 */
Array* init (std::size_t dimensionNumber, std::size_t* dimensions);

/**
 * This function creates multidimensional array and fills it
 * with inital values.
 * If obj points to already created array it will be overridden.
 *
 * @param dimensionNumber number of dimensions
 * @param dimensions array with sizes of dimensions
 * @param initialValue initial value
 *
 * @return newly created array
 *
 * @complexity O(n), where n is the result of multiplication
 *                   of sizes of all dimensions.
 */
Array* init (std::size_t dimensionNumber, std::size_t* dimensions, bool initialValue);

/**
 * This function deletes any memory that was allocated by array
 *
 * @param obj array to destroy
 *
 * @complexity O(1)
 */
void free (Array* obj);

/**
 * This function returns number of dimensions in array.
 *
 * @param obj pointer to array to be queried.
 *
 * @return number of dimensions in array, 0 if array is invalid.
 *
 * @complexity O(1)
 */
std::size_t getDimensionNumber (const Array* obj);

/**
 * This function returns size of array's dimension
 * 
 * @param obj array to be queried
 * @param i index of a dimension
 *
 * @return size of array's dimension,
 *
 * @complexity O(1)
 */
std::size_t getDimensionSize (const Array* obj, std::size_t i);

/**
 * This function writes value to array
 *
 * @param obj array to write to
 * @param coordinates array with coordinates
 * @param value value to write
 *
 * @complexity O(1)
 */
void write (Array* obj, std::size_t* coordinates, bool value);

/**
 * This function reads value from an array
 * 
 * @param obj array to read from
 * @param coordinates array with coordinates
 *
 * @return value that was read
 *
 * @complexity O(1)
 */
bool read  (const Array* obj, std::size_t* coordinates);

/**
 * This function checks if two arrays are identical
 *
 * @return true - identical
 *         false - different or both invalid
 *
 * @complexity O(n) where n is the result of multiplication
 *                  of all sizes of dimensions of array
 */
bool isIdentical (const Array* a, const Array* b);

}

# endif /* HPP_71A2B637EFC840C8961B25D75659B872 */
