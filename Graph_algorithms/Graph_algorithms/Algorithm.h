#pragma once


#include "GraphAPI.h"
#include "Graph.h"


namespace algorithms_on_graphs
{
	class Algorithm
	{

	protected:
		void waiting_for_the_next_move();

	public:
		virtual bool work(Graph graph, bool need_to_stop) = 0;
	};
}