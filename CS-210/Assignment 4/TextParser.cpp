#include "WordData.h"
#include "HashWordDictionary.h"
#include<iostream>
#include<fstream>
#include<vector>

/*
    TextParser - used to parse text, and obtain data involving it.
    Partially written by Daniel Page

    COMPLETED
    NAME: Maksim Sharoika
    SID: 200446763


*/

class TextParser{
    private:
        HashWordDictionary* words;//a hash table for the words of the English dictionary
        HashWordDictionary* textWords;//a hash table for the words of the text file read





        /* COMPLETED - By Maksim Sharoika */
        /* partition Used for QS */
       // function to help location the pivot during the quick sort algorithm 
       int partition(std::vector<WordData*>& wordVector, int start, int end){
         // set x to the value currently at the end of the vector (frequency)
         int x = wordVector[end]->getValue();
         // set i to before the begining of the vector 
         int i = start-1;
         // create a temporary pointer to hold data while I conduct swaps 
         WordData* temp;
         // from the begining of the vector until the end of it
         for (int j = start; j < end; j++)
           {
             // if a value of a vector is greater then the current pivot (end of the vector)
             if (wordVector[j]->getValue() >= x)
             {
               // this swaps the i and j if the jth item is bigger than or equal to x
               // increment i to the next position
               i++;
               // conduct a swap using a temporary pointer temp and the two vector pointers
               temp = wordVector[i];
               // pointer in the vector
               wordVector[i] = wordVector[j];
               // pointer in the vector
               wordVector[j] = temp;
             }
           }
         // once we have gone through the vector we swap the position to the right 
         // of i with the end amd then return i+1 as the pivot value and make sure the pivot
         // is in the correct returned poisition
         temp = wordVector[i+1];
         // pointer in the vector
         wordVector[i+1] = wordVector[end];
         wordVector[end] = temp; 
         // pointer in the vector
         return i + 1; 
         // return i + 1 (one position to the right)
       }





        /*
            Quick Sort
            Input: An array of WordData object, integers that are start and end positions of subarray
            Output: Sorts wordArray[start...end] from largest to smallest frequencies. 
        */
        void QS(std::vector<WordData*>& wordVector, int start, int end){

            //you are responsible for implementing partition.  See how simple this is!!!
            if(start < end){
              int pos = partition(wordVector,start,end);
              QS(wordVector,start,pos-1);
              QS(wordVector,pos+1,end);
            }
        }

        /*
            Quick Sort driver function    
            Sorts WordData objects from largest to smallest frequencies. 
        */
        void quickSort(std::vector<WordData*>& wordVector,int n){
            QS(wordVector,0,n-1);//begins Quick Sort
        }

    public:
        /*
            Constructor
        */
        TextParser(std::string wordFile, std::string textFile){



          
          
        /* COMPLETED - By Maksim Sharoika */
           words = new HashWordDictionary(77509);
          // 77069 = 0.753987
          // 77279 = 0.751938
          // 77509 = 0.749706
          // 77573 = 0.749088
          


          
            textWords = new HashWordDictionary(20047);//we just picked this value, we are not going to be concerned about this!

            std::ifstream fileWords;//for reading the file with words
            std::ifstream fileTexts;//for reading the file with the text
            fileWords.open(wordFile);
            std::string input;//read line.
            int duplicateRecords = 0;
            while(std::getline(fileWords,input)){
                    
                WordData* newWord = new WordData(input);
                try{
                    words->put(newWord);
                }
                catch(DuplicateKeyException){
                    duplicateRecords++;
                }
            }
            if(duplicateRecords>0){//report to the user the number of duplicates.
                std::cout<<"Warning: Upon recording "<<wordFile<<"... there were " << duplicateRecords<<" records encountered."<<std::endl;
            }
            fileWords.close();
            //next, we read in words from the text file!
            fileTexts.open(textFile);
            std::string inputText;
            //fileTexts>>inputText; 
            while(!(fileTexts>>std::ws).eof()){//read the file until we have nothing left
                    fileTexts>>inputText;
                    for(int i = 0; i < inputText.size(); i++) {//make the input letters all uppercase
                        inputText.at(i) = toupper(inputText.at(i));
                    }
                    std::string longest = findLongestWord(inputText);
                    try{
                        if(longest.size()>0){//don't put empty strings in
                                textWords->put(new WordData(longest));
                        }
                    }
                    catch(DuplicateKeyException){
                        //do nothing
                    }
            }
            fileTexts.close();
            
        }

        //deconstructor, you do not need to do anything here.
        ~TextParser(){
            delete words;
            delete textWords;
        }





        /* COMPLETED - By Maksim Sharoika */
        /*
            Find the longest string that provided is in the word dictionary, return it!
        */
        std::string findLongestWord(std::string word){
          // create a empty string to store the longest string 
          // in the text file we are looking at
          std::string longest = "";
          // start at the first character and increment to the right 
          for (int i = 0; i < word.length(); i++) 
          {
            // for each of the outer loops start at the letter to the right of the start 
            // and increment all possibilities of length to the right
            for (int j = i+1; j <= word.length(); j++) 
            {
              // look for the substring in the alphabet dictionary table
              if (words->get(word.substr(i,j)) != nullptr)
              {
                // if it is there (not a nullptr returned)
                if (word.substr(i,j).length() > longest.length())
                {
                  // if it is longer then the current longest word replace it as the longest
                  longest = word.substr(i,j);
                }
              }
            }
          }
          // return the longest word or the nullptr depending on circumstances
          return longest;
        }






        //Return a sorted array (vector), sorted most frequent word to least.
        std::vector<WordData*> sortedTextWords(){
            //obtain all the records
            std::vector<WordData*> wordVector = textWords->listRecords();
            //sort the vector (do not modify this code)
            quickSort(wordVector,textWords->size());

            return wordVector;

        }




        /* COMPLETED - By Maksim Sharoika */
        //Return the word count of the text file (total count of words)
        int wordCount(){
            //obtain all the records and set the starting word count to 0 just incase
            int numWords = 0;
            std::vector<WordData*> wordVector = textWords->listRecords();
            // Use the vector count up how many words there are
            // (by counting the frequencies of words)
            // go through the vector of WordData and for each object 
            // access its frequency and tally it all up
            for (int i = 0; i < wordVector.size(); i++)
            {
              // add the current frequency to the total of frequencies
              numWords = numWords + (wordVector[i]->getValue());
            } 
            // return the totaled value 
            return numWords;
        }





		//compute load factor
        double computeLoadFactor(){
            return ((double)words->size())/((double)words->M());
        }

};
