
#include "Server.h"
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
    //  getCommand("start<name>");
    //template <typename T>;
    //std::map<int, T> commandMap;
    int port;
    ifstream filePort;//("../configurationFile.txt");
    filePort.open("configurationFile.txt");
    if(filePort==NULL)
        cout<<"The file is empty.";
    filePort>>port;
    Server server(port);
    try{
        server.run();
    }catch(const char* msg) {
        cout << "Cannot start server. Reason: "<<msg<< endl;
        exit(-1);
    }
}