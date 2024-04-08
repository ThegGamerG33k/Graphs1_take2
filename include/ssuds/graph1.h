#include <unordered_map.h>
#include <ostream>

namespace ssuds
{
	template <class N, class E>
	class Graph
	{
	protected:
		UnorderedMap<N, UnorderedMap<N, E>> mData;

	public:
		void add_node(const N& nval)
		{
			mData[nval];		// Makes the (initially empty) map of neighbors
			//  from this node nval.
		}

		void add_edge(const N& start_nval, const N& dest_nval, const E& eval)
		{
			// Do we want to raise an exception if the nodes don't exist?
			UnorderedMap<N, UnorderedMap<N, E>>::UnorderedMapIterator it = mData.find(start_val);
			if (it != mData.end())
			{
				// We do have the node start_val in our map
				it = mData.find(dest_nval)
					if (it != mData.end()
					{
						// We do have the dest_nval -- make an edge
						mData[start_nval][dest_nval] = eval;
							return;
					}
			}

			throw std::out_of_range("Invalid start or dest node");
		}

		bool contains_node(const N& nval)
		{
			//find the node for the given starting value and check to see if is in the graph, if there is return 
			//true, if there isn's return false as there is not edge connecting the nodes
			UnorderedMap<N, UnorderedMap<N, E>>::UnorderedMapIterator it = mData.find(start_val);
			if (it != mData.end())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		bool contains_edge(const N& start_nval, const N& dest_nval)
		{
			//find the node for the given starting value and check to see if is in the graph
			UnorderedMap<N, UnorderedMap<N, E>>::UnorderedMapIterator it = mData.find(start_val);
			if (it != mData.end())
			{
				//look to see if there is a connection between the starting node and the given dest_node, if there is return 
				//true, if there isn's return false as there is not edge connecting the nodes
				UnorderedMap<N,E>::UnorderedMapIterator it2 = (*it).second().find(dest_nval);
				if (it2 != end)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				//invalid start_nval
				return false;
			}
		}
		
		ostream operator<< ()
	};
}