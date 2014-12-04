#pragma once

#include <set>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>

#include "moses/Syntax/KBestExtractor.h"
#include "moses/Syntax/SVertexStack.h"
#include "moses/Syntax/T2S/PVertexToStackMap.h"
#include "moses/TreeInput.h"
#include "moses/Word.h"

#include "HyperTree.h"
#include "InputForest.h"

namespace Moses
{
namespace Syntax
{

struct PVertex;
class SDerivation;
struct SHyperedge;

namespace F2S
{

template<typename RuleMatcher>
class Manager
{
 public:
  Manager(const TreeInput &);

  void Decode();

  // Get the SHyperedge for the 1-best derivation.
  const SHyperedge *GetBestSHyperedge() const;

  void ExtractKBest(
      std::size_t k,
      std::vector<boost::shared_ptr<KBestExtractor::Derivation> > &kBestList,
      bool onlyDistinct=false) const;

  const std::set<Word> &GetUnknownWords() const { return m_oovs; }

 private:
  void InitializeRuleMatchers();

  void InitializeStacks();

  void RecombineAndSort(const std::vector<SHyperedge*> &, SVertexStack &);

  const TreeInput &m_source;
  InputForest m_inputForest;
  T2S::PVertexToStackMap m_stackMap;
  std::set<Word> m_oovs;
  boost::shared_ptr<HyperTree> m_glueRuleTrie;
  std::vector<boost::shared_ptr<RuleMatcher> > m_mainRuleMatchers;
  boost::shared_ptr<RuleMatcher> m_glueRuleMatcher;
};

}  // F2S
}  // Syntax
}  // Moses

// Implementation
#include "Manager-inl.h"
