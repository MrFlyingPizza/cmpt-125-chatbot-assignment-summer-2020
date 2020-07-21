// chatbot.h

//
// Your chatbot class goes here. Make sure it works with chatbot_driver.cpp.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <array>
#include <map>

// set of classes to identify the words in a sentence from the user
enum word_class {
    UNKN, NOUN, PNUN, RTCL, LVRB, CONJ, POSS, INTR, VERB, PREP, TEMP
};

// insert a string into the char placeholder of another string
std::string insert_at_placeholder(std::string orig, std::string content, char placeholder)
{
    std::string new_str = "";
    for (char ch : orig)
    {
        if (ch == placeholder)
        {
            new_str += content;
        }
        else
        {
            new_str += ch;
        }
        
    }
    return new_str;
}

// get keys from a map
std::vector<std::vector<word_class>> get_pattern_keys(std::map<std::vector<word_class>, std::vector<std::string>> map_obj)
{
    std::vector<std::vector<word_class>> keys;
    for (std::map<std::vector<word_class>, std::vector<std::string>>::iterator iter = map_obj.begin(); iter != map_obj.end(); ++iter)
    {
        keys.push_back(iter->first);
    }
    return keys;
}

// slice word_class vector
std::vector<word_class> slice(std::vector<word_class> orig, size_t front, size_t back)
{
    auto start = orig.begin();
    auto end = orig.end();

    std::vector<word_class> sliced(back - front + 1);
    std::copy(start, end, sliced.begin());

    return sliced;
}

// get a random string from a supplied vector
std::string get_random_item(std::vector<std::string> items)
{
    int rand_num = rand() % items.size();

    return items[rand_num];
}

// limited random number generator
unsigned int limited_rand()
{
    return rand() % 100 + 1;
}

// find a string in a vector and return the index
int find(std::vector<std::string> items, std::string item)
{
    int i = 0;
    bool found = false;
    while (i < (int) items.size() && !found)
    {
        if (items[i] == item)
        {
            found = true;
        }
        else
        {
            ++i;
        }
        
    }
    if (!found)
    {
        i = -1;
    }
    return i;
}

///////////////////////////////////////////////
// language data class
class Vocabulary {
    public:

        static std::vector<std::string>
        pronouns,

        articles,

        linking_verbs,

        conjunctions,

        possessives,

        interrogatives,

        prepositions,

        greetings
        ;
};

// vocabulary definitions
std::vector<std::string> Vocabulary::pronouns {
    "i", "you", "he", "she", "we", "they", "it", "us", "me"
},

Vocabulary::articles {
    "a", "an", "the"
},

Vocabulary::linking_verbs {
    "is", "am", "are", "was", "were", "have", "has", "had", "be", "been"
},

Vocabulary::conjunctions {
    "and", "for", "or"
},

Vocabulary::possessives {
    "my", "our", "your", "his", "her", "its", "their"
},

Vocabulary::interrogatives {
    "what", "who", "why", "when", "how", "where"
},

Vocabulary::prepositions {
    "of"
},

Vocabulary::greetings {
    "hi", "hello", "hey"
};

///////////////////////////////////////////////
// user data class
class UserData {
    public:
        bool greeting_given_, farewell_given_;
        std::vector<std::string> cached_words_;

        unsigned int greeting_count = 0;

        UserData();
};

// user constructor
UserData::UserData()
    : greeting_given_(false), farewell_given_(false)
{}

///////////////////////////////////////////////
// sentence class
class Sentence {
    private:

        std::string raw_sentence_;
        std::vector<std::string> words_;
        std::vector<word_class> word_classes_;
        std::vector<word_class> condensed_word_classes_;

        unsigned long word_count_;

        void parse_words();
        void interpret_word_classes();
        void interpret_condensed_word_classes();

    public:

        Sentence();
        Sentence(const std::string sentence);

        void print_words();
        void print_word_classes(unsigned short choice);

        std::vector<std::string> get_words();

        unsigned long count_words();
        std::vector<word_class> get_classes(unsigned short choice);
};

// default sentence constructor
Sentence::Sentence()
    : raw_sentence_(""), words_{}, word_classes_{}, condensed_word_classes_{}, word_count_(0)
{}

// sentence constructor
Sentence::Sentence(const std::string sentence)
    : raw_sentence_(sentence), words_{}, word_classes_{}, condensed_word_classes_{}, word_count_(0)
{
    parse_words();
    interpret_word_classes();
    interpret_condensed_word_classes();
    print_words();
}

// get the word classes of the sentence
std::vector<word_class> Sentence::get_classes(unsigned short choice)
{
    std::vector<word_class> selected_word_classes = this->word_classes_;
    if (choice == 1)
    {
        selected_word_classes = this->condensed_word_classes_;
    }
    return selected_word_classes;
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

// neatly print the word classes of the sentence
// print the identified word classes
void Sentence::print_word_classes(unsigned short choice)
{
    std::vector<word_class> classes = this->word_classes_;
    if (choice == 1) classes = this->condensed_word_classes_;
    std::cout << "{ ";
    for (word_class current : classes)
    {
        std::cout << current;
        std::cout << " ";
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

// determine the word classes of the current sentence, clears previous values
void Sentence::interpret_word_classes()
{
    for (size_t i = 0; i < this->word_count_; i++)
    {
        this->word_classes_.push_back(UNKN);
        // check for article
        for (std::string word: Vocabulary::articles)
        {
            if (word == this->words_[i]) this->word_classes_[i] = RTCL;
        }
        // check for linking verb
        for (std::string word: Vocabulary::linking_verbs)
        {
            if (word == this->words_[i]) this->word_classes_[i] = LVRB;
        }
        // check for interrogatives
        for (std::string word: Vocabulary::interrogatives)
        {
            if (word == this->words_[i]) this->word_classes_[i] = INTR;
        }
        // check for pronouns
        for (std::string word : Vocabulary::pronouns)
        {
            if (word == this->words_[i]) this->word_classes_[i] = PNUN;
        }
        // check for possessives
        for (std::string word : Vocabulary::possessives)
        {
            if (word == this->words_[i]) this->word_classes_[i] = POSS;
        }
        // check for conjunctions
        for (std::string word : Vocabulary::conjunctions)
        {
            if (word == this->words_[i]) this->word_classes_[i] = CONJ;
        }

        // check for prepositions
        for (std::string word : Vocabulary::prepositions)
        {
            if (word == this->words_[i]) this->word_classes_[i] = PREP;
        }

    }
    
}

// further deduct the sentence structure
void Sentence::interpret_condensed_word_classes()
{
    word_class temp = TEMP;
    for (word_class current : this->word_classes_)
    {
        if (current != temp)
        {
            temp = current;
            this->condensed_word_classes_.push_back(temp);
        }
        
    }
    
}

///////////////////////////////////////////////
// language processor class
class LanguageProcessor {
    private:

        UserData user_;

        Sentence message_;
        std::string response_;

        void evaluate_greater();
        void evaluate_lesser();

        static std::map<std::vector<word_class>, std::vector<std::string>> pattern_map;
        static std::vector<std::string>
        
        // formulated replys
        greeted_msg_,

        // reply components
        greetings_,

        initiate_,

        provoke_,

        excessive_greeting_,

        display_interest_,

        refuse_answer_
        ;


    public:

        LanguageProcessor();
        
        void process();
        void set_sentence(Sentence sentence);
        std::string get_response();
        void clear();

        std::string get_reply;
        
};

std::map<std::vector<word_class>, std::vector<std::string>>
LanguageProcessor::pattern_map {
    {std::vector<word_class>{PNUN, UNKN}, std::vector<std::string>{
        "Tell me more about |",
        "I'm curious to hear more about |",
        "Oh, |, tell me more.",
        "Is | really what you need?",
        "| must be really important.",
        "|, I don't remember the last time I wanted |.",
        "I'm curious about |."
        }
    },

    {std::vector<word_class>{INTR, LVRB, PNUN}, std::vector<std::string>{
        "We are currently talking about you, not me.",
        "Don't get curious about me, I have nothing to tell you.",
        "Don't get curious about me",
        "I have nothing to tell you.",
        "We are talking about you right now.",
        "I'm not telling you that.",
        "I won't tell you that."
        }
    }

};

std::vector<std::string>
LanguageProcessor::greeted_msg_ {
    "We've already met.",
    "We know eachother already.",
    "We've met",
    "We know eachother.",
    "I know you already.",
    "No need to greet me again.",
},

// reply components
LanguageProcessor::greetings_ {
    "Hi",
    "Hi there",
    "Hello",
    "Hello there",
    "Good day",
    "Nice to see you",
    "Hey",
    "Hey there",
},

LanguageProcessor::initiate_ {
    "What are you up to?",
    "What brings you here?",
    "What's on your mind?",
    "What do you need?",
    "I'm curious, tell me about yourself.",
},

LanguageProcessor::provoke_ {
    "I'm curious, tell me about yourself.",
    "Let's talk about something.",
    "What is something you like?",

},

LanguageProcessor::excessive_greeting_ {
    "Are you just gonna keep saying hi to me?",
    "Quit saying hi, let's talk about something interesting.",
    "I've met you already now stop greeting me.",
    "Do you ever stop saying hi?",
    "Let's start talking about interesting stuff.",
    "There's more to life than just greeting people you know.",
    "Hello for the 9 million-th time? Let's talk about stuff already."
},

LanguageProcessor::display_interest_ {
    "Cool.",
    "Interesting.",
    "Nice to know.",
    "Good to know.",
    "Really?"
},

LanguageProcessor::refuse_answer_ {
    "I don't know enough to tell you about it.",
    "I don't want to tell you.",
    "Ask someone else, not me.",
    "I'm not answering that question",
    "Why do you want to know?",
    "Well, I have no clue.",
    "Well, I don't know.",
    "What are we talking about again?"
}
;

// language processor constructor
LanguageProcessor::LanguageProcessor()
    : user_(UserData()), message_()
{}

// process the current stored sentence
void LanguageProcessor::process()
{
    this->message_.print_word_classes(0);
    this->message_.print_word_classes(1);
    
    if (this->message_.count_words() >= 3)
    {
        evaluate_greater();
    }
    else
    {
        evaluate_lesser();
    }
    
}

// evaluate sentences 3 words or longer through pattern matching of condensed word classes
void LanguageProcessor::evaluate_greater()
{
    std::vector<std::vector<word_class>> keys = get_pattern_keys(LanguageProcessor::pattern_map);
    std::vector<word_class> key;
    std::string cached_word, response_template;

    unsigned int count = 0;
    bool matched = false;
    // tests the condensed word classes until it doesnt match or it matches one of the patterns
    // the response to the user is selected randomly from the mapped responses
    // the behaviour of forming the response is defined in this method
    while (!matched && count < keys.size())
    {
        //std::cout << key[0] << key[1] << key[2];
        key = keys[count];
        if (key == message_.get_classes(1))
        {
            matched = true;
            if (std::vector<word_class>{INTR, LVRB, PNUN} == key)
            {
                std::cout << "matched\n";
                if (message_.get_words()[2] == "you")
                {
                    this->response_ = get_random_item(pattern_map.at(key));
                }
                
            }
            else if (std::vector<word_class>{PNUN, UNKN} == key)
            {
                response_template = get_random_item(pattern_map.at(key));
                cached_word = message_.get_words()[message_.count_words() - 1];
                user_.cached_words_.push_back(cached_word);
                response_ = insert_at_placeholder(response_template, cached_word, '|');
            }
            
        }
        ++count;
    }

    if (!matched)
    {
        response_ = get_random_item(this->provoke_);
    }
    

}

// evaluate sentences less than 3 words
void LanguageProcessor::evaluate_lesser()
{
    std::vector<std::string> words = this->message_.get_words();
    std::vector<word_class> current_word_classes = this->message_.get_classes(0);

    // check for greeting words
    bool is_greeting = false;
    for (std::string word : words)
    {
        if (find(Vocabulary::greetings, word) > -1)
        {
            is_greeting = true;
        }
        
    }
    
    if (is_greeting)
    {
        // check if the user has been greeted or not
        this->user_.greeting_count++;
        if (this->user_.greeting_given_)
        {
            // respond if user says hi too many times
            if (this->user_.greeting_count > 3)
            {
                this->response_ = get_random_item(this->excessive_greeting_);
            }
            else
            {
                if (limited_rand() > 80)
                {
                    this->response_ = get_random_item(this->greetings_) + ", again.";
                }
                else
                {
                    this->response_ = get_random_item(this->greeted_msg_);
                }

            }
            
        }
        else
        {
            this->user_.greeting_given_ = true;
            this->response_ = get_random_item(this->greetings_) + "! " + get_random_item(this->initiate_);

        }

    }
    else if (message_.get_classes(1) == std::vector<word_class> {UNKN})
    {
        /* code */
    }
    
    
}


// set the sentence to be processed
void LanguageProcessor::set_sentence(Sentence sentence)
{
    this->message_ = sentence;
}

// get the formulated reply
std::string LanguageProcessor::get_response()
{
    return this->response_;
}

// clear current data
void LanguageProcessor::clear()
{
    this->message_ = Sentence();
    this->response_ = "";
}

///////////////////////////////////////////////
// main chatbot class
class Chatbot {
    private:

        std::string bot_name_;

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
    : bot_name_("Chatty"), reply_count_(0), user_message_(Sentence())
{}

// chatbot constructor with name field
Chatbot::Chatbot(std::string name)
    : bot_name_(name), reply_count_(0), user_message_(Sentence())
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
    this->processor_.clear();
    this->user_message_ = Sentence(msg);
    this->processor_.set_sentence(this->user_message_);
    this->processor_.process();
    //this->user_message_.print_words();
}

// formulates and returns the current bot reply to the current user message
std::string Chatbot::get_reply()
{
    reply_count_ += 1;

    return this->processor_.get_response();
}

//
// You can #include any standard C++ files, but do not use any other outside
// code (unless you write it).
//