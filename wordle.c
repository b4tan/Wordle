
#include "wordle.h"
#include "utils.h"

/**
 * Play the wordle game.
 *
 * key          The answer word. Should be lowercase only.
 * nattempts    The total number of attempts allowed.
 * attempts     An array of string buffers to keep track of each attempt.
 * return       Number of guesses the player took to guess the right word,
 *              return 0 if player failed to guess the word.
 */
int wordle(const char *key, int nattempts, char attempts[][WORDBUFSZ])
{
    /*
     * TODO:
     * Implement this function. Feel free to create any
     * helper functions you need. But do NOT change the
     * parameters of this function.
     */
     // initialize template for question
     int attempt_num = 1;
     char template[WORDLEN] = {'_', '_', '_', '_', '_'};
     //  printf("%s\r", template);
     // for the 6 guesses...
     for(int i = 0;i < nattempts; i++) { 
          printf("%s\r", template);
         // get input
         get_input(attempts[i], WORDLEN);
         // if the word is truly correct then
         if (strcmp(attempts[i], key) == 0) {
            return attempt_num;
         } else {
         // traverse through the columns
            for(int k = 0; k < WORDBUFSZ; k ++) {
                    // traverse through the keygen
                for (int count = 0; count < WORDLEN; count++) {
                    // if element in input matches with element in keygen
                    if (attempts[i][k] == key[count]) {
                        template[count] = attempts[i][k];
                    }
                }
            }
         }
        //  printf("%s\r", template);
         attempt_num++;
     }
     return 0;
}
