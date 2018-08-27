Server Side
The server is constantly waiting to receive connections from new customers. The port number it is listening to is defined in a settings file. The server supports the management of a single network game at the same time, meaning that at most two players can be connected to the server at the same time.
Only after a pair of players finish playing, a new pair of players will be able to connect to the server.
After a player connects to the server, he can start sending his moves to him and receive the moves the opponent makes (serially).

The client-server communication protocol
When a player connects for the first time to the server, the server checks whether it is the first player to join the game or the second.
If he is the first player he will have to wait for the other player to connect
Call to the read () function on the socket, which waits until the server sends a message back.
When the other player connects, the server will send messages to both players with their numbers, which means that the first player will be sent the message "1" (which represents the color black) and the second player will be sent the message "2."
According to the number each player will receive, he will know what color he is playing (1 = black, 2 = white).
From that moment on, the game starts and the server waits for messages from both players with the moves that each player has chosen.
The server can assume that the moves they are going to are legitimate moves on the board. The messages of the moves will follow the order of the game - ie, the server will wait for the first player, then the second player, then the first player and then repeat.
Any announcement of a move from one of the players will be forwarded to the other player.
A move message will be sent in the format "Y, X," where Y and X describe the location of the slot where the player chose to put his disc. If the player has no possible move on the board, he will send a message to the server. "NoMove"
When the game ends, the player who made the last move on the board will send an "End" message to the server (the server has no way to tell for himself if the game is over or not.) In this case the server will close its sockets with both players and return to wait for a pair of players New.

Customer side description
At the beginning of the program, the user will be presented with a menu that will allow him to choose whether to play against a normal player or against a player or a remote player.
