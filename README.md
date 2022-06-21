# Blockchain Basic
***

This is a simple test app I made to learn more about the blockchain algorithm and the peer-to-peer network structure.

Although it isn't perfect, it correctly implements a simple blockchain. Each block in the
blockchain contains exactly 256 bytes of data, regardless of what it may be (since the app
only really works from the commandline, most data is going to be human-readable strings, but anyway).

The hash algorithm used is SHA-256

## Building

1- Clone the Repository
2- Compile the app:
    - g++ -o basic_blockchain *.cpp
3- Run the app:
    - ./basic_blockchain
4- Enjoy!

Example:

```
~/ git clone https://github.com/RodrigoMato00/My_blockchain.git
........
~/ cd My_blockchain
~/ g++ -o basic_blockchain *.cpp
~/ ./basic_blockchain
~/ Mining block 1...
Block mined: 00000031882d579d7ed4fa8f761c62d24bcae6dfa7237218f11cbce22faed369
~/ Mining block 2...
Block mined: 000000448e6eb4b0584f4b8d961c40e75deafae0706acf5cf7a61a792fe0e1dd
~/ Mining block 3...
Block mined: 00000028c04df85e5ebfda01b4efdc9543d23ebcd5a6a6a8865e5c053287a6e2
```
