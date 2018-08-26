Server Side
The server is constantly waiting to receive connections from new customers. The port number it listens to will be defined in a settings file.
The server must serve all the clients who connect to it simultaneously. After a client logs on to the server, he can send him requests.
The server will maintain a list of all games managed by it. A player can start a new game, or join an existing game by selecting a game from the list.
When the server receives a request from a client it gets it in the form of text.
The server checks with the map how to handle the request using the Command layout.
You must also allow the server to be stopped in an orderly way through the command line, using the exit command.
This command will send a message to all connected clients that the server is about to close, and all the sockets will be neatly closed.
