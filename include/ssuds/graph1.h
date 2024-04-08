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

		/// <summary>
		/// A function that adds a new node to the Graph
		/// </summary>
		/// <param name="nval"></param>
		void add_node(const N& nval)
		{
			mData[nval];		// Makes the (initially empty) map of neighbors
			//  from this node nval.
		}

		/// <summary>
		/// A function that moves to the location of a given node and creates a new edge connection to another existing node as 
		/// that is provided
		/// </summary>
		/// <param name="start_nval"></param>
		/// <param name="dest_nval"></param>
		/// <param name="eval"></param>
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


		/// <summary>
		/// a function that searches throw the Graph for a node that matches the given node value provided
		/// </summary>
		/// <param name="nval"></param>
		/// <returns>returns true if the node is found, otherwise it returns false</returns>
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
		/// <summary>
		/// A function that looks through the Graph for the given node and then finds a given edge that is connected to that node
		/// </summary>
		/// <param name="start_nval"></param>
		/// <param name="dest_nval"></param>
		/// <returns>returns true if the edge is found inside the given node, otherwise it returns false if it doesn't find the edge
		/// in the given node. If it can't find the node with a matching starting value it also returns false</returns>
		bool contains_edge(const N& start_nval, const N& dest_nval)
		{
			//find the node for the given starting value and check to see if is in the graph
			UnorderedMap<N, UnorderedMap<N, E>>::UnorderedMapIterator it = mData.find(start_val);
			if (it != mData.end())
			{
				//look to see if there is a connection between the starting node and the given dest_node, if there is return 
				//true, if there isn's return false as there is not edge connecting the nodes
				UnorderedMap<N,E>::UnorderedMapIterator it2 = (*it).second.find(dest_nval);
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

		/// <summary>
		/// a function that searches throw the Graph for a node that matches the given node value provided and removes it 
		/// from the Graph
		/// </summary>
		/// <param name="start_nval"></param>
		/// <returns>true if it finds the node given and false if it does not</returns>
		bool remove_node(const N& start_nval)
		{
			UnorderedMap<N, UnorderedMap<N, E>>::UnorderedMapIterator it = mData.find(start_nval);
			if (it != mData.end())
			{
				mData.remove((*it).first);
				return true;
			}
			else
			{
				return false;
			}
		}

		/// <summary>
		/// A function that looks through the Graph for the given node and then finds a given edge that is connected to that node and removes it
		/// </summary>
		/// <param name="start_nval"></param>
		/// <param name="dest_nval"></param>
		/// <returns>returns true if the provided edge is found and removed, returns false if the edge is not found. If the starting node is not
		/// found it also returns false</returns>
		bool remove_edge(const N& start_nval, const N& dest_nval)
		{
			UnorderedMap<N, UnorderedMap<N, E>>::UnorderedMapIterator it = mData.find(start_nval);
			if (it != mData.end())
			{
				UnorderedMap<N, E>::UnorderedMapIterator it2 = (*it).second.find(dest_nval);
				if (it2 != mData.end())
				{
					(*it).second.remove(dest_nval);
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}

		/// <summary>
		/// A function that returns all edges of a given node that match the given node destination
		/// </summary>
		/// <param name="start_nval"></param>
		/// <param name="dest_nval"></param>
		/// <returns>returns all nodes with matching destination values if they are found, otherwise it
		/// throws an error saying the edge value was invalid. If the given starting node isn't found it
		/// will throw an error saying the given node value is invalid</returns>
		const E& get_edge(const N& start_nval, const N& dest_nval)
		{
			UnorderedMap<N, UnorderedMap<N, E>>::UnorderedMapIterator it = mData.find(start_nval);
			if (it != mData.end())
			{
				UnorderedMap<N, E>::UnorderedMapIterator it2 = (*it).second.find(dest_nval);
				if (it2 != mData.end())
				{
					const E& edge = (*it2);
					return edge;
				}
				else
				{
					throw std::out_of_range("Invalid edge value.");
				}
			}
			else
			{
				throw std::out_of_range("Invalid node value.");
			}
		}

		/// <summary>
		/// Function that finds all neighbors of a given node
		/// </summary>
		/// <param name="nval"></param>
		/// <returns>returns all connected nodes to the given node</returns>
		typename ssuds::UnorderedMap<N, E>::UnorderedMapIterator get_neighbor_iterator(const N& nval)
		{
			auto it = mData.find(nval);
		}
		
		/// <summary>
		/// operator override for output that restructures it to output N | (N1, E1)
		/// where N is the current node, N1 is a node connected to N, and E1 is the edge
		/// value that is between N and N1
		/// </summary>
		/// <param name="os"></param>
		/// <param name="G"></param>
		/// <returns>A output formatted like: N | (N1, E1)</returns>
		friend std::ostream operator<< (std::ostream& os, const Graph& G)
		{
			UnorderedMap<N, UnorderedMap<N, E>>::UnorderedMapIterator it = G.mData.begin());
			while (it != G.mData.end())
			{
				os << (*it).first << " | "
				UnorderedMap<N, E>::UnorderedMapIterator it2 = (*it).second.begin();
				while (it2 != G.mData.end())
				{
					os << "(" << (*it2).first << ": " << (*it).second << ")" ;
					++it2;
				}
				os << std::endl;
				++it;
			}

		}
	};
}