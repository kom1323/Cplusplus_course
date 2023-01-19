#ifndef  _PAGE_H
#define _PAGE_H

#pragma warning(disable : 4996)
#include "Types.h"
#include "Status.h"
#include "Member.h"
#include "FacebookExceptions.h"
#include "Entity.h"

class Page : public Entity
{
private:

public:
	Page(const string& name);
	Page() = default;

	const Page& operator=(const Page& other);
	Page& operator+=(Member& fan);

	bool operator>(const Member& other);
	bool operator>(const Page& other);
	bool operator<(const Member& other);
	bool operator<(const Page& other);

	void writeToFile(ostream& os) const override;
};
#endif // ! _PAGE
