/*

You have a function rand5() that generates a random integer from 1 to 5. 
Use it to write a function rand7() that generates a random integer from 1 to 7.

*/



  int rand7()
{
    while (true) {
        // do our die rolls
        int roll1 = rand5();
        int roll2 = rand5();

        int outcomeNumber = (roll1 - 1) * 5 + (roll2 - 1) + 1;

        // if we hit an extraneous
        // outcome we just re-roll
        if (outcomeNumber > 21) {
            continue;
        }

        // our outcome was fine. return it!
        return outcomeNumber % 7 + 1;
    }
}