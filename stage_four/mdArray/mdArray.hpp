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
 * This class represents multidimensional array.
 */
class Array {

    bool* getElementPtr (const std::size_t* coordinates) const;

    std::size_t  dimensionNumber_;
    std::size_t* dimensions_;
    bool* data_;

    public:

/**
 * Constructs zero sized trivial object
 */
    Array ();
    ~Array();

/**
 * Equals calling Array() and resize (...)
 */
    Array (std::size_t dimensionNumber, const std::size_t* dimensions);

/**
 * Equals calling Array() and resize (...)
 */
    Array (std::size_t dimensionNumber, const std::size_t* dimensions, bool initialValue);

    Array (const Array&);
    Array (Array&&);

    Array& operator = (const Array&);
    Array& operator = (Array&&);

    void copy (const Array& right);

/**
 * This function resizes array.
 * All previous stored data will be lost.
 *
 * If one of the params is zero, then object will be set
 * to trivial zero size state.
 *
 * @param dimensionNumber number of dimensions
 * @param dimensions array with sizes of dimensions
 *
 * @return number of elements created
 *
 * @complexity O(1)
 */
    std::size_t resize (std::size_t dimensionNumber, const std::size_t* dimensions);

/**
 * This function resizes multidimensional array and fills it
 * with inital values.
 *
 * If dimensionNumber or dimensions is zero, then object will be set
 * to trivial zero size state.
 *
 * @param dimensionNumber number of dimensions
 * @param dimensions array with sizes of dimensions
 * @param initialValue initial value
 *
 * @return number of elements created
 *
 * @complexity O(n), where n is the result of multiplication
 *                   of sizes of all dimensions.
 */
    std::size_t resize (std::size_t dimensionNumber, const std::size_t* dimensions, bool initialValue);

/**
 * This function sets object to trivial zero size state.
 * This will free any dinamically allocated memory.
 *
 * @complexity O(1)
 */
    void free ();

/**
 * This function returns number of dimensions in array.
 *
 * @return number of dimensions in array, 0 if array is trival zero sized.
 *
 * @complexity O(1)
 */
    std::size_t getDimensionNumber () const
    {
        return dimensionNumber_;
    }

/**
 * This function returns size of array's dimension.
 *
 * If i>=getDimensionNumber OR object is trivial zero sized,
 * then function returns zero.
 * 
 * @param i index of a dimension
 *
 * @return size of array's dimension,
 *
 * @complexity O(1)
 */
    std::size_t getDimensionSize (std::size_t i) const;

/**
 * This function writes value to array
 *
 * Undefined behaviour on out-of-range write
 *
 * @param coordinates array with coordinates
 * @param value value to write
 *
 * @complexity O(1)
 */
    void write (const std::size_t* coordinates, bool value);

/**
 * This function reads value from an array
 *
 * Undefined behaviour on out-of-range read
 * 
 * @param coordinates array with coordinates
 *
 * @return value that was read
 *
 * @complexity O(1)
 */
    bool read  (const std::size_t* coordinates) const;

/**
 * This function checks if two arrays are identical
 *
 * @return true - identical
 *         false - different or both invalid
 *
 * @complexity O(n) where n is the result of multiplication
 *                  of all sizes of dimensions of array
 */
    bool isIdentical (const Array& right) const;


/**
 * The same as calling isIdentical, but on operator form
 */
    bool operator == (const Array& right) const
    {
        return isIdentical (right);
    }

};

} /* namespace mdArray */

# endif /* HPP_71A2B637EFC840C8961B25D75659B872 */
