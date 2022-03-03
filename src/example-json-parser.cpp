/*Very basic example of parsing a json msg */
#include<iomanip>
#include<iostream>
#include<rapidjson/document.h>
using namespace std;

//Type of JSON value
enum kType {
    kNullType = 0,      //null
    kFalseType = 1,     //false
    kTrueType = 2,      //true
    kObjectType = 3,    //object
    kArrayType = 4,     //array 
    kStringType = 5,    //string
    kNumberType = 6     //number
};

static std::string GetTypeName(int type)
{
    switch(type)
    {
        case kNullType:
            return "Null";
        case kFalseType:
            return "False";
        case kTrueType:
            return "True";
        case kObjectType:
            return "Object";
        case kArrayType:
            return "Array";
        case kStringType:
            return "String";
        case kNumberType:
            return "Number";
    }
    return (std::string());
}

/*
 *APIs for numbers
 *bool Value::IsInt() const
 *bool Value::IsUint() const
 *bool Value::IsInt64() const
 *bool Value::IsUint64() const
 *bool Value::IsDouble() const
 */

static std::string GetValue(const rapidjson::Value& value)
{
    if (value.IsString()) {
        return value.GetString();
    }
    if (value.IsNumber()) {
        return std::to_string(value.GetInt());
    }
    return (std::string());
}

int main()
{
    const char jsonmsg[] = R"json(
                {
                   "Name":"Sammi Srivastava",
                   "Age":30,
                   "Hobby":[
                      "Traveling",
                      "Exercise"
                   ],
                   "Address":{
                      "Country":"India",
                      "State":"Chandigarh",
                      "City":"Chandigarh",
                      "Pincode":"160104"
                   }
                }
                )json";

    std::cout <<"Json msg: " <<jsonmsg <<std::endl;

    rapidjson::Document document(rapidjson::kObjectType);
    document.Parse(jsonmsg);

    assert(document.IsObject());

    std::cout <<"Attribute:Type" <<std::endl;
    std::cout <<"-----------------------" <<std::endl;
    for (rapidjson::Value::ConstMemberIterator it = document.MemberBegin(); it != document.MemberEnd(); ++it)
    {
        std::cout <<it->name.GetString() <<":" <<GetTypeName(it->value.GetType()) <<std::endl;

        if (it->value.IsArray())
        {
            for (rapidjson::Value::ConstValueIterator it2 = it->value.Begin(); it2 != it->value.End(); ++it2)
            {
                std::cout <<std::setw(6) <<"-" <<GetTypeName(it2->GetType()) <<std::endl;
            }
        }
        if (it->value.IsObject())
        {
            for (rapidjson::Value::ConstMemberIterator it2 = it->value.MemberBegin(); it2 != it->value.MemberEnd(); ++it2)
            {
                std::cout <<std::setw(15) <<it2->name.GetString() <<":" <<GetTypeName(it2->value.GetType()) <<std::endl;
            }
        }
    }

    std::cout <<std::endl <<"Attribute:Value" <<std::endl;
    std::cout <<"-----------------------" <<std::endl;
    for (rapidjson::Value::ConstMemberIterator it = document.MemberBegin(); it != document.MemberEnd(); ++it)
    {
        std::cout <<it->name.GetString() <<":" <<GetValue(it->value) <<std::endl;

        if (it->value.IsArray())
        {
            for (rapidjson::Value::ConstValueIterator it2 = it->value.Begin(); it2 != it->value.End(); ++it2)
            {
                std::cout <<std::setw(6) <<"-" <<GetValue(*it2) <<std::endl;
            }
        }
        if (it->value.IsObject())
        {
            for (rapidjson::Value::ConstMemberIterator it2 = it->value.MemberBegin(); it2 != it->value.MemberEnd(); ++it2)
            {
                std::cout <<std::setw(15) <<it2->name.GetString() <<":" <<GetValue(it2->value) <<std::endl;
            }
        }
    }
    return 0;
}
