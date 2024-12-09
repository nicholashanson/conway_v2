#ifndef CONWAY_H
#define CONWAY_H

#include <mdspan-stable/include/mdspan/mdspan.hpp>
#include <array>
#include <optional>
#include <iostream>

namespace conway {
    using md5x5 = Kokkos::mdspan<std::optional<bool>, Kokkos::extents<size_t, 5, 5>>;
    using md6x6 = Kokkos::mdspan<std::optional<bool>, Kokkos::extents<size_t, 6, 6>>;
    using md7x8 = Kokkos::mdspan<std::optional<bool>, Kokkos::extents<size_t, 7, 8>>;
    using a25 = std::array<std::optional<bool>, 25>;
    using a36 = std::array<std::optional<bool>, 36>;
    using a56 = std::array<std::optional<bool>, 56>;

    extern a25 rule_one_0_before;
    extern a25 rule_one_0_after;
    extern a36 block;
    extern a56 beehive;

    template<typename array, typename mdspan>
    class board {
        public:
            board( array block ) :
                board_( block.data() ) {
                    std::cout << "constructor called" << std::endl;
                }
            bool operator==( const board& rhs ) {
                for ( size_t i = 0; i < board_.static_extent( 0 ); i++ )
                    for ( size_t j = 0; j < board_.static_extent( 1 ); j ++ )
                        if ( board_[ i, j ] != rhs.board_[ i, j ] )
                            return false;
                return true;
            }

            friend auto evolve<array, mdspan>( board<array, mdspan>& bd );
        private:
            mdspan board_;

    };

    template<typename array, typename mdspan>
    auto evolve( board<array, mdspan>& bd ) {
        // loop through cells, excluding edge cells
        for ( size_t i = 1; i < bd.board_.static_extent( 0 ) - 1; i++ )
            for ( size_t j = 1; j < bd.board_.static_extent( 1 ) - 1; j++ ) {
                unsigned live_neighbor_count{};

                // loop through neighboring cells
                for ( int k = -1; k <= 1; k++ )
                    for ( int l = -1; l <= 1; l++ )
                        // skip over this cell
                        if ( k == l == 0 )
                            continue;
                        // if neighboring cell is live, increment live neighbor count
                        else if ( bd.board_[ i + k, j + l].value_or( false ) )
                            live_neighbor_count++;

                // this cell is live
                if ( bd.board_[ i, j ].value() == 1 )
                    // apply rule three
                    if ( live_neighbor_count != 2 && live_neighbor_count != 3  )
                        bd.board_[ i, j ] = 0;
                else // this cell is dead
                    // apply rule four
                    if ( live_neighbor_count == 3 )
                        bd.board_[ i, j ] = 1;
            }
    }
}

#endif
