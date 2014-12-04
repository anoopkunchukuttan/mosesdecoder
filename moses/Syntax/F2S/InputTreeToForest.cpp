#include "InputTreeToForest.h"

#include <boost/unordered_map.hpp>

namespace Moses
{
namespace Syntax
{
namespace F2S
{

void InputTreeToForest(const T2S::InputTree &tree, InputForest &forest)
{
  using T2S::InputTree;

  forest.vertices.clear();
  forest.vertices.reserve(tree.nodes.size());

  // Map from tree vertices to forest vertices.
  boost::unordered_map<const InputTree::Node*, InputForest::Vertex*> vertexMap;

  // Create forest vertices (but not hyperedges) and fill in vertexMap.
  for (std::vector<InputTree::Node>::const_iterator p = tree.nodes.begin();
       p != tree.nodes.end(); ++p) {
    const InputTree::Node &treeVertex = *p;
    forest.vertices.push_back(InputForest::Vertex(p->pvertex));
    InputForest::Vertex &forestVertex = forest.vertices.back();
    vertexMap[&treeVertex] = &forestVertex;
  }

  // Create the forest hyperedges.
  for (std::size_t i = 0; i < tree.nodes.size(); ++i) {
    const InputTree::Node &treeVertex = tree.nodes[i];
    const std::vector<InputTree::Node*> &treeChildren = treeVertex.children;
    if (treeChildren.empty()) {
      continue;
    }
    InputForest::Vertex &forestVertex = forest.vertices[i];
    InputForest::Hyperedge e;
    e.head = &forestVertex;
    e.tail.reserve(treeChildren.size());
    for (std::vector<InputTree::Node*>::const_iterator p = treeChildren.begin();
         p != treeChildren.end(); ++p) {
      e.tail.push_back(vertexMap[*p]);
    }
    forestVertex.incoming.push_back(e);
  }
}

}  // F2S
}  // Syntax
}  // Moses
