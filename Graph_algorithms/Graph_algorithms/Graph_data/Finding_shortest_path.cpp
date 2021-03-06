#include "Finding_shortest_path.h"


namespace algorithms_on_graphs
{
	void Finding_shortest_path::bfs(Graph &graph, queue<int> &next_verteces, vector<int> &direction, int finish, int stop_type, int &can_move_on)
	{
		while (!next_verteces.empty())
		{
			int vertex = next_verteces.front();
			next_verteces.pop();

			//GraphAPI part
			if (stop_type == 1)
			{
				GraphAPI::instance().set_highlighted(vertex);
				waiting_for_the_next_move();
				
				if (GraphAPI::instance().algorithm_is_ended())
				{
					return;
				}
			}
			else if (stop_type == -1)
			{
				waiting_for_the_next_move(can_move_on);
			}


			for (auto new_vertex : graph.at(vertex))
			{
				if (direction[new_vertex] == -1)
				{
					next_verteces.push(new_vertex);
					direction[new_vertex] = vertex;

					//GraphAPI part
					if (stop_type == 1)
					{
						GraphAPI::instance().set_used_mark(new_vertex);
						waiting_for_the_next_move();

						if (GraphAPI::instance().algorithm_is_ended())
						{
							return;
						}
					}
					else if (stop_type == -1)
					{
						waiting_for_the_next_move(can_move_on);
					}

					if (new_vertex == finish)
					{
						return;
					}
				}
			}

			//GraphAPI part
			if (stop_type == 1)
			{
				GraphAPI::instance().set_black_mark(vertex);
			}
		}
	}


	Graph Finding_shortest_path::create_route(Graph &graph, vector<int> &direction, int start, int finish)
	{
		vector<vector<int> > new_graph(graph.size());

		int index = finish;
		
		while (direction[index] != start)
		{
			new_graph[direction[index]].push_back(index);

			index = direction[index];
		}

		return Graph(new_graph, true);
	}


	void Finding_shortest_path::work(Graph graph, int start, int finish, int stop_type, int &can_move_on)
	{
		vector<int> direction(graph.size(), -1);

		queue<int> next_verteces;
		next_verteces.push(start);
		direction[start] = start;

		bfs(graph, next_verteces, direction, finish, stop_type, can_move_on);

		//GraphAPI part
		if (stop_type == 1)
		{
			if (GraphAPI::instance().algorithm_is_ended())
			{
				return;
			}
		}

		if (direction[finish] == -1)
		{
			//GraphAPI part
			if (stop_type == 1)
			{
				GraphAPI::instance().set_result("There is no way between the verteces");
				GraphAPI::instance().end_of_the_algorithm();
			}
		}
		else
		{
			//GraphAPI part
			if (stop_type == 1)
			{
				GraphAPI::instance().set_result("Route exist");
				GraphAPI::instance().end_of_the_algorithm();
			}
		}

		if (stop_type == -1)
		{
			can_move_on = -1;
		}
	}

}