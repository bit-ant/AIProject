#ifndef API_IHEURISTICFUNCTION_H
#define API_IHEURISTICFUNCTION_H

#include <memory>
#include <api/EightPuzzleNode.h>

namespace api {

class IHeuristicFunction {

public:
    ///
    /// \brief ~IHeuristicFunction
    ///
    virtual ~IHeuristicFunction() = default;

    ///
    /// \brief calculateNodeCost Calculate the node cost based on the current heuristic function
    /// \param node
    /// \return
    ///
    virtual float calculateCost(std::shared_ptr<api::EightPuzzleNode>& node) const = 0;
};
} // namespace api

#endif // API_IHEURISTICFUNCTION_H
