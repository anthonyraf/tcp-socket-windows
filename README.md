## Using sockets in c++ on windows
The server send "Hello World" to the client

## Compilation

    $ g++ -o server.exe server.cpp -lws2_32
    $ g++ -o client.exe client.cpp -lws2_32
> Note: `-lws2_32` is obligatory

## Run

    $ server.exe
    $ client.exe
