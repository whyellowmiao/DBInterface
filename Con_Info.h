#ifndef CON_INFO_H
#define CON_INFO_H

#include <string>

typedef enum
{

 MySQL = 1,

 NoSQL

}
DB_Type;

class Con_Info
{

 public:

 Con_Info() {};

 Con_Info(DB_Type db):

 fdb(db){}

 Con_Info(DB_Type db,
          const std::string& url,
          const std::string& user,
          const std::string& password):

 fdb(db),
 furl(url),
 fuser(user),
 fpassword(password){}
 //virtual ~Con_Info() = default;
 DB_Type GetDB() const { return fdb; }

 const std::string GetURL() const { return furl; }

 const std::string GetUSER() const { return fuser; }

 const std::string GetPASSWORD() const { return fpassword; }

 virtual ~Con_Info() {};

 private:

 DB_Type fdb;

 std::string furl;

 std::string fuser;

 std::string fpassword;

};

#endif
