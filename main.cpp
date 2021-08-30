#include "TestMap.pb.h"
#include <google/protobuf/util/json_util.h>
#include "TestMapBuilder.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <thread>
#include <cstring>

using namespace std;
using namespace google::protobuf::util;


int main()
{
    cout << "main started" << endl;
//    auto test = test::TestMap::default_instance();
//    auto& testmap = *test.mutable_map1();
//    string key = "testkey";
//    string val = "testvalue";
//    testmap[key] = val;
//    cout << "test.map1_size: " << test.map1_size() << endl;
//    cout << "testmap[key]: " << testmap[key] << endl;
    unordered_map<string,string> eventMap;
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
    TestMapBuilder builder;

    //Create message from map data
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

    //Create map from message data
    unordered_map<string,string> testMap = builder.createMapFromMessage(testMessage);
    unordered_map<string,string>::iterator iter;
    for (iter = testMap.begin(); iter != testMap.end(); ++iter)
    {
        cout << "testMap key:" << iter->first << " value: " << iter->second << endl;
    }
}