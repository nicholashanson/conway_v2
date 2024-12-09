#include <boost/test/unit_test.hpp>
#include "conway.h"

/*
    Rule one: Any live cell with fewer than two live neighbors dies,
    as if by underpopulation.
*/
BOOST_AUTO_TEST_CASE( RuleOneTest )
{
    conway::board<conway::a25, conway::md5x5> bd( conway::rule_one_0_before );
    conway::evolve( bd );
    BOOST_CHECK( ( bd == conway::board<conway::a25, conway::md5x5>( conway::rule_one_0_after ) ) );
}
