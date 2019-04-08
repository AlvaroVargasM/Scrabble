#define RAPIDJSON_HAS_STDSTRING 1




#include <iostream>
#include "Logic/Tile.h"
#include "Logic/GameBoard.h"
#include "Logic/LinkedList.h"
#include "Logic/Organizer.h"
#include "Logic/Searcher.h"
#include "Logic/Stack.h"
#include "UnitTest.h"
#include "Networking/Server.h"
#include "NetPackage.h"
#include "libraries/rapidjson/document.h"
#include "libraries/rapidjson/writer.h"
#include "libraries/rapidjson/stringbuffer.h"
#include <vector>
#include <sstream>


int main() {


    /*NetPackage* temp = new NetPackage();

    rapidjson::Document docu;

    docu.SetObject();

    rapidjson::Document::AllocatorType& allocator = docu.GetAllocator();

    rapidjson::Value object(rapidjson::kObjectType);
    object.AddMember("from", temp->getFrom(), allocator);
    object.AddMember("data", temp->getData(), allocator);
    docu.AddMember("Package", object, allocator);

    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    docu.Accept(writer);

    std::cout << strbuf.GetString() << std::endl;*/

    Server* server = new Server();









    return 0;
}

