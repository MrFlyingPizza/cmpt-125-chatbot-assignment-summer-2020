// chatbot.h

//
// Your chatbot class goes here. Make sure it works with chatbot_driver.cpp.
//
#include <string>
#include <vector>
#include <iostream>

///////////////////////////////////////////////
// sentence class
class Sentence {
    private:

        std::string raw_sentence_;
        std::vector<std::string> words_;
        unsigned long word_count_;

        void parse_words();

    public:

        Sentence();
        Sentence(const std::string sentence);

        void print_words();
};

// default sentence constructor
Sentence::Sentence()
    : raw_sentence_(""), word_count_(0)
{}

// sentence constructor
Sentence::Sentence(const std::string sentence)
    : raw_sentence_(sentence), word_count_(0)
{
    parse_words();
}

// get the words from a sentence and store it in a vector
void Sentence::parse_words()
{
    std::string sentence = this->raw_sentence_;
    std::string word = "";

    unsigned int count = sentence.length(), i = 0;
    while (i < count)
    {
        if (sentence[i] != ' ')
        {
            word += sentence[i];
        }
        else if (!word.empty())
        {
            this->words_.push_back(word);
            this->word_count_ += 1;
            word = "";
        }
        ++i;
    }

    if (!word.empty())
    {
        this->words_.push_back(word);
        this->word_count_ += 1;
        word = "";
    }

}

// print all the word count and all the words that has been parsed
void Sentence::print_words()
{
    std::cout << "count: " + std::to_string(this->word_count_);
    std::cout << " | ";
    std::cout << "{ ";
    for (std::string word : this->words_)
    {
        std::cout << word + " ";
    }
    std::cout << "}\n";
}

///////////////////////////////////////////////
// language processor class
class LanguageProcessor {
    private:

        Sentence in_sentence_, out_sentence_;

    public:

        LanguageProcessor();
        
};

// language processor constructor
LanguageProcessor::LanguageProcessor()
    : in_sentence_(Sentence()), out_sentence_(Sentence())
{}

///////////////////////////////////////////////
// main chatbot class
class Chatbot {
    private:

        std::string bot_name_;
        std::string bot_reply_;

        Sentence user_message_;

        LanguageProcessor processor_;

    public:

        Chatbot();
        Chatbot(std::string name);

        std::string get_name();
        std::string get_reply();

        void set_name(std::string name);
        void tell(std::string);
        
};

// default chatbot constructor
Chatbot::Chatbot()
    : bot_name_("Chatty"), bot_reply_(""), user_message_(Sentence())
{}

// chatbot constructor with name field
Chatbot::Chatbot(std::string name)
    : bot_name_(name), bot_reply_(""), user_message_(Sentence())
{}

// returns the chatbots name field
std::string Chatbot::get_name()
{
    return this->bot_name_;
}

// formulates and returns the current bot reply to the current user message
std::string Chatbot::get_reply()
{
    return this->bot_reply_;
}

// set chatbots name field to something else
void Chatbot::set_name(std::string name)
{
    this->bot_name_ = name;
}

// give the chatbot the user's current message
void Chatbot::tell(std::string msg)
{
    this->user_message_ = Sentence(msg);
    //this->user_message_.print_words();
}

//
// You can #include any standard C++ files, but do not use any other outside
// code (unless you write it).
//