#define TEST
#ifdef TEST
#define BOOST_TEST_MODULE TestSuite
#include <boost/test/included/unit_test.hpp>
#include "conway.h"

/*
    Still lifes
*/

BOOST_AUTO_TEST_CASE( BlockTest )
{
    conway::board bd( conway::block );
    conway::evolve( bd );
    BOOST_CHECK( bd == conway::board( conway::block ) );
}

#endif
