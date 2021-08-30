#include "TestMapBuilder.h"
#include "TestMap.pb.h"
#include <iostream>

using namespace std;

test::TestMap TestMapBuilder::createMessageFromMap(unordered_map<string,string> &theMap)
{
    auto message = test::TestMap::default_instance();
    auto& testmap = *message.mutable_map1();
    
    unordered_map<string,string>::iterator iter;
    for (iter = theMap.begin(); iter != theMap.end(); ++iter)
    {
        cout << "createMessageFromMap key:" << iter->first << " value: " << iter->second << endl;
        testmap[iter->first]=iter->second;
    }

    return message;
}

unordered_map<string,string> TestMapBuilder::createMapFromMessage(test::TestMap message)
{
    unordered_map<string,string> eventMap;
    auto messageMap = message.mutable_map1();
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        eventMap[pair.first] = pair.second;
    }

    return eventMap;
}