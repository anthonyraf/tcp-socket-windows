## Example of using sockets in c++ on windows
The server send "Hello World" to the client

## Compilation

    $ g++ -o serveur.exe serveur.cpp -lws2_32
    $ g++ -o client.exe client.cpp -lws2_32
> Note: `-lws2_32` is obligatory

## Run

    $ serveur.exe
    $ client.exe
