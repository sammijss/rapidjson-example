/*Very basic example of creating json msg */
#include<iostream>
#include<rapidjson/document.h>
#include<rapidjson/prettywriter.h>
using namespace std;

/*
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
*/

int main()
{
    //Document is the root of a json message
    rapidjson::Document document; //document(kObjectType)

    //Created this document as an object rather than an array
    document.SetObject();

    //Pass an allocator when the object may need to allocate memory
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

    document.AddMember("Name", rapidjson::Value().SetString("Sammi Srivastava"), allocator);
    document.AddMember("Age", rapidjson::Value().SetInt(35), allocator);

    //Create an array type, similar to std::vector
    rapidjson::Value array(rapidjson::kArrayType);
    array.PushBack("Traveling", allocator);
    array.PushBack("Exercise", allocator);

    document.AddMember("Hobby", array, allocator);

    //Create an object type
    rapidjson::Value object(rapidjson::kObjectType);
    object.AddMember("Country", "India", allocator);
    object.AddMember("State", "Chandigarh", allocator);
    object.AddMember("City", "Chandigarh", allocator);
    object.AddMember("Pincode", "160104", allocator);

    document.AddMember("Address", object, allocator);

    rapidjson::StringBuffer buffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    std::cout <<buffer.GetString() <<std::endl;

    return 0;
}
