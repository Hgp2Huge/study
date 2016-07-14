#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "query.h"
#include "query_base.h"

class WordQuery : public Query_base {
    friend class Query; // Query uses the WordQuery constructor
    WordQuery(const std::string& s) : query_word(s) {}
    // concrete class: WordQuery defines all inherited virtual functions
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    std::string rep() const { return query_word; }
    std::string query_word; // word for which to search
};

#endif // WORDQUERY

