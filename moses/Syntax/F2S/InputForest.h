#pragma once

#include <vector>

#include "moses/Syntax/PVertex.h"

namespace Moses
{
namespace Syntax
{
namespace F2S
{

struct InputForest
{
 public:
  struct Vertex;

  struct Hyperedge {
    Vertex *head;
    std::vector<Vertex*> tail;
  };

  struct Vertex {
    Vertex(const PVertex &v) : pvertex(v) {}
    PVertex pvertex;
    std::vector<Hyperedge> incoming;
  };

  // Vertices in post-order.
  std::vector<Vertex> vertices;
};

}  // F2S
}  // Syntax
}  // Moses
