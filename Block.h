#ifndef My_BLOCKCHAIN_H
#define MY_BLOCKCHAIN_H

#include <cstdint>
#include <iostream>

//All the files in the C++ standard library declare all
//of its entities within the std namespace
using namespace std;

//calling the class Block
class Block {

//public modifier and public variables
public:
    string sPrevHash;

    Block(uint32_t nIndexIn, const string &sDataIn);

    string GetHash();

    void MineBlock(uint32_t nDifficulty);

//pivate modifier and private variables
private:
    uint32_t _nIndex; //index of the block
    int64_t _nNonce; //nonce of the block
    string _sData; //data of the block
    string _sHash; //hash of the block
    time_t _tTime; //time of the block

    string _CalculateHash() const;
    // _CalculateHash also has the const keyword, this is
    // to ensure the method cannot change any of the variables in the block
    // class which is very useful when dealing with a blockchain.
};
#endif
