#include <core/AStarSearch.h>
#include <algorithm>

namespace core {

AStarSearch::AStarSearch::AStarSearch(const std::shared_ptr<api::EightPuzzleNode> initialState,
                                      const std::shared_ptr<api::EightPuzzleNode> goalState,
                                      const std::shared_ptr<api::IHeuristicFunction> heuristicFunction,
                                      const unsigned long &maxNumOfNodes)
    : m_SearchQueue(),
      m_MaxNumOfNodes(maxNumOfNodes),
      m_GoalState(),
      m_Heuristic(heuristicFunction),
      m_IsSolutionFound(false)
{
    if (nullptr == initialState || nullptr == goalState || nullptr == heuristicFunction)
    {
        throw;
    }
    else
    {
        m_SearchQueue.push_back(initialState);
        m_GoalState = goalState;
    }
}

void AStarSearch::search()
{
    static unsigned long noOfGeneratedNodes = 0;

    // Get first element
    const std::shared_ptr<api::EightPuzzleNode> currentNode = m_SearchQueue.front();

    // Remove first element from queue
    m_SearchQueue.pop_front();

    // Is this the goal?
    if (currentNode->getState() == m_GoalState->getState())
    {
        // Solution found!
        m_IsSolutionFound = true;
        return;
    }
    if (noOfGeneratedNodes >= m_MaxNumOfNodes)
    {
        // No solution found within the given limit
        // Abort search
        return;
    }
    else
    {
        // Get possible next moves
        api::EightPuzzleNode::nodeChildren children = currentNode->generateChildren();
        if (children.empty())
        {
            // No more nodes
            return;
        }

        // Increment the number of generated nodes
        noOfGeneratedNodes+= children.size();

        // Calculate children's costs
        for (std::shared_ptr<api::EightPuzzleNode>& child : children)
        {
            // Consider accumulated cost as well
            // At each step, the accumulated cost is that of the parent plus the one calculated for the current child
            child->setCost(currentNode->getCost() + m_Heuristic->calculateCost(child));
        }

        if (children.size() > 1)
        {
            // Add new nodes to the the queue
            // Order does not matter, queue shall be sorted
            for (std::vector<std::shared_ptr<api::EightPuzzleNode>>::iterator it = children.begin();
                    it != children.end(); ++it )
            {
                m_SearchQueue.push_back(*it);
            }
        }
        else
        {
            // Just add the single new child at the front
            m_SearchQueue.push_back(children.front());
        }
        // Sort entire queue based on cost
        std::sort(m_SearchQueue.begin(), m_SearchQueue.end(),
                  [] (std::shared_ptr<api::EightPuzzleNode>& a, std::shared_ptr<api::EightPuzzleNode>& b)
                        {
                            if (nullptr == a)
                                return false;
                            if (nullptr == b)
                                return true;
                            return a->getCost() < b->getCost();
                        });

        // Remove duplicate states and keep the one with the lowest cost
        std::unique(m_SearchQueue.begin(), m_SearchQueue.end(),
                    [] (std::shared_ptr<api::EightPuzzleNode>& a, std::shared_ptr<api::EightPuzzleNode>& b)
                        {
                            if (nullptr == a)
                                return false;
                            if (nullptr == b)
                                return true;
                            return a->getState() == b->getState() && a->getCost() < b->getCost();
                        });

        // Recursive call to continue searching
        search();
    }
}

bool AStarSearch::solutionFound() const
{
    return false;
}

unsigned int AStarSearch::noOfNodesGenerated() const
{
    return 0;
}

} // namespace core
