#include "Graph.h"


namespace algorithms_on_graphs
{
	Vertex::Vertex(vector<int> vertices) : adjacent_vertices(vertices)
	{

	}

	Vertex::~Vertex()
	{
		adjacent_vertices.clear();
	}

	vector<int> Vertex::adjacent()
	{
		return adjacent_vertices;
	}


	Graph::Graph()
	{

	}

	Graph::Graph(vector<vector<int> > vertices)
	{
		this->vertices.clear();
		for (int i = 0; i < int(vertices.size()); ++i)
		{
			this->vertices.push_back(Vertex(vertices[i]));
		}
	}

	Graph::Graph(vector<vector<int> > vertices, bool direct) : Graph(vertices)
	{
		this->direct = direct;
	}

	
	Graph::~Graph()
	{
		vertices.clear();
	}


	bool Graph::is_direct()
	{
		return direct;
	}

	int Graph::get_size()
	{
		return int(vertices.size());
	}

	Vertex Graph::at(int index)
	{
		index = std::max(index, 0);
		index = std::min(index, get_size() - 1);

		return vertices[index];
	}
}