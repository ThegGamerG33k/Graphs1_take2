#include <gtest/gtest.h>
#include <graph1.h>

class GraphTests : public ::testing::Test
{
protected:
	ssuds::Graph<std::string, float> g;
};