#ifndef _MEDIA_STATUS_H
#define _MEDIA_STATUS_H

#include "Types.h"
#include "Status.h"
#include <string>

class MediaStatus : public Status
{
private:

	string fileName; // start 
	
public:
	MediaStatus(const string& status, const string& nameOfFile);
	
	void playMedia() const;

};

#endif //! _MEDIA_STATUS_H