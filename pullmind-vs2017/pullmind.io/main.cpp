#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_net.h"

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();
	IPaddress address;
	if (SDLNet_ResolveHost(&address, "127.0.0.1", 3333) == -1)
	{
		printf("Error %s\n", SDLNet_GetError());
		return 1;
	}
	TCPsocket socket = SDLNet_TCP_Open(&address);
	SDLNet_TCP_Send(socket, "hello", 5);
	char data[100] = "";
	SDLNet_TCP_Recv(socket, data, 10);
	printf("%s", data);
	SDLNet_TCP_Close(socket);
	return 0;
}