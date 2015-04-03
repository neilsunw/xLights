#ifndef UTILCLASSES_H
#define UTILCLASSES_H

#include "wx/wx.h"
#include <map>


class MapStringString: public std::map<wxString,wxString> {
public:
    MapStringString(): std::map<wxString,wxString>() {
    }
    const wxString &operator[](const wxString &key) const {
        return Get(key, notFound);
    }
    wxString &operator[](const wxString &key) {
        return std::map<wxString, wxString>::operator[](key);
    }
    const wxString &Get(const wxString &key, const wxString &def) const {
        std::map<wxString,wxString>::const_iterator i(find(key));
        if (i == end()) {
            return def;
        }
        return i->second;
    }
    
    void Parse(const wxString &str) {
        clear();
        wxString before,after,name,value;
        wxString settings(str);
        while (!settings.IsEmpty()) {
            before=settings.BeforeFirst(',');
            settings=settings.AfterFirst(',');
            
            name=before.BeforeFirst('=');
            value=before.AfterFirst('=');
            (*this)[name]=value;
        }
    }
    
    wxString AsString() const {
        wxString ret;
        for (std::map<wxString,wxString>::const_iterator it=begin(); it!=end(); ++it) {
            if (ret.Length() != 0) {
                ret += ",";
            }
            ret += it->first + "=" + it->second;
        }
        return ret;
    }
    
    
private:
    wxString notFound;
};


#endif