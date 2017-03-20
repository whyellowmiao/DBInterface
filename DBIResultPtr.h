#ifndef DBIRESULTPTR_H
#define DBIRESULTPTR_H

#include <stdexcept>
#include "Context.h"
#include "DBInterface.h"
#include "DB_TableRow.h"

class DBInterface;

template <class T> class DBIResultPtr
{

public:

DBIResultPtr() {};
DBIResultPtr(const Context& c);

virtual ~DBIResultPtr() {};

void Session();

void GetResByRowNum(int id);

int GetInt(const std::string&) const;

double GetDouble(const std::string&) const;

std::string GetString(const std::string&) const;

private:

void MvCursorbeforeFirst();

void MvCursortoNext();

Context PtrContext;

DBInterface PtrSvc;

int RowCount;

std::vector<T>* data;

};

template <class T>
DBIResultPtr<T>::DBIResultPtr(const Context& c):
PtrContext(c)
//PtrSvc(c)
{
#ifdef FORSNIPER
LogInfo << "Building Result Pointer" << std::endl;
#else
std::cout << "Building Result Pointer" << std::endl;
#endif
}

template <class T>
void DBIResultPtr<T>::Session()
{
PtrSvc.Session(PtrContext);
}

template <class T>
void DBIResultPtr<T>::GetResByRowNum(int id)
{
//id=0 means read the first line
MvCursorbeforeFirst();
for(int i=0;i<=(id-RowCount);i++)
MvCursortoNext();
}

template <class T>
void DBIResultPtr<T>::MvCursorbeforeFirst()
{
RowCount = 0;
if(PtrSvc.FetchResult().GetConnection()!=NULL)
{
 if(PtrSvc.FetchResult().GetConnection()->isValid())
 #ifdef FORSNIPER
 LogInfo << "con is valid" << std::endl;
 #else
 std::cout << "con is valid" << std::endl;
 #endif
 else
 #ifdef FORSNIPER
 LogError << "con is unvalid" << std::endl;
 #else
 std::cerr << "con is unvalid" << std::endl;
 #endif
}
else
#ifdef FORSNIPER
LogError<< "con is unfetchable" << std::endl;
#else
std::cout << "con is unfetchable" << std::endl;
#endif
PtrSvc.FetchResult().GetResult()->beforeFirst();
}

template <class T>
void DBIResultPtr<T>::MvCursortoNext()
{
PtrSvc.FetchResult().GetResult()->next();
RowCount++;
}

template <class T>
int DBIResultPtr<T>::GetInt(const std::string& str) const
{
return PtrSvc.FetchResult().GetResult()->getInt(str);
}

template <class T>
double DBIResultPtr<T>::GetDouble(const std::string& str) const
{
return PtrSvc.FetchResult().GetResult()->getDouble(str);
}

template <class T>
std::string DBIResultPtr<T>::GetString(const std::string& str) const
{
return PtrSvc.FetchResult().GetResult()->getString(str);
}

#endif
