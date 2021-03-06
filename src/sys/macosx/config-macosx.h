// -----------------------------------------------
// config-macosx.h
//
// Mac os specific definitions for reading/writting configuration data
//
// Written by Ed Zavada, 2004-2012
// Copyright (c) 2012, Dream Rock Studios, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// -----------------------------------------------


#ifndef PDG_CONFIGMANAGER_MACOSX_H_INCLUDED
#define PDG_CONFIGMANAGER_MACOSX_H_INCLUDED

#include "pdg_project.h"

#include "pdg/sys/config.h"

#include <string>

namespace pdg {

class ConfigManagerMac : public ConfigManager {
public:
	ConfigManagerMac();
	virtual ~ConfigManagerMac();
	// return false if config not found, unusable or empty
    bool  useConfig(const char* inConfigName);

    // getters
    // find a given item by case insensitive name in the config, return false if not found, true and value if found
    bool  getConfigString(const char* configItemName, std::string& outString);
    bool  getConfigLong(const char* configItemName, long& outLongValue);
    bool  getConfigFloat(const char* configItemName, float& outFloatValue);
    bool  getConfigBool(const char* configItemName, bool& outBooleanValue);

    // setters
    // change a given item by case insensitive name in the config, save the changes immediately
    void  setConfigString(const char* configItemName, std::string inString);
    void  setConfigLong(const char* configItemName, long inLongValue);
    void  setConfigFloat(const char* configItemName, float inFloatValue);
    void  setConfigBool(const char* configItemName, bool inBooleanValue);
protected:
    std::string mAppKey;
};

}  // close namespace pdg

#endif // PDG_CONFIGMANAGER_MACOSX_H_INCLUDED
