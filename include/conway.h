#ifndef CONWAY_H
#define CONWAY_H

#include <mdspan-stable/include/mdspan/mdspan.hpp>
#include <array>
#include <optional>
#include <iostream>

namespace conway {
    using md6x6 = Kokkos::mdspan<std::optional<bool>, Kokkos::extents<size_t, 6, 6>>;
    using md7x8 = Kokkos::mdspan<std::optional<bool>, Kokkos::extents<size_t, 7, 8>>;
    using a36 = std::array<std::optional<bool>, 36>;
    using a56 = std::array<std::optional<bool>, 56>;

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
        private:
            mdspan board_;
    };

    template<typename array, typename mdspan>
    auto evolve( board<array, mdspan>& bd ) {
        return;
    }
}

#endif
