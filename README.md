## A Chatbot Class

In this assignment your task is to create a
[chatbot](https://en.wikipedia.org/wiki/Chatbot) that can, if possible, pass
[the Turing Test](https://en.wikipedia.org/wiki/Turing_test).

Implement your chatbot in a class called `Chatbot` in the file
[chatbot.h](chatbot.h). Test it using the code in
[chatbot_driver.cpp](chatbot_driver.cpp). **Important**: your code *must* work
with [chatbot_driver.cpp](chatbot_driver.cpp)! Implement, at least, all the
methods and constructors it requires. You can test your `Chatbot` class with
other code if you like, but it still must work with the unmodified
[chatbot_driver.cpp](chatbot_driver.cpp).

This is an open-ended assignment: your goal is to make your chatbot as
interesting and as intelligent as possible. It's fine if you want to restrict
your chatbot to a particular topic, e.g. it could just chat about hockey, or
Harry Potter, or geography, etc. You could try to make it useful, e.g. the
chatbot could help you learn C++ --- maybe it could even write programs for
you!

The markers will look for the following when marking:

- **Keyword-style functionality**: Search the user input for particular
  keywords, and do something different for each keyword.

- **[Eliza][Eliza]-style functionality**: This follows the style of the famous
  [Eliza chatbot][Eliza]. This includes keyword-style functionality.

- **Beyond [Eliza][Eliza]-style functionality**: Something original, creative,
  or interesting that clearly and non-trivially goes beyond an
  [Eliza][Eliza]-style chatbot. Do some research: there is no shortage of idea
  for chatbots to be found on the web!

- **Trivial or very low-effort**: Chatbots that clearly have little effort put
  into them will get low (i.e. failing) marks.

You can `#include` any files you need from the standard C++ library, but
*don't* use any code outside the C++ library (unless you write it yourself).
Make sure to cite any source of ideas that inspired your chatbot.

**Source code readability matters!** We want to see perfect indentation and
use of whitespace, sensibly chosen names, good use of appropriate C++
features, and so on. Please follow coding style used in the notes and
lectures.

Finally, in the file [chatbot_description.txt](chatbot_description.txt), give
an English description (e.g. 1 or 2 paragraphs) of how your chatbot works and
what its main features are. Spelling, grammar, and formatting matter!
**Important**: Include example transcripts of your chatbot showing the kinds
of things it can do.


### What to Submit

Put all your C++ code into the file [chatbot.h](chatbot.h). When you are
ready, compress [chatbot.h](chatbot.h) and
[chatbot_description.txt](chatbot_description.txt) into a zip archive named
`chatbot.zip`. Do *not* put any other files or folders in this zip archive!

Submit `chatbot.zip` on Canvas when it's ready.

The marker will run your chatbot with
[chatbot_driver.cpp](chatbot_driver.cpp), so make sure it works!

Note that if your program does not compile, you will get 0 for the entire
assignment.


### Frequently Asked Questions

- **What is an [Eliza][Eliza]-style chatbot?**

  [Eliza][Eliza]-style chatbot asks the user questions based on their input.
  It looks for text patterns, such as "I like X", and responds with a matching
  pattern, such as "Why do you like X?". For example, if the user enters "I
  like to dream of sheep", the response would be "Why do you like to dream of
  sheep?"

  You should look for a number of different such patterns, the more the
  better. Here are a couple of other ideas for patterns and replies:

  - Given "I am X", reply with "How long have you been X?"

  - Given "You are X", reply with "Why do you think I am X?"

  - Given "I saw X in a dream", reply with "How does X make you feel?"

  The idea is to reply to the patterns in a way that encourages the human to
  give more details, to have them carry the conversation.

  You should add at least one of your own templates.

- **How can I go beyond an [Eliza][Eliza]-style chatbot?**

  It's not hard to see the limitations of [Eliza][Eliza]. For example, Eliza
  has no memory of anything you see. So one thing you might try is to remember
  some words, and then use them in later replies.

  Another problem with [Eliza][Eliza] is that it doesn't answer any useful
  questions. You could try adding templates designed to answer practical
  questions.

  There are many other features you could add. Do some web research to get
  ideas!

- **Do I have to use features not mentioned in this assignment, such as
  dynamic memory or inheritance?**

  No. You *can* use whatever C++ features you like, as long as you both
  understand them, and they make sense to use in this program.

[Eliza]: https://en.wikipedia.org/wiki/ELIZA
