#ifndef DBWRITER
#define DBWRITER

#include "Context.h"
#include "DBInterface.h"
#include "DB_TableRow.h"

template <class T> class DBWriter
{

public:

DBWriter() {};
DBWriter(const Context& c);

virtual ~DBWriter() {};

DBWriter<T>& operator<<(const T& row);

private:

Context cx;

T temrow;

std::vector<T>* data;

};

template<class T>
DBWriter<T>::DBWriter(const Context& c):
cx(c)
{
#ifdef FORSNIPER
LogInfo << "Constructing DBWriter..." << std::endl;
#else
std::cout << "Consturcting DBWriter..." << std::endl;
#endif
}

template<class T>
DBWriter<T>& DBWriter<T>::operator<<(const T& row)
{

temrow = row;
temrow.Store(cx);

return *this;

}

#endif
