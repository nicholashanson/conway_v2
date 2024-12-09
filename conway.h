#include <mdspan-stable/include/mdspan/mdspan.hpp>
#include <array>
#include <optional>

namespace conway {
    using md6x6 = Kokkos::mdspan<std::optional<bool>, Kokkos::extents<size_t, 6, 6>>;
    using a36 = std::array<std::optional<bool>, 36>;

    a36 block =
    {
        std::nullopt, 0, 0, 0, 0, std::nullopt,
                   0, 0, 0, 0, 0, 0,
                   0, 0, 1, 1, 0, 0,
                   0, 0, 1, 1, 0, 0,
                   0, 0, 0, 0, 0, 0,
        std::nullopt, 0, 0, 0, 0, std::nullopt
    };

    class board {
        public:
            board( a36 block ) :
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
            md6x6 board_;
    };

    auto evolve( board bd ) {
        return;
    }
}
