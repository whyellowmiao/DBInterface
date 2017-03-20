/*#include "DBiResultPtr.h"

template <class T>
DBiResultPtr<T>::DBiResultPtr(const Context& c):
PtrContext(c),
PtrSvc(c)
{
std::cout << "Building Result Pointer" << std::endl;
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
}*/
