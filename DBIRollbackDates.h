#ifndef DBIROLLBACKDATES_H
#define DBIROLLBACKDATES_H

#include <map>
#include <vector>
#include <string>

/*#ifndef ROOT_Rtypes
#if !defined(__CINT__) || defined(__MAKECINT__)
#include "Rtypes.h"
#endif
#endif*/

class DBIRollbackDates
{
 public:

 DBIRollbackDates();
virtual ~DBIRollbackDates();

 const std::string& Get(const std::string& tableName) const;
 void Show() const;

 void Clear() {fTableToDate.clear();}
 void Set(const std::vector<std::string>& config);
 void Set(const std::string& config&);

 private:

 std::map<std::string,std::string> fTableToDate;

};

#endif
