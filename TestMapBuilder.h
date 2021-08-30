#ifndef TestMapBuilder_h
#define TestMapBuilder_h

#include "TestMap.pb.h"
#include <unordered_map>

class TestMapBuilder
{
    public:
    TestMapBuilder()=default;
    ~TestMapBuilder()=default;
    test::TestMap createMessageFromMap(std::unordered_map<std::string, std::string>&);
    std::unordered_map<std::string,std::string> createMapFromMessage(test::TestMap);
};
#endif