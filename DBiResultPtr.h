#ifndef DBIRESULTPTR
#define DBIRESULTPTR

#include <stdexcept>
#include "Context.h"
#include "DB_Svc.h"
#include "DB_TableRow.h"

class DB_Svc;

template <class T> class DBiResultPtr
{

public:

DBiResultPtr() = default;
DBiResultPtr(const Context& c);

virtual ~DBiResultPtr() = default;

void Session();

void GetResByRowNum(int id);

int GetInt(const std::string&) const;

double GetDouble(const std::string&) const;

std::string GetString(const std::string&) const;

private:

void MvCursorbeforeFirst();

void MvCursortoNext();

Context PtrContext;

DB_Svc PtrSvc;

int RowCount;

std::shared_ptr<std::vector<T>> data;

};

template <class T>
DBiResultPtr<T>::DBiResultPtr(const Context& c):
PtrContext(c),
PtrSvc(c)
{
#ifdef FORSNIPER
LogInfo << "Building Result Pointer" << std::endl;
#else
std::cout << "Building Result Pointer" << std::endl;
#endif
}

template <class T>
void DBiResultPtr<T>::Session()
{
PtrSvc.Session(PtrContext);
}

template <class T>
void DBiResultPtr<T>::GetResByRowNum(int id)
{
//id=0 means read the first line
MvCursorbeforeFirst();
for(int i=0;i<=(id-RowCount);i++)
MvCursortoNext();
}

template <class T>
void DBiResultPtr<T>::MvCursorbeforeFirst()
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
void DBiResultPtr<T>::MvCursortoNext()
{
PtrSvc.FetchResult().GetResult()->next();
RowCount++;
}

template <class T>
int DBiResultPtr<T>::GetInt(const std::string& str) const
{
return PtrSvc.FetchResult().GetResult()->getInt(str);
}

template <class T>
double DBiResultPtr<T>::GetDouble(const std::string& str) const
{
return PtrSvc.FetchResult().GetResult()->getDouble(str);
}

template <class T>
std::string DBiResultPtr<T>::GetString(const std::string& str) const
{
return PtrSvc.FetchResult().GetResult()->getString(str);
}

#endif
