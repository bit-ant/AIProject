#ifndef API_ISEARCHALGORITHM_H
#define API_ISEARCHALGORITHM_H

#include <api/IHeuristicFunction.h>

namespace api {

class ISearchAlgorithm {

public:
    ///
    /// \brief ~ISearchAlgorithm
    ///
    virtual ~ISearchAlgorithm() = default;

    ///
    /// \brief search
    ///
    virtual void search() = 0;

    ///
    /// \brief solutionFound
    /// \return True if solution was found
    ///
    virtual bool solutionFound() const = 0;

    ///
    /// \brief noOfNodesGenerated
    /// \return The number of nodes generated for the search
    ///
    virtual unsigned int noOfNodesGenerated() const = 0;
};
} // namespace api

#endif // API_ISEARCHALGORITHM_H
