# define BOOST_TEST_MODULE all
# include <boost/test/included/unit_test.hpp>

# include "mdArray.hpp"

BOOST_AUTO_TEST_CASE(allocationOneDimension)
{
    {
        std::size_t* coord = new size_t[1];
        coord[0] = 5;
        mdArray::Array array (1, coord);

        BOOST_TEST ( array.getDimensionNumber () == 1 );

        BOOST_TEST ( array.getDimensionSize (0) == 5 );

        delete[] coord;
    }
}

BOOST_AUTO_TEST_CASE(allocationTwoDimension)
{
    {
        std::size_t* coord = new size_t[2];
        coord[0] = 7;
        coord[1] = 3;
        mdArray::Array array (2, coord);

        BOOST_TEST ( array.getDimensionNumber () == 2 );

        BOOST_TEST ( array.getDimensionSize (0) == 7 );
        BOOST_TEST ( array.getDimensionSize (1) == 3 );

        delete[] coord;
    }
}

BOOST_AUTO_TEST_CASE(allocationThreeDimension)
{
    {
        std::size_t* coord = new size_t[3];
        coord[0] = 8;
        coord[1] = 4;
        coord[2] = 7;
        mdArray::Array array (3, coord);

        BOOST_TEST ( array.getDimensionNumber () == 3 );

        BOOST_TEST ( array.getDimensionSize (0) == 8 );
        BOOST_TEST ( array.getDimensionSize (1) == 4 );
        BOOST_TEST ( array.getDimensionSize (2) == 7 );

        delete[] coord;
    }
}

BOOST_AUTO_TEST_CASE(ioOneDimension)
{
    {
        std::size_t* coord = new size_t[1];
        constexpr std::size_t sizeX = 3;
        coord[0] = sizeX;
        mdArray::Array array (1, coord);

        bool values[sizeX] = {true, false, false};

        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord[0] = i;
            array.write (coord, values[i]);
        }
        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord[0] = i;
            BOOST_TEST ( array.read (coord) == values[i] );
        }

        delete[] coord;

    }
}

BOOST_AUTO_TEST_CASE(ioTwoDimension)
{
    {
        std::size_t* coord = new size_t[2];
        constexpr std::size_t sizeX = 3;
        constexpr std::size_t sizeY = 2;
        coord[0] = sizeX;
        coord[1] = sizeY;
        mdArray::Array array (2, coord);

        bool values[sizeY][sizeX] = {{true, false, false},{false, true, true}};

        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord[0] = i;
            for (std::size_t j = 0; j < sizeY; j++)
            {
                coord[1] = j;
                array.write (coord, values[j][i]);
            }
        }
        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord[0] = i;
            for (std::size_t j = 0; j < sizeY; j++)
            {
                coord[1] = j;
                BOOST_TEST ( array.read (coord) == values[j][i] );
            }
        }

        delete[] coord;

    }
}

BOOST_AUTO_TEST_CASE(ioThreeDimension)
{
    {
        std::size_t* coord = new size_t[3];
        constexpr std::size_t sizeX = 3;
        constexpr std::size_t sizeY = 2;
        constexpr std::size_t sizeZ = 4;
        coord[0] = sizeX;
        coord[1] = sizeY;
        coord[2] = sizeZ;
        mdArray::Array array (3, coord);

        bool values[sizeZ][sizeY][sizeX] = {{{true, false, false}, {false, true, true}},
                                            {{false, false, false},{false, true, true}},
                                            {{true, true, false},  {false, true, true}},
                                            {{true, false, true}  ,{false, true, true}}};

        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord[0] = i;
            for (std::size_t j = 0; j < sizeY; j++)
            {
                coord[1] = j;
                for (std::size_t k = 0; k < sizeZ; k++)
                {
                    coord[2] = k;
                    array.write (coord, values[k][j][i]);
                }
            }
        }
        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord[0] = i;
            for (std::size_t j = 0; j < sizeY; j++)
            {
                coord[1] = j;
                for (std::size_t k = 0; k < sizeZ; k++)
                {
                    coord[2] = k;
                    BOOST_TEST ( array.read (coord) == values[k][j][i] );
                }
            }
        }

        delete[] coord;

    }
}
