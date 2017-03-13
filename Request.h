#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <vector>
#include "Con_Info.h"

typedef enum
{

 lookup,

 createtable,

 customreq,

 infilepath,

 insertcode

}
RequestProxy;

class Request
{

 public:

 Request(DB_Type db = MySQL,
         RequestProxy reqpro = lookup):

 fdb(db),
 freqpro(reqpro){}

 Request(const std::vector<std::string>& property,
         const std::string& tablename,
         RequestProxy reqpro = lookup,
         const std::string& schema = "",
         DB_Type db = MySQL
         ):

 fdb(db),
 freqpro(reqpro),
 fschema(schema),
 ftablename(tablename),
 fproperty(property){}

 Request(const std::string& sqlquery,
         DB_Type db = MySQL,
         RequestProxy reqpro = customreq,
         const std::string& schema = "",
         const std::string& tablename = ""):

 fdb(db),
 freqpro(reqpro),
 fschema(schema),
 ftablename(tablename),
 fsqlquery(sqlquery){}

 virtual ~Request() = default;

 const DB_Type GetDB() const { return fdb; }

 const RequestProxy GetRequest() const{ return freqpro; }

 const std::string GetSchema() const{ return fschema; }

 const std::string GetTableName() const{ return ftablename; }

 const std::string GetSqlquery() const { return fsqlquery; }

 const std::vector<std::string> GetPro() const{ return fproperty; }

 private:

 DB_Type fdb;

 RequestProxy freqpro;

 std::string fschema;

 std::string ftablename;

 std::string fsqlquery;

 std::vector<std::string> fproperty;

};

#endif
