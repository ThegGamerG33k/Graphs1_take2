#include <gtest/gtest.h>
#include <graph1.h>
#include <string>

class GraphTests : public ::testing::Test
{
protected:
	ssuds::Graph<std::string, float> g;
	ssuds::Graph<std::string, float> iterate;
	
	void SetUp() override
	{
		g.add_node("n1");
		g.add_node("n2");
		g.add_node("n3");
		g.add_edge("n1", "n3", .6f);
	}

	void TearDown() override
	{
		
	}
};


TEST_F(GraphTests, BasicFunction)
{
	EXPECT_TRUE(g.contains_node("n1")); 
	EXPECT_FALSE(g.contains_node("n5")); 

	EXPECT_TRUE(g.contains_edge("n1", "n3")); 
	EXPECT_FALSE(g.contains_edge("n1", "n2")); 
	EXPECT_NO_THROW(g.add_edge("n1", "n2", .2f));
	EXPECT_TRUE(g.contains_edge("n1", "n2"));

	EXPECT_NO_THROW(g.add_node("n4"));
	EXPECT_TRUE(g.contains_node("n4"));
	EXPECT_TRUE(g.remove_node("n4"));
	EXPECT_FALSE(g.contains_node("n4"));

	EXPECT_TRUE(g.remove_edge("n1", "n2"));
	EXPECT_FALSE(g.contains_edge("n1", "n2"));

	EXPECT_EQ(g.get_edge("n1", "n3"), 0.6f);
	EXPECT_THROW(g.get_edge("n1", "n2"), std::out_of_range);
	EXPECT_THROW(g.get_edge("n4", "n1"), std::out_of_range);

	EXPECT_EQ(g.get_neighbor_iterator("n1"), "n3");
}