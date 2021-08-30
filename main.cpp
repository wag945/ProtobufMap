#include "TestMap.pb.h"
#include <google/protobuf/util/json_util.h>
#include "TestMapBuilder.h"
#include <iostream>

using namespace std;
using namespace google::protobuf::util;

void createEventData(unordered_map<string,string> &eventMap)
{
    eventMap["EventName"]="TestEvent";
    eventMap["NumTracks"]="2";
    eventMap["Ctsl1"]="1";
    eventMap["Id1"]="Friend";
    eventMap["Category1"]="Surface";
    eventMap["Latitude1"]="37.00";
    eventMap["Longitude1"]="-75.0";
    eventMap["Ctsl2"]="2";
    eventMap["Id2"]="Unknown";
    eventMap["Category2"]="Air";
    eventMap["Latitude2"]="37.50";
    eventMap["Longitude2"]="-74.0";
}

test::TestMap createMessageFromMapData(unordered_map<string,string> &eventMap)
{
    TestMapBuilder builder;
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("EventName",pair.first.c_str()))
        {
            if (!strcmp(eventMap["EventName"].c_str(),pair.second.c_str()))
            {
                cout << "EventName matches"  << endl;
            }
        }    
    }
    return testMessage;
}

void createMapFromMessageData(test::TestMap testMessage)
{
    TestMapBuilder builder;
    unordered_map<string,string> testMap = builder.createMapFromMessage(testMessage);
    unordered_map<string,string>::iterator iter;
    for (iter = testMap.begin(); iter != testMap.end(); ++iter)
    {
        cout << "testMap key:" << iter->first << " value: " << iter->second << endl;
    }
}

int main()
{
    cout << "main started" << endl;

    unordered_map<string,string> eventMap;

    createEventData(eventMap);

    //Create message from map data
    auto testMessage = createMessageFromMapData(eventMap);

    //Create map from message data
    createMapFromMessageData(testMessage);
}