#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "12";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2017";
	static const char UBUNTU_VERSION_STYLE[] =  "17.11";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 2;
	static const long MINOR  = 1;
	static const long BUILD  = 13;
	static const long REVISION  = 12940;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 1434;
	#define RC_FILEVERSION 2,1,13,12940
	#define RC_FILEVERSION_STRING "2, 1, 13, 12940\0"
	static const char FULLVERSION_STRING [] = "2.1.13.12940";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 11;
	

}
#endif //VERSION_H
