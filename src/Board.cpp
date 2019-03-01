#include <cassert>
#include <Board.hpp>

// Board::Board(int w, int h, int d)
//     :  mWidth{w}, mHeigth{h}, mDepth{d} {
        
//         m
//}

unsigned Board::Get(int x, int y, int z) {
    assert(x >= 0 && y >= 0 && z >= 0);
    return mBlocks[GetIndex(x, y, z)];
}

unsigned Board::Set(int x, int y, int z, unsigned u) {
    assert(x >= 0 && y >= 0 && z >= 0);
    return mBlocks[GetIndex(x, y, z)] = u;
}
