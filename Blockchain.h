#ifndef MY_BLOCKCHAIN_H
#define MY_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

// calling our blockchain class Blockchain
class Blockchain {
// public modifier and public variables
public:
    Blockchain();

    void AddBlock(Block bNew);

// private modifier and private variables
private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
    // _GetLastBlock which is also followed by the
    // const keyword to denote that the output of the method
    // cannot be changed.
};

#endif
