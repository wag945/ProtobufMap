#include <iostream>
#include <vector>
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

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class myTestFixture1: public ::testing::Test { 
public: 
   myTestFixture1( ) { 
       // initialization code here
   } 

   void SetUp( ) { 
       // code here will execute just before the test ensues 
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

   void TearDown( ) { 
       // code here will be called just after the test completes
       // ok to through exceptions from here if need be
   }

   ~myTestFixture1( )  { 
       // cleanup any pending stuff, but no exceptions allowed
   }

    std::unordered_map<string,string> eventMap;
    TestMapBuilder builder;
   // put in any custom data members that you need 
};

TEST_F(myTestFixture1, EventNameMatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("EventName",pair.first.c_str()))
        {
            if (!strcmp(eventMap["EventName"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, NumTracksMatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("NumTracks",pair.first.c_str()))
        {
            if (!strcmp(eventMap["NumTracks"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Ctsl1MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Ctsl1",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Ctsl1"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Ctsl2MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Ctsl2",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Ctsl2"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Id1MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Id1",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Id1"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Id2MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Id2",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Id2"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Category1MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Category1",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Category1"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Category2MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Category2",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Category2"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Latitude1MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Latitude1",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Latitude1"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Latitude2MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Latitude2",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Latitude2"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Longitude1MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Longitude1",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Longitude1"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

TEST_F(myTestFixture1, Longitude2MatchesTest)
{
    auto testMessage = builder.createMessageFromMap(eventMap);
    cout << "testMessage size: " << testMessage.map1_size() << endl;
    auto messageMap = testMessage.mutable_map1();
    bool fieldMatches = false;
    for (auto & pair : *messageMap)
    {
        cout << "Key:" << pair.first << " Value: " << pair.second << endl;
        if (!strcmp("Longitude2",pair.first.c_str()))
        {
            if (!strcmp(eventMap["Longitude2"].c_str(),pair.second.c_str()))
            {
                fieldMatches = true;
            }
        }
    }
    EXPECT_EQ(true,fieldMatches);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}