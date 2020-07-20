// chatbot.h

//
// Your chatbot class goes here. Make sure it works with chatbot_driver.cpp.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctype.h>

// set of classes to identify the words in a sentence from the user
enum word_class {
    UNKNOWN, NOUN, PRONOUN, ARTICLE, LINKING_VERB, CONJUNCTION, POSSESSIVE, INTERROGATIVE
};

///////////////////////////////////////////////
// language data class
class Vocabulary {
    public:

        Vocabulary();

        const std::vector<std::string>
        pronouns {
            "i", "you", "he", "she", "we", "they", "it", "us", "me"
        },

        articles {
            "a", "an", "the"
        },

        linking_verbs {
            "is", "am", "are", "was", "were", "have", "has", "had", "be", "been"
        },

        conjunctions {
            "and", 
        },

        possessives {
            "my", "our", "your", "his", "her", "its", "their"
        },

        interrogatives {
            "what", "who", "why", "when", "how", "where"
        },

        greetings {
            "hi", "hello", "hey"
        }
        ;
};

Vocabulary::Vocabulary()
{}

// user data class
class UserData {
    public:
        bool greeting_given_, farewell_given_;
        std::vector<std::string> interests_, favourites_, cached_words_;
};

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
        std::vector<std::string> get_words();

        unsigned long count_words();
};

// default sentence constructor
Sentence::Sentence()
    : raw_sentence_(""), words_{}, word_count_(0)
{}

// sentence constructor
Sentence::Sentence(const std::string sentence)
    : raw_sentence_(sentence), words_{}, word_count_(0)
{
    parse_words();
    print_words();
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

// return the word count of the sentence
unsigned long Sentence::count_words()
{
    return this->word_count_;
}

// return the parsed words vector
std::vector<std::string> Sentence::get_words()
{
    return this->words_;
}

///////////////////////////////////////////////
// language processor class
class LanguageProcessor {
    private:

        Vocabulary vocab_;

        Sentence in_sentence_;
        std::vector<word_class> word_classes_;

        void interpret_word_classes();

    public:

        LanguageProcessor();
        
        void process();
        void print_word_classes();
        void set_sentence(Sentence sentence);
        Sentence get_sentence();
        
};

// language processor constructor
LanguageProcessor::LanguageProcessor()
    : vocab_(Vocabulary()), in_sentence_(Sentence()), word_classes_{}
{}

// process the current stored sentence
void LanguageProcessor::process()
{
    print_word_classes();
    
    if (this->in_sentence_.count_words() >= 3)
    {
        /* code */
    }
    else
    {
        /* code */
    }
    
}

// determine the word classes of the current sentence, clears previous values
void LanguageProcessor::interpret_word_classes()
{
    std::vector<std::string> words = this->in_sentence_.get_words();
    this->word_classes_.clear();

    for (size_t i = 0; i < this->in_sentence_.count_words(); i++)
    {
        this->word_classes_.push_back(UNKNOWN);
        // check for article
        for (std::string word: this->vocab_.articles)
        {
            if (word == words[i]) this->word_classes_[i] = ARTICLE;
        }
        // check for linking verb
        for (std::string word: this->vocab_.linking_verbs)
        {
            if (word == words[i]) this->word_classes_[i] = LINKING_VERB;
        }
        // check for interrogatives
        for (std::string word: this->vocab_.interrogatives)
        {
            if (word == words[i]) this->word_classes_[i] = INTERROGATIVE;
        }
        // check for pronouns
        for (std::string word : this->vocab_.pronouns)
        {
            if (word == words[i]) this->word_classes_[i] = PRONOUN;
        }
        // check for possessives
        for (std::string word : this->vocab_.possessives)
        {
            if (word == words[i]) this->word_classes_[i] = POSSESSIVE;
        }
        // check for conjunctions
        for (std::string word : this->vocab_.conjunctions)
        {
            if (word == words[i]) this->word_classes_[i] = CONJUNCTION;
        }

    }
    
}

// set the sentence to be processed
void LanguageProcessor::set_sentence(Sentence sentence)
{
    this->in_sentence_ = sentence;
    interpret_word_classes();
}

// print the identified word classes
void LanguageProcessor::print_word_classes()
{
    std::cout << "{ ";
    for (word_class current : this->word_classes_)
    {
        std::cout << current;
        std::cout << " ";
    }
    std::cout << "}\n";
}

///////////////////////////////////////////////
// main chatbot class
class Chatbot {
    private:

        std::string bot_name_;
        std::string bot_reply_;

        size_t reply_count_;

        Sentence user_message_;

        LanguageProcessor processor_ = LanguageProcessor();

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
    : bot_name_("Chatty"), bot_reply_(""), reply_count_(0), user_message_(Sentence())
{}

// chatbot constructor with name field
Chatbot::Chatbot(std::string name)
    : bot_name_(name), bot_reply_(""), reply_count_(0), user_message_(Sentence())
{}

// returns the chatbots name field
std::string Chatbot::get_name()
{
    return this->bot_name_;
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
    this->processor_.set_sentence(this->user_message_);
    this->processor_.process();
    //this->user_message_.print_words();
}

// formulates and returns the current bot reply to the current user message
std::string Chatbot::get_reply()
{
    reply_count_ += 1;
    return this->bot_reply_;
}

//
// You can #include any standard C++ files, but do not use any other outside
// code (unless you write it).
//