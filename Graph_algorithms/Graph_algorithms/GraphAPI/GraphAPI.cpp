#include "GraphAPI.h"
#include "../Graph_data/Read_graph.h"

#include <cmath>


GraphAPI::GraphAPI()
{
    can_move = false;
    algo_ended = false;
    current_highlighted = 0;
}

void GraphAPI::set_highlighted(unsigned vertex)
{
    current_highlighted = vertex;
}

void GraphAPI::set_black_mark(unsigned vertex)
{
    black_marked.push_back(vertex);
}

void GraphAPI::set_used_mark(unsigned vertex)
{
    use_marked.push_back(vertex);
}

unsigned GraphAPI::get_current_highlighted()
{
    current_highlighted = (current_highlighted + 1)%10;
    return current_highlighted;
}

vector<unsigned> GraphAPI::get_black_marked()
{
    vector<unsigned> res;
    for(auto i : black_marked)
    {
        res.push_back(i);
    }
    return {0,2};
    return res;
}

vector<unsigned> GraphAPI::get_used_marked()
{
    vector<unsigned> res;
    for(auto i : use_marked)
    {
        res.push_back(i);
    }
    return {0,1};
    return res;
}

void GraphAPI::set_result(std::string result)
{
    this->result = result;
}

void GraphAPI::end_of_the_algorithm()
{
    algo_ended = true;
}

bool GraphAPI::can_move_on()
{
    if(can_move)
    {
        can_move = false;
        return true;
    }
    else
    {
        return false;
    }

}

void GraphAPI::continue_algo()
{
    can_move = true;
}

vector<Point> GraphAPI::get_vertices_coordinates(std::string graph_file_name)
{
	algorithms_on_graphs::Graph graph = get_graph(graph_file_name);
    return build_dots::getAllDots(graph);
}

algorithms_on_graphs::Graph GraphAPI::get_graph(std::string graph_file_name)
{

    string file_name = "../Graph_data/Data/" + graph_file_name;

#ifdef QT_GRAPH_API
    file_name = "../Graph_algorithms/Graph_data/Data/" + graph_file_name;
#endif

	return algorithms_on_graphs::Read_graph::get_graph_from_file(file_name);
}






GraphAPI::~GraphAPI()
{

}
