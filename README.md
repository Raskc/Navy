# Navy ⛴️

This project is a remake of the famous game __Navy__.\
Both players decide of where there ships are located on a board (in a .txt file).\
Then both of them spar by deciding one after another where they are going to attack until one of them eventually destroy all of the ennemies ship.

## Installation

Just __clone__ the repo then use __Make__ to compile the game and finally launch the binary with _./navy_.
To get information about the game use the :

```bash
./navy -h
```

## How does it work ?

The game work by using __Sigaction__ to send data between the two program.

The __Data__ is made of __8 characters__ in binary (1 byte).
Each Byte value are stored in an array to let the program understand which bytes is equal to which character.\
Some others values like the "Missed" or "Hitted" ones are stored in a .h . 👨🏽‍💻



## Credits
* Edgar Dion 🐈
* Alessandro Tano 🥱
