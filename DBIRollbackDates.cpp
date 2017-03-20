#include <cstring>
#include <stdexcept>
#include "DBIRollbackDates.h"

void DBIRollbackDates::Set(const std::vector<std::string>& config)
{

using std::string;

 bool  hasChanged = false;

 for(UInt_t i=0;i<config.size();i++) {

 string line = config[i];
 string::size_type p = line.find_first_of('=');
 if(p == string::npos) {
 std::cerr << "Incorrect form of rollback string; doesn't contain '=': " << line;
 }

 bool ok = true;
 string tablename = line.substr(0,p);

 p+=1;
 while(line[p]==' ') p++;
 string date = line.substr(p);

 TimeStamp ts(DBI::MakeTimeStamp(date,&ok));
 if ( ok ) {

 date = DBI::MakeDateTimeString(ts);
 int loc = date.size()-1;
 while ( loc && date[loc] == ' ' ) date.erase(loc--);

 fTableToDate[tablename] = date;
 hasChanged = true;

 } else {

 std::cout
 << "Illegal Rollback config item: " << line << std::endl
 << "Tablename = [" << tablename << "]   date = [" << date << "]" << std::endl;

 }
 }
 if ( hasChanged ) this->Show();
}

