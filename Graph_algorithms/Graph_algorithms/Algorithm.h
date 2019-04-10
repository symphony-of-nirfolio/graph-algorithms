#pragma once


#include "GraphAPI.h"
#include "Graph.h"


namespace algorithms_on_graphs
{
	class Algorithm
	{

	public:
		virtual bool work(Graph graph) = 0;
	};
}