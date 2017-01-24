/* 

Check if a given deck is only shuffled

*/


 
bool isSingleRiffle(
    const vector<int>& half1,
    const vector<int>& half2,
    const vector<int>& shuffledDeck)
{
    size_t half1Index = 0;
    size_t half2Index = 0;
    size_t half1MaxIndex = half1.size() - 1;
    size_t half2MaxIndex = half2.size() - 1;

    for (int card : shuffledDeck) {
        // if we still have cards in half1
        // and the "top" card in half1 is the same
        // as the top card in shuffledDeck
        if (half1Index <= half1MaxIndex && card == half1[half1Index]) {
            ++half1Index;
        }
        else if (half2Index <= half2MaxIndex && card == half2[half2Index]) {
            // if we still have cards in half2
            // and the "top" card in half2 is the same
            // as the top card in shuffledDeck
            ++half2Index;
        }
        else {
            // if the top card in shuffledDeck doesn't match the top
            // card in half1 or half2, this isn't a single riffle.
            return false;
        }
    }

    // all cards in shuffledDeck have been "accounted for"
    // so this is a single riffle!
    return true;
}