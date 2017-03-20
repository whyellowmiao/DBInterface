#ifndef DBI_H
#define DBI_H

#include <map>
#include <string>
#include "Context/TimeStamp.h"
#include "Context.h"

namespace DBI
{

std::string MakeDataTimeString(const TimeStamp& timeStamp);
TimeStamp MakeTimeStamp(const std::string& sqlDateTime, bool* ok=0);

}

#endif
