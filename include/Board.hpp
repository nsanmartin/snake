#ifndef _BOARD_H
#define _BOARD_H

#include <vector>

class Board {
    unsigned mWidth, mHeigth, mDepth;
    std::vector<unsigned> mBlocks;
    inline size_t GetIndex(int x, int y, int z) {
        return x * mWidth + y * mHeigth + z;
    };
public:
    Board(unsigned w, unsigned h, unsigned d)
        :  mWidth{w}, mHeigth{h}, mDepth{d},
           mBlocks{w*h*d}
        {}

    unsigned Get(int x, int y, int z);
    unsigned Set(int x, int y, int z, unsigned u);    

};


#endif
