#include "Blockchain.h"

/* tart off with the signature for the blockchain constructor we specified
 in Blockchain.h. As a blocks are added to the blockchain they need to
 reference the previous block using its hash, but as the blockchain must
 start somewhere we have to create a block for the next block to reference,
 we call this a genesis block. A genesis block is created and placed onto
 the _vChain vector. We then set the _nDifficulty level depending on how
 hard we want to make the PoW process.*/
Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 6;
}

/* The AddBlock method is called to add a new block to the blockchain.
we get using _GetLastBlock and its GetHash method. The block is then
mined using the MineBlock method followed by the block being added
to the _vChain vector (line 4), thus completing the process of adding
a block to the blockchain. */
void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

// The GetLastBlock method is used to return the last block in the blockchain.
Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
