#include "MediaStatus.h"


MediaStatus::MediaStatus(const string& status, const string& nameOfFile): Status(status), fileName(nameOfFile)
{
	
}

void MediaStatus::playMedia() const
{
	string temp = "start ";
	temp += this->fileName;
	const char* run = temp.c_str();
	system(run);
}

void MediaStatus::writeToFile(ostream& os) const
{
	os << this->fileName<<endl;
}

void MediaStatus::readFromFile(istream& os)
{
	getline(os, this->fileName);

}
