## A Chatbot Class

In this assignment your task is to create a
[chatbot](https://en.wikipedia.org/wiki/Chatbot) that can, if possible, pass
[the Turing Test](https://en.wikipedia.org/wiki/Turing_test).

Implement your chatbot in a class called `Chatbot` that you put in the file
[chatbot.h](chatbot.h). Test it using the code in
[chatbot_driver.cpp](chatbot_driver.cpp).

This is an open-ended assignment: your goal is to make your chatbot as
interesting and as intelligent as possible. Here is the basic styles of
chatbot the markers will be looking for:

- **Trivial or very low-effort**: Chatbots that clearly have little effort put
  into them will get low (i.e. failing) marks.

- **Keyword-style functionality**: Search the user input for particular
  keywords, and do something different for each keyword.

- **[Eliza](https://en.wikipedia.org/wiki/ELIZA)-style functionality**: This
  follows the style of the famous [Eliza
  chatbot](https://en.wikipedia.org/wiki/ELIZA). This includes keyword-style
  functionality.

- **Beyond [Eliza](https://en.wikipedia.org/wiki/ELIZA)-style functionality**:
  Something original, creative, or interesting that clearly and non-trivially
  goes beyond an [Eliza](https://en.wikipedia.org/wiki/ELIZA)-style chatbot.
  Do some research: there is no shortage of idea for chatbots to be found on
  the web!

You can `#include` any files you need from the standard C++ library, but
*don't* use any code outside the C++ library (unless you write it yourself).
Make sure to cite any source of ideas that inspired your chatbot.

**Source code readability matters!** We want to see perfect indentation and
use of whitespace, sensibly chosen names, good use of appropriate C++
features, and so on. Please follow coding style used in the notes and
lectures.

Finally, in the file [chatbot_description.txt](chatbot_description.txt), give
a brief English description (e.g. 1 or 2 paragraphs) of how your chatbot works
and what is interesting about it. Spelling, grammar, and formatting matter!


### What to Submit

Put all your C++ code into the file [chatbot.h](chatbot.h). When you are
ready, compress [chatbot.h](chatbot.h) and
[chatbot_description.txt](chatbot_description.txt) into a zip archive named
`chatbot.zip`. Do *not* put any other files or folders in this zip archive!

Submit `chatbot.zip` on Canvas when it's ready.

The marker will run your chatbot with
[chatbot_driver.cpp](chatbot_driver.cpp), so make sure it works!
