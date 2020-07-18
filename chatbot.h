// chatbot.h

//
// Your chatbot class goes here. Make sure it works with chatbot_driver.cpp.
//
#include <string>
#include <vector>

///////////////////////////////////////////////
// language processor class
class LanguageProcessor {
    private:

        std::string in_sentence_, out_sentence_;

    public:
    
        LanguageProcessor();
        
};

LanguageProcessor::LanguageProcessor()
    : in_sentence_(""), out_sentence_("") {}

///////////////////////////////////////////////
// main chatbot class
class Chatbot {
    private:

        std::string bot_name_;
        std::string bot_reply_;

        std::string user_message_;

        void form_reply();

    public:

        Chatbot(std::string name);

        std::string get_name();
        std::string get_reply();

        void set_name(std::string name);
        void tell(std::string);
        
};

Chatbot::Chatbot(std::string name) {
    this->bot_name_ = name;
}

std::string Chatbot::get_name()
{
    return this->bot_name_;
}

std::string Chatbot::get_reply()
{
    return this->bot_reply_;
}

void Chatbot::set_name(std::string name)
{
    this->bot_name_ = name;
}

void Chatbot::tell(std::string msg)
{
    this->user_message_ = msg;
}

//
// You can #include any standard C++ files, but do not use any other outside
// code (unless you write it).
//