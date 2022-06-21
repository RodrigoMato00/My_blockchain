#include "Block.h"
#include "sha256.h" // include the SHA256 hashing technique to create hashes of our blocks
#include <sstream>

/* The constructor starts off by repeating the signature we specified in
the Block.h header file but we also add code to copy the contents
of the parameters into the the variables _nIndex, and _sData */
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr); // set to the current time
}

/* specify the signature for GetHash
 and then add a return for the private variable _sHash */
string Block::GetHash() {
    return _sHash;
}

/* start with the signature for the MineBlock method, which we specified
in the Block.h header file (line 1), and create an array of characters with
a length one greater that the value specified for nDifficulty */
void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];

    // fill the array with zeros, followed by the final array item
    // being given the string terminator character (\0)
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    // c-string is turned into a standard string
    string str(cstr);


    /*  increment the _nNonce and _sHash is assigned with the output of
     _CalculateHash, the front portion of the hash is then compared the
     string of zeros we’ve just created; if no match is found the loop is
     repeated until a match is found. Once a match is found a message is
     sent to the output buffer to say that the block has been successfully mined */
    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;
}

/* the _CalculateHash method, which we specified in the Block.h header
file, but we include the inline keyword which makes the code more
efficient as the compiler places the method’s instructions inline
wherever the method is called; this cuts down on separate method calls.
A string stream is then created (line 2), followed by appending the values
for _nIndex, _tTime, _sData, _nNonce, and sPrevHash to the stream */
inline string Block::_CalculateHash() const {
    std::stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    // returning the output of the sha256 method,
    // using the string output from the string stream
    return sha256(ss.str());
}
