#ifndef CORE_HILLCLIMBSEARCH_H
#define CORE_HILLCLIMBSEARCH_H

#include <api/ISearchAlgorithm.h>
#include <api/EightPuzzleNode.h>
#include <deque>

namespace core {

class HillClimbSearch : public api::ISearchAlgorithm
{
public:
    HillClimbSearch(const std::shared_ptr<api::EightPuzzleNode> initialState,
                    const std::shared_ptr<api::EightPuzzleNode> goalState,
                    const std::shared_ptr<api::IHeuristicFunction> heuristicFunction,
                    const unsigned long& maxNumOfNodes);

    void search() override;

    bool solutionFound() const override;

    unsigned int noOfNodesGenerated() const override;

private:
    std::deque<std::shared_ptr<api::EightPuzzleNode>> m_SearchQueue;
    unsigned long m_MaxNumOfNodes; // Indicates the maximum number of nodes to be searched
    std::shared_ptr<api::EightPuzzleNode> m_GoalState;
    std::shared_ptr<api::IHeuristicFunction> m_Heuristic;
    bool m_IsSolutionFound;
};

} //namespace core

#endif // CORE_HILLCLIMBSEARCH_H
