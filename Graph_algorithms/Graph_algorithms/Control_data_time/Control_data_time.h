#pragma once
#include "../Graph_data/Graph.h"
#include "../GraphAPI/GraphAPI.h"
#include <chrono>
#include <string>

namespace control_data_time
{
	string time_of_work(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph);
	string time_of_work(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph, int st, int fin);

	string RAM_usage(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph);
	string RAM_usage(GraphAPI::Algorithm current_algorithm, algorithms_on_graphs::Graph current_graph, int st, int fin);
}
