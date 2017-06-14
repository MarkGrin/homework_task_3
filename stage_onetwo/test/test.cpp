# define BOOST_TEST_MODULE all
# include <boost/test/included/unit_test.hpp>
# include <iostream>

# include "mdArray.hpp"

BOOST_AUTO_TEST_CASE(allocationOneDimension)
{
    {
        mdArray::Coordinates coord = {1, new size_t[1]};
        coord.coordinates[0] = 5;
        mdArray::Array array;

        mdArray::init (&array, &coord);

        BOOST_TEST ( mdArray::getDimensionNumber (&array) == 1 );

        BOOST_TEST ( mdArray::getDimensionSize (&array, 0) == 5 );

        mdArray::free (&array);
        delete[] coord.coordinates;
    }
}

BOOST_AUTO_TEST_CASE(allocationTwoDimension)
{
    {
        mdArray::Coordinates coord = {2, new size_t[2]};
        coord.coordinates[0] = 7;
        coord.coordinates[1] = 3;
        mdArray::Array array;

        mdArray::init (&array, &coord);

        BOOST_TEST ( mdArray::getDimensionNumber (&array) == 2 );

        BOOST_TEST ( mdArray::getDimensionSize (&array, 0) == 7 );
        BOOST_TEST ( mdArray::getDimensionSize (&array, 1) == 3 );

        mdArray::free (&array);
        delete[] coord.coordinates;
    }
}

BOOST_AUTO_TEST_CASE(allocationThreeDimension)
{
    {
        mdArray::Coordinates coord = {3, new size_t[3]};
        coord.coordinates[0] = 8;
        coord.coordinates[1] = 4;
        coord.coordinates[2] = 7;
        mdArray::Array array;

        mdArray::init (&array, &coord);

        BOOST_TEST ( mdArray::getDimensionNumber (&array) == 3 );

        BOOST_TEST ( mdArray::getDimensionSize (&array, 0) == 8 );
        BOOST_TEST ( mdArray::getDimensionSize (&array, 1) == 4 );
        BOOST_TEST ( mdArray::getDimensionSize (&array, 2) == 7 );

        mdArray::free (&array);
        delete[] coord.coordinates;
    }
}

BOOST_AUTO_TEST_CASE(ioOneDimension)
{
    {
        mdArray::Coordinates coord = {1, new size_t[1]};
        constexpr std::size_t sizeX = 3;
        coord.coordinates[0] = sizeX;
        mdArray::Array array;

        mdArray::init (&array, &coord);

        bool values[sizeX] = {true, false, false};

        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord.coordinates[0] = i;
            mdArray::write (&array, &coord, values[i]);
        }
        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord.coordinates[0] = i;
            BOOST_TEST ( mdArray::read (&array, &coord) == values[i] );
        }

        mdArray::free (&array);
        delete[] coord.coordinates;

    }
}

BOOST_AUTO_TEST_CASE(ioTwoDimension)
{
    {
        mdArray::Coordinates coord = {2, new size_t[2]};
        constexpr std::size_t sizeX = 3;
        constexpr std::size_t sizeY = 2;
        coord.coordinates[0] = sizeX;
        coord.coordinates[1] = sizeY;
        mdArray::Array array;

        mdArray::init (&array, &coord);

        bool values[sizeY][sizeX] = {{true, false, false},{false, true, true}};

        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord.coordinates[0] = i;
            for (std::size_t j = 0; j < sizeY; j++)
            {
                coord.coordinates[1] = j;
                mdArray::write (&array, &coord, values[j][i]);
            }
        }
        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord.coordinates[0] = i;
            for (std::size_t j = 0; j < sizeY; j++)
            {
                coord.coordinates[1] = j;
                BOOST_TEST ( mdArray::read (&array, &coord) == values[j][i] );
            }
        }

        mdArray::free (&array);
        delete[] coord.coordinates;

    }
}

BOOST_AUTO_TEST_CASE(ioThreeDimension)
{
    {
        mdArray::Coordinates coord = {3, new size_t[3]};
        constexpr std::size_t sizeX = 3;
        constexpr std::size_t sizeY = 2;
        constexpr std::size_t sizeZ = 4;
        coord.coordinates[0] = sizeX;
        coord.coordinates[1] = sizeY;
        coord.coordinates[2] = sizeZ;
        mdArray::Array array;

        mdArray::init (&array, &coord);

        bool values[sizeZ][sizeY][sizeX] = {{{true, false, false}, {false, true, true}},
                                            {{false, false, false},{false, true, true}},
                                            {{true, true, false},  {false, true, true}},
                                            {{true, false, true}  ,{false, true, true}}};

        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord.coordinates[0] = i;
            for (std::size_t j = 0; j < sizeY; j++)
            {
                coord.coordinates[1] = j;
                for (std::size_t k = 0; k < sizeZ; k++)
                {
                    coord.coordinates[2] = k;
                    mdArray::write (&array, &coord, values[k][j][i]);
                }
            }
        }
        for (std::size_t i = 0; i < sizeX; i++)
        {
            coord.coordinates[0] = i;
            for (std::size_t j = 0; j < sizeY; j++)
            {
                coord.coordinates[1] = j;
                for (std::size_t k = 0; k < sizeZ; k++)
                {
                    coord.coordinates[2] = k;
                    BOOST_TEST ( mdArray::read (&array, &coord) == values[k][j][i] );
                }
            }
        }

        mdArray::free (&array);
        delete[] coord.coordinates;

    }
}
