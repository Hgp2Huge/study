#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <memory>
#include <string>
#include "query_base.h"
#include "queryresult.h"
#include "textquery.h"
#include "wordquery.h"

// interface class to manage the Query_base inhertance hierarchy
class Query {
    // these operators need access to the shared_ptr constructor
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&); // builds a new WordQuery
    // interface functions: call the corresponding Query_base operations
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;
};

inline
Query::Query(const std::string& s) : q(new WordQuery(s)) {}

#endif // QUERY_H
