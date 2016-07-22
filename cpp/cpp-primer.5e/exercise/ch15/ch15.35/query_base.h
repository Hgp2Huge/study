#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include <string>
#include "textquery.h"
#include "queryresult.h"

// abstruct class acts as a base class for concrete query types;
// all members are private
class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no; // used the eval functions
    virtual ~Query_base() = default;
private:
    // eval returns the QueryResult that matchs this Query
    virtual QueryResult eval(const TextQuery&) const = 0;
    // rep is a string representation of the query
    virtual std::string rep() const = 0;
};

#endif // QUERY_BASE_H
