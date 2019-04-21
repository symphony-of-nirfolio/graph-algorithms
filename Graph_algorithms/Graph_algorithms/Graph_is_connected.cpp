#include "Graph_is_connected.h"


namespace algorithms_on_graphs
{
	bool Graph_is_connected::dfs(vector<bool> &visit, Graph &graph, int vertex, bool need_to_stop)
	{
		visit[vertex] = true;

		//GraphAPI part
		if (need_to_stop)
		{
			//GraphAPI::instance.mark_vertex(vertex);
			//waiting_for_the_next_move();
		}
		//

		for (int i = 0; i < int(graph.at(vertex).adjacent().size()); ++i)
		{
			int new_vertex = graph.at(vertex).adjacent()[i];

			if (visit[new_vertex] == false)
			{
				dfs(visit, graph, new_vertex, need_to_stop);
			}
		}

		return true;
	}


	void Graph_is_connected::work(Graph graph, bool need_to_stop)
	{
		vector<bool> visit(graph.get_size(), false);

		dfs(visit, graph, 0, need_to_stop);

		for (int i = 0; i < graph.get_size(); ++i)
		{
			if (visit[i] == false)
			{
				//GraphAPI part
				if (need_to_stop)
				{
					//GraphAPI::instance.result(false);
					//GraphAPI::instance.end_of_the_algorithm();
				}
				//

				return;
			}
		}

		//GraphAPI part
		if (need_to_stop)
		{
			//GraphAPI::instance.result(true);
			//GraphAPI::instance.end_of_the_algorithm();
		}
		//
	}

}