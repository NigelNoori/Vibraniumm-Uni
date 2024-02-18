#include <iostream>
#include <string>

using namespace std;

enum commandType {ADD, DELETE, UPDATE, SEARCH, LIST, EXIT};

/**
* Adds a word to the dictionary. If the word is already in the dictionary
* it is not added.
* Parameters:
*   dictionary - a dynamic array of words in the order they were entered
*   wordcount - the number of words in the dictionary
*   aWord - the word to be added to the dictionary
* Return: a pointer to the updated dictionary
*/
string *myAdd(string *dictionary, int &wordCount, string aWord);

/**
* Deletes a word from the dictionary. If the word is not in the dictionary
* it is not deleted.
* Parameters:
*   dictionary - a dynamic array of words in the order they were entered
*   wordcount - the number of words in the dictionary
*   aWord - the word to be deleted from the dictionary
* Return: a pointer to the updated dictionary
*/
string *myDelete(string *dictionary, int &wordCount, string aWord);

/**
* Uses linear search to find a word in the dictionary. If the word does not exist in the
* dictionary, “aWord is not found.” is output. Otherwise, “aWord is found.” and
* the number of comparisons is output.
* Parameters:
*   dictionary - an array of words
*   wordCount - the number of words in the array
*   aWord - the word to be found
*/
void mySearch(string dictionary[], int wordCount, string aWord);

/***
* Uses linear searches to find oldWord and newWord in the dictionary. If the
* oldWord does not exist in the dictionary or the newWord already exists in
* the dictionary a message is output. Otherwise, oldword is overwritten by
* newWord and a message is output.
* Parameters:
*   dictionary - an array of words
*   wordCount - the number of words in the array
*   oldWord - the word to be replaced
*   newWord - the replacement word
*/
void myUpdate(string dictionary[], int wordCount, string oldWord,
              string newWord);

/**
* List all the entries in the dictionary, one per line.
* Parameters:
*   dictionary - an array of words
*   wordCount - the number of words in the array
*/
void myList(string dictionary[], int wordCount);

/**
* Output message and exit to the terminal’s prompt.
*/
void myExit();

/**
* This function returns true if aWord is found in dictionary of wordCount words, and false,
* otherwise. The count parameter should return the number of comparisons made to array elements.
* Parameters:
*   dictionary - an array of words
*   wordCount - the number of words in the array
*   aWord - the word to be found
*   count - the number of comparisons made
* Return: true if aWord is found, false otherwise
*/
bool linearSearch(const string dictionary[], int wordCount, string aWord,
                  int &count);

/**
* Convert a string command to a commandType.
* Parameter: command a string containing a command
* Return: a commandType that corresponds to the given string
*/
commandType stringToCommandType(string command);

int main() {
  string *dictionary = nullptr;
  int wordCount = 0,
      addCount = 0,
      deleteCount = 0,
      updateCount = 0,
      searchCount = 0,
      listCount = 0;
  string command = "",
         aWord = "",
         newWord = "";

  while (true) {
    cout << ">>> ";
    cin >> command;

    switch (stringToCommandType(command)) {
    case ADD:
      cin >> aWord;
      dictionary = myAdd(dictionary, wordCount, aWord);
      addCount++;
      break;
    case DELETE:
      cin >> aWord;
      dictionary = myDelete(dictionary, wordCount, aWord);
      deleteCount++;
      break;
    case UPDATE:
      cin >> aWord >> newWord;
      myUpdate(dictionary, wordCount, aWord, newWord);
      updateCount++;
      break;
    case SEARCH:
      cin >> aWord;
      mySearch(dictionary, wordCount, aWord);
      searchCount++;
      break;
    case LIST:
      myList(dictionary, wordCount);
      listCount++;
      break;
    case EXIT:
    default:
      if (dictionary != nullptr)
        delete[] dictionary;
      cout << "ADD(" << addCount << "), "
           << "DELETE(" << deleteCount << "), "
           << "UPDATE(" << updateCount << "), "
           << "SEARCH(" << searchCount << "), "
           << "LIST(" << listCount << ")\n";
      myExit();
    }
  }

  return 0;
}

string *myAdd(string *dictionary, int &wordCount, string aWord) {
  int comparisonCount = 0;

  if (linearSearch(dictionary, wordCount, aWord, comparisonCount)) {
    cout << aWord << " is already added." << endl;
    return dictionary;
  }

  string *plusOneDictionary = new string[wordCount + 1];
  for (int i = 0; i < wordCount; ++i) {
    plusOneDictionary[i] = dictionary[i];
  }
  plusOneDictionary[wordCount] = aWord;
  wordCount++;

  if (dictionary != nullptr)
    delete[] dictionary;

  cout << aWord << " is added." << endl;

  return plusOneDictionary;
}

string *myDelete(string *dictionary, int &wordCount, string aWord) {
  int comparisonCount = 0;

  if (!linearSearch(dictionary, wordCount, aWord, comparisonCount)) {
    cout << aWord << " is not found." << endl;
    return dictionary;
  }

  if (wordCount == 1) {
    wordCount--;
    delete[] dictionary;
    dictionary = nullptr;
    return dictionary;
  }

  string *lessOneDictionary = new string[wordCount - 1];
  for (int i = 0; i < comparisonCount - 1; ++i) {
    lessOneDictionary[i] = dictionary[i];
  }
  for (int i = comparisonCount; i < wordCount; ++i) {
    lessOneDictionary[i - 1] = dictionary[i];
  }

  wordCount--;

  if (dictionary != nullptr)
    delete[] dictionary;

  cout << aWord << " is deleted." << endl;

  return lessOneDictionary;
}

void mySearch(string dictionary[], int wordCount, string aWord) {
  int comparisonCount = 0;

  if (linearSearch(dictionary, wordCount, aWord, comparisonCount)) {
    cout << aWord << " is found. " << comparisonCount;
    if (comparisonCount == 1)
      cout << " comparison was";
    else
      cout << " comparisons were";
    cout << " made." << endl;
  } else {
    cout << aWord << " is not found." << endl;
  }
}

void myUpdate(string dictionary[], int wordCount, string oldWord,
              string newWord) {
  int comparisonCount = 0;


  if (linearSearch(dictionary, wordCount, newWord, comparisonCount)) {
    cout << newWord << " is already in the dictionary." << endl;
    return;
  }

  if (!linearSearch(dictionary, wordCount, oldWord, comparisonCount)) {
    cout << oldWord << " is not found." << endl;
    return;
  }

  dictionary[comparisonCount - 1] = newWord;
  cout << oldWord << " is replaced by " << newWord << '.' << endl;
}

void myList(string dictionary[], int wordCount) {
  if (wordCount == 0) {
    cout << "There are 0 words in the dictionary." << endl;
    return;
  }

  for (int i = 0; i < wordCount; ++i) {
    cout << dictionary[i] << endl;
  }

  cout << "There ";
  if (wordCount == 1)
    cout << "is 1 word ";
  else
    cout << "are " << wordCount << " words ";
  cout << "in the dictionary." << endl;
}

void myExit() {
  cout << "bye bye" << endl;
  exit(0);
}

bool linearSearch(const string dictionary[], int wordCount, string aWord,
                  int &count) {
  if (wordCount == 0) {
    count = 0;
    return false;
  }

  for (count = 0; count < wordCount; ++count) {
    if (dictionary[count] == aWord) {
      count++;
      return true;
    }
  }

  return false;
}

commandType stringToCommandType(string command) {
  if (command == "ADD")
    return ADD;
  if (command == "DELETE")
    return DELETE;
  if (command == "UPDATE")
    return UPDATE;
  if (command == "SEARCH")
    return SEARCH;
  if (command == "LIST")
    return LIST;
  return EXIT;
}

