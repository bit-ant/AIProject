#include <core/HillClimbSearch.h>
#include <algorithm>

namespace core {

HillClimbSearch::HillClimbSearch(const std::shared_ptr<api::EightPuzzleNode> initialState,
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

void HillClimbSearch::search()
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
            child->setCost(m_Heuristic->calculateCost(child));
        }

        if (children.size() > 1)
        {
            // Sort new nodes based on cost
            std::sort(children.begin(), children.end(),
                      [] (std::shared_ptr<api::EightPuzzleNode>& a, std::shared_ptr<api::EightPuzzleNode>& b)
                            { return a->getCost() < b->getCost(); });

            // Add new nodes to the front of the queue
            // Note: reverse iterate so that the node with the lower cost ends up at the front
            for (std::vector<std::shared_ptr<api::EightPuzzleNode>>::reverse_iterator it = children.rbegin();
                    it != children.rend(); ++it )
            {
                m_SearchQueue.push_front(*it);
            }
        }
        else
        {
            // Just add the single new child at the front
            m_SearchQueue.push_front(children.front());
        }
        // Recursive call to continue searching
        search();
    }
}

bool HillClimbSearch::solutionFound() const
{
    return m_IsSolutionFound;
}

unsigned int HillClimbSearch::noOfNodesGenerated() const
{
    return static_cast<unsigned int>(m_SearchQueue.size());
}

} // namespace core
