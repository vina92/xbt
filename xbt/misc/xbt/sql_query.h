#pragma once

#include <xbt/data_ref.h>

class Cdatabase;
class Csql_result;

class Csql_query
{
public:
	Csql_result execute() const;
	std::string read() const;
	void operator=(const std::string&);
	void operator+=(const std::string&);
	Csql_query& p_name(const std::string&);
	Csql_query& p_raw(data_ref);
	Csql_query& operator()(long long);
	Csql_query& operator()(data_ref);
	Csql_query(Cdatabase&, const std::string& = "");

#if 1
	Csql_query& p(long long v)
	{
		return (*this)(v);
	}

	Csql_query& p(data_ref v)
	{
		return (*this)(v);
	}
#endif
private:
	std::string replace_names(const std::string&) const;

	std::string m_in;
	std::string m_out;
	Cdatabase& m_database;
};